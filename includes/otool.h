# ifndef OTOOL_H
# define OTOOL_H

# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/fat.h>

# include "libft.h"

# define MACHO32_TYPE "MH32"
# define MACHO64_TYPE "MH64"
# define FAT32_TYPE "FAT32"
# define FAT64_TYPE "FAT64"
# define UNKNOWN_TYPE "UNKNW"

# define B_ENDIAN 0
# define L_ENDIAN 1
# define UNK_ENDIAN

// TMP
# include <stdio.h>
// TMP

# define PROT PROT_READ | PROT_WRITE
# define FLAGS MAP_PRIVATE | MAP_FILE

typedef struct s_otool
{
        void    *ptr;
        size_t  size;
        int     fd;
        char    type[5];
        int     endian;
}               t_otool;

void            arch_64_macho(void *ptr);
void            arch_32_macho(void *ptr);

void            *get_image(t_otool *file, char *av);

void            DumpHex(const void *data, size_t size);

void            save_filetype(t_otool *file, void *ptr);

int16_t         swap_int16(int16_t val);
uint16_t        swap_uint16(uint16_t val);

int32_t         swap_int32(int32_t val);
uint32_t        swap_uint32(uint32_t val);

int64_t         swap_int64(int64_t val);
uint64_t        swap_uint64(uint64_t val);

void            swap_mach_header(struct mach_header *mh);
void            swap_mach_header_64(struct mach_header_64 *mh);

void            swap_load_command(struct load_command *lc);

void            swap_segment_command(struct segment_command *sg);
void            swap_segment_command_64(struct segment_command_64* sg);

void            swap_section(struct section *s, uint32_t nsects);
void            swap_section_64(struct section_64 *s, uint32_t nsects);

# endif