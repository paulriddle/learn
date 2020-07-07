#include <stddef.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;
typedef __int128 int128_t;

void store_prod(int128_t *dest, int64_t x, int64_t y)
{
    *dest = x * (int128_t)y;
}

void show_bytes(byte *start, size_t len)
{
    for(size_t i = 0; i < len; i++)
    {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int128_t(int128_t x)
{
    show_bytes((byte *)&x, sizeof(int128_t));
}

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        exit(1);
    }

    int128_t dest = 0;
    int64_t x = strtoll(argv[1], 0, 10);
    int64_t y = strtoll(argv[2], 0, 10);

    store_prod(&dest, x, y);

    show_int128_t(dest);
}
