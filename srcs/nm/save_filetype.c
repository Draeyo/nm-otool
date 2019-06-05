#include "nm.h"

static void     fill_filetype(t_nm *file, char *type, int endian)
{
    ft_strcpy(file->type, type);
    file->endian = endian;
}

void    save_filetype(t_nm *file, void *ptr)
{
    uint32_t    type;

    type = *(uint32_t*)ptr;
    if (type == MH_CIGAM)
        fill_filetype(file, MACHO32_TYPE, L_ENDIAN);
    else if (type == MH_MAGIC)
        fill_filetype(file, MACHO32_TYPE, B_ENDIAN);
    else if (type == MH_CIGAM_64)
        fill_filetype(file, MACHO64_TYPE, L_ENDIAN);
    else if (type == MH_MAGIC_64)
        fill_filetype(file, MACHO64_TYPE, B_ENDIAN);
    else if (type == FAT_MAGIC)
        fill_filetype(file, FAT32_TYPE, B_ENDIAN);
    else if (type == FAT_CIGAM)
        fill_filetype(file, FAT32_TYPE, L_ENDIAN);
    else if (type == FAT_MAGIC_64)
        fill_filetype(file, FAT64_TYPE, B_ENDIAN);
    else if (type == FAT_CIGAM_64)
        fill_filetype(file, FAT64_TYPE, L_ENDIAN);
    else
        fill_filetype(file, UNKNOWN_TYPE, UNK_ENDIAN);
}