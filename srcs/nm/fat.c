#include "nm.h"

void    arch_32_fat(void *ptr, t_nm *file)
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
        // if (fat->cputype == CPU_TYPE_X86_64)
        ft_putendl(((NXArchInfo*)NXGetArchInfoFromCpuType(fat->cputype, fat->cpusubtype))->description);
        read_file_nm(ptr + fat->offset, file);
        fat = (void*)fat + sizeof(struct fat_arch);
        if (magic == FAT_CIGAM)
            swap_fat_arch(fat);
        i++;
        while (file->res_start)
        {
            free(file->res_start->content);
            free(file->res_start);
            file->res_start = file->res_start->next;
        }
        while (file->sect_start)
        {
            free(file->sect_start);
            file->sect_start = file->sect_start->next;
        }
    }
}

void    arch_64_fat(void *ptr, t_nm *file)
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
        // if (fat->cputype == CPU_TYPE_X86_64)
        ft_putendl(((NXArchInfo*)NXGetArchInfoFromCpuType(fat->cputype & CPU_ARCH_MASK, fat->cpusubtype))->description);
        read_file_nm(ptr + fat->offset, file);
        fat = (void*)fat + sizeof(struct fat_arch_64);
        if (magic == FAT_CIGAM_64)
            swap_fat_arch_64(fat);
        i++;
        while (file->res_start)
        {
            free(file->res_start->content);
            free(file->res_start);
            file->res_start = file->res_start->next;
        }
        while (file->sect_start)
        {
            free(file->sect_start);
            file->sect_start = file->sect_start->next;
        }
    }
}