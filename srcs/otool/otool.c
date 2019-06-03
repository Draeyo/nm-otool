#include "otool.h"

void    read_file(void *ptr, t_otool *file)
{
    uint32_t    magic;

    magic = *(uint32_t*)ptr;
    if (magic == MH_MAGIC || magic == MH_CIGAM)
        arch_32_macho(ptr);
    else if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
        arch_64_macho(ptr);
    else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
        arch_32_fat(ptr, file);
    else if (magic == FAT_MAGIC_64 || magic == FAT_CIGAM_64)
        arch_64_fat(ptr, file);
    else
        printf("unknown architecture\n");
}

void    ft_otool(char *arg, t_otool *file)
{
    void        *ptr;

    ft_putstr(arg);
    ft_putstr(":\n");
    if (!(ptr = get_image(file, arg)))
        ft_putendl_fd("ERROR", 2);
    else
        file->ptr = ptr;
    // magic = *(uint32_t*)ptr;
    read_file(ptr, file);
    munmap(ptr, file->size);
}

int main(int ac, char **av)
{
    t_otool *file;
    // void *ptr;
    int i;

    if (ac < 2)
        return (0);
    file = malloc(sizeof(t_otool));
    i = 0;
    while (av[++i])
        ft_otool(av[i], file);
    free(file);
    return (0);
}