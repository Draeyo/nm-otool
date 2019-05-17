#include "otool.h"

void    arch_32_fat(void *ptr, t_otool *file)
{
    uint32_t        i;
    struct fat_arch *fat;
    uint32_t        magic;

    i = 0;
    magic = *(uint32_t*)ptr;
    if (magic == FAT_CIGAM)
        swap_fat_header(ptr);
    fat = (void*)ptr + sizeof(struct fat_header);
    // printf("%u\n", ((struct fat_header*)ptr)->nfat_arch);
    while (i < ((struct fat_header*)ptr)->nfat_arch)
    {
        read_file(ptr + swap_uint32(fat->offset), file);
        fat = (void*)fat + sizeof(struct fat_arch);
        i++;
    }
}

void    arch_64_fat(void *ptr, t_otool *file)
{
    uint32_t            i;
    uint32_t            magic;
    struct fat_arch_64 *fat;

    i = 0;
    magic = *(uint32_t*)ptr;
    if (magic == FAT_CIGAM_64)
        swap_fat_header(ptr);
    fat = (void*)ptr + sizeof(struct fat_header);
    // printf("%u\n", ((struct fat_header*)ptr)->nfat_arch);
    while (i < ((struct fat_header*)ptr)->nfat_arch)
    {
        read_file(ptr + fat->offset, file);
        fat = (void*)fat + sizeof(struct fat_arch_64);
        i++;
    }
}