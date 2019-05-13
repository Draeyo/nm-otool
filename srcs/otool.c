#include "otool.h"

static void             print_hex(int nb)
{
        const char      *tmp = "0123456789abcdef";

        if (nb >= 16)
        {
                print_hex(nb / 16);
                print_hex(nb % 16);
        }
        else
                ft_putchar(tmp[nb]);
}

int     main(int ac, char **av)
{
    int     fd;
    size_t  size;
    void    *ptr;
    struct stat     stat;
    void    *header;
    void    *load;
    void    *segment;
    void    *section;
    

    if (ac < 2)
        return (0);
    fd = open(av[1], O_RDONLY);
    fstat(fd, &stat);
    size = (size_t)stat.st_size;
    ptr = mmap(0, size, PROT, FLAGS, fd, 0);
    printf("%x\n", *(int*)ptr);
    if (*(int*)ptr == MH_MAGIC)
        printf("32bits\n");
    else if (*(int*)ptr == MH_MAGIC_64)
    {
        header = (struct mach_header_64*)ptr;
        printf("64bits\n");
        printf("%d Loads\n", ((struct mach_header_64*)header)->ncmds);
        int i = ((struct mach_header_64*)header)->ncmds;
        load = ptr + sizeof(struct mach_header_64);
        segment = load;
        while (i > 0)
        {
            //printf("load size : %d\n", ((struct load_command*)load)->cmdsize);
            if (((struct segment_command_64*)segment)->cmd & LC_SEGMENT_64)
            {
                write(1, ((struct segment_command_64*)segment)->segname, 16);
                ft_putchar('\n');
                int section_nb = ((struct segment_command_64*)segment)->nsects;
                section = segment + (((struct segment_command_64*)segment)->cmdsize - (sizeof(struct section_64) * ((struct segment_command_64*)segment)->nsects));
                while (section_nb)
                {
                    printf("%s\n", ((struct section_64*)section)->sectname);
                    section += sizeof(struct section_64);
                    section_nb--;
                }
                ft_putchar('\n');
                segment = segment + ((struct segment_command_64*)segment)->cmdsize;
            }
            i--;
        }
    }
    else
        printf("unknown arch\n");
    munmap(ptr, size);
    return (0);
}