#include "nm.h"

void read_file_nm(void *ptr, t_nm *file)
{
    uint32_t magic;

    magic = *(uint32_t *)ptr;
    if (magic == MH_MAGIC || magic == MH_CIGAM)
        arch_32_macho(ptr, file);
    else if (magic == MH_MAGIC_64 || magic == MH_CIGAM_64)
        arch_64_macho(ptr, file);
    else if (magic == FAT_MAGIC || magic == FAT_CIGAM)
        arch_32_fat(ptr, file);
    else if (magic == FAT_MAGIC_64 || magic == FAT_CIGAM_64)
        arch_64_fat(ptr, file);
    else
        printf("unknown architecture\n");
}

void ft_nm(char *arg, t_nm *file)
{
    void *ptr;

    if (file->ac > 2)
    {
        ft_putstr(arg);
        ft_putstr(":\n");
    }
    if (!(ptr = get_image(file, arg)))
        ft_putendl_fd("ERROR", 2);
    else
    {
        file->ptr = ptr;
        read_file_nm(ptr, file);
        munmap(ptr, file->size);
    }
}

static void manage_files(char *arg, int ac)
{
    t_nm    *file;

    file = malloc(sizeof(t_nm));
    ft_bzero(file, sizeof(t_nm));
    file->ac = ac;
    ft_nm(arg, file);
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
    free(file);
}

int main(int ac, char **av)
{
    int i;

    if (ac < 2)
        return (0);
    i = 0;
    while (av[++i])
        manage_files(av[i], ac);
    return (0);
}