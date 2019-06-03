#include "otool.h"

void    *get_image(t_otool *file, char *av)
{
    void *ptr;
    struct stat stat;

    file->fd = open(av, O_RDONLY);
    if (fstat(file->fd, &stat))
    {
        ft_putendl_fd("fstat failed\n", 2);
        return (NULL);
    }
    file->size = (size_t)stat.st_size;
    if ((ptr = mmap(0, file->size, PROT, FLAGS, file->fd, 0)) == MAP_FAILED)
    {
        ft_putendl_fd("mmap failed.\n", 2);
        return (NULL);
    }
    save_filetype(file, ptr);
    return (ptr);
}