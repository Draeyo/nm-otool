# ifndef OTOOL_H
# define OTOOL_H

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <mach-o/loader.h>

# include "libft.h"

// TMP
# include <stdio.h>

# define PROT PROT_READ | PROT_WRITE
# define FLAGS MAP_PRIVATE | MAP_FILE

typedef struct s_otool
{
        void    *ptr;
        size_t  size;
        int     fd;
}               t_otool;

void            arch_64_macho(void *ptr);
void            arch_32_macho(void *ptr);

void            *get_image(t_otool *file, char *av);

void            DumpHex(const void *data, size_t size);

# endif