# ifndef OTOOL_H
# define OTOOL_H

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <mach-o/loader.h>

# include "libft.h"

# define PROT PROT_READ | PROT_WRITE
# define FLAGS MAP_PRIVATE | MAP_FILE

# endif