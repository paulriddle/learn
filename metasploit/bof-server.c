#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <winsock.h>
#include <windows.h>

#define BACKLOG 5
#define VERSION_STR "bof-server v0.01"

void    bserv_error(char *s, int n, char *msg)
{
    fprintf(stderr, "%s at line %i: %s, %s\n", s, n, msg, strerror(errno));
    exit(-1);
}

int     getl(int fd, char *s)
{
    int   n;
    int   ret;
    
    s[0] = 0;
    for (n = 0; (ret = recv(fd, s + n, 1, 0)) == 1 && 
         s[n] && s[n] != '\n'; n++)
        ;
    if (ret == -1 || ret == 0)
        return (-1);
    while (n && (s[n] == '\n' || s[n] == '\r' || s[n] == ' '))
    {
        s[n] = 0;
        n--;
    }
    return (n);
}

void    manage_client(int s)
{
    char buffer[512];
    int cont = 1;
    
    while (cont)
    {
        send(s, "\r\n> ", 4, 0);
        if (getl(s, buffer) == -1)
            return ;
        if (!strcmp(buffer, "version"))
            send(s, VERSION_STR, strlen(VERSION_STR), 0);
        if (!strcmp(buffer, "quit"))
            cont = 0;
    }
}

int main(int ArgCount, char **Args)
{
    int Port = atoi(Args[1]);
    int                   s;
    int                   i;
    int                   pid;
    int                   cli_s;
    struct sockaddr_in    sin;
    struct sockaddr_in    cli_sin;
    
    if(ArgCount != 2 || Port > 65555)
    {
        printf("Usage: %s <port>\n", Args[0]);
        exit(-1);
    }
    
    WSADATA SocketData;
    
    if(WSAStartup(MAKEWORD(1, 1), &SocketData) != 0)
    {
        fprintf(stderr, "WSAStartup failed.\n");
        exit(1);
    }
    
    if ((s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
        bserv_error(__FILE__, __LINE__, "socket");
    sin.sin_family = AF_INET;
    sin.sin_port = htons(Port);
    sin.sin_addr.s_addr = INADDR_ANY;
    if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == -1)
        bserv_error(__FILE__, __LINE__, "Can't bind");
    if (listen(s, 42) == -1)
        bserv_error(__FILE__, __LINE__, "Can't listen");
    i = sizeof(cli_sin);
    while ((cli_s = accept(s, (struct sockaddr*)&cli_sin, &i)) != -1)
    {
        printf("[%i] %s connected\n", cli_s, inet_ntoa(cli_sin.sin_addr));
        manage_client(cli_s);
        printf("[%i] %s disconnected\n", cli_s, inet_ntoa(cli_sin.sin_addr));
        closesocket(cli_s);
    }
    perror("accept");
    closesocket(s);
    return 0;
}
