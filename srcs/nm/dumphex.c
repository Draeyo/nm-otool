#include "nm.h"

void    DumpHex(void *ptr, uint32_t offset, size_t size)
{
    uint32_t    i;
    void        *data;

    i = 0;
    data = ptr + offset;
    while (i < (uint32_t)size)
    {
        if (i % 16 == 0)
            printf("%016x\t", i + offset);
        printf("%02x ", ((unsigned char *)data)[i]);
        if ((i + 1) % 16 == 0 || i + 1 == (uint32_t)size)
            printf("\n");
        ++i;
    }
}