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
    if (magic == FAT_CIGAM)
        swap_fat_arch(fat);
    while (i < ((struct fat_header*)ptr)->nfat_arch)
    {
        // check if arch == actual arch
        printf("MyFatCpuType : \t\t%#x\n", fat->cputype);
        printf("getLocalArchInfo : \t%#x | %#x\t -> %s\n", ((NXArchInfo*)NXGetLocalArchInfo())->cputype, ((NXArchInfo*)NXGetLocalArchInfo())->cpusubtype, ((NXArchInfo*)NXGetLocalArchInfo())->description);
        printf("archInfoFromMyFat : \t%#x | %#x\t -> %s\n\n", ((NXArchInfo*)NXGetArchInfoFromCpuType(fat->cputype, fat->cpusubtype))->cputype, ((NXArchInfo*)NXGetArchInfoFromCpuType(fat->cputype, fat->cpusubtype))->cpusubtype, ((NXArchInfo*)NXGetArchInfoFromCpuType(fat->cputype, fat->cpusubtype))->description);
        // printf("cpuTypeFromMyFat : \t%#x\n\n", ((NXArchInfo*)NXGetArchInfoFromCpuType(fat->cputype, fat->cpusubtype))->cputype);
        // printf("%s\n", ((NXArchInfo*)NXGetArchInfoFromCpuType(swap_uint32(fat->cputype), swap_uint32(fat->cpusubtype)))->description);
        if (((NXArchInfo*)NXGetLocalArchInfo())->cputype == fat->cputype)
            read_file(ptr + fat->offset, file);
        fat = (void*)fat + sizeof(struct fat_arch);
        if (magic == FAT_CIGAM)
            swap_fat_arch(fat);
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
    if (magic == FAT_CIGAM_64)
        swap_fat_arch_64(fat);
    while (i < ((struct fat_header*)ptr)->nfat_arch)
    {
        // check if arch == actual arch
        read_file(ptr + fat->offset, file);
        fat = (void*)fat + sizeof(struct fat_arch_64);
        if (magic == FAT_CIGAM_64)
            swap_fat_arch_64(fat);
        i++;
    }
}