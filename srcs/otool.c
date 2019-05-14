#include "otool.h"

int main(int ac, char **av)
{
    t_otool *file;
    void *ptr;
    int i;

    if (ac < 2)
        return (0);
    file = malloc(sizeof(t_otool));
    i = 0;
    while (av[++i])
    {
        ft_putstr(av[i]);
        ft_putstr(":\n");
        if (!(ptr = get_image(file, av[i])))
        {
            ft_putendl_fd("ERROR", 2);
            free(file);
            return (1);
        }
        else
            file->ptr = ptr;
        if (*(uint32_t *)ptr == MH_MAGIC)
            arch_32_macho(ptr);
        else if (*(uint32_t *)ptr == MH_MAGIC_64)
            arch_64_macho(ptr);
        else
            printf("unknown arch\n");
        munmap(ptr, file->size);
    }
    free(file);
    return (0);
}