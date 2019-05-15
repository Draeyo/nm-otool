#include "otool.h"

void    DumpHex(const void *data, size_t size)
{
    size_t  i;

    i = 0;
    while (i < size)
    {
        if (i % 16 == 0)
            printf("%016zx\t", i);
        printf("%02x ", ((unsigned char *)data)[i]);
        if ((i + 1) % 16 == 0 || i + 1 == size)
            printf("\n");
        ++i;
    }
}