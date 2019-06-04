# ifndef NM_H
# define NM_H

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/fat.h>
# include <mach-o/arch.h>
# include <mach-o/nlist.h>
# include <mach-o/stab.h>

# include "libft.h"

# define PROT PROT_READ | PROT_WRITE
# define FLAGS MAP_PRIVATE | MAP_FILE

# define B_ENDIAN 0
# define L_ENDIAN 1
# define UNK_ENDIAN -1

typedef struct  s_nm
{
        void    *ptr;
        size_t  size;
        int     fd;
        int     byte_order;    
}               t_nm;

void            ft_nm(char *arg, t_nm *file);
void            read_file(void *ptr, t_nm *file);

# endif