 #include<stdio.h>
 #include<stdlib.h>

int main(int argc, char *argv[])
{
  char *buf;
  buf = (char*) malloc(1<<31);
  fgets(buf, 1024, stdin);
  printf("%s\n", buf);

  return 0;
}
