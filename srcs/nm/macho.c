#include "nm.h"

static void     print_symtype(uint8_t type)
{
    // external uppercase, internal lowercase
    // apply mask to check type (check masks in nlist and stab)
    ft_putchar(' ');
    if (type | N_UNDF)
        ft_putchar('U');
    else if (type | N_ABS)
        ft_putchar('A');
    else
        ft_putchar('X');
    ft_putchar(' ');
}

static int      hex_padding16(unsigned long nb)
{
    int     i;

    i = 16;
    while (nb > 0 && i > 0)
    {
        nb /= 16;
        i--;
    }
    return (i);
}

static void     print_hex(unsigned long nb)
{
    const char *tmp = "0123456789abcdef";

    if (nb >= 16)
    {
        print_hex(nb / 16);
        print_hex(nb % 16);
    }
    else
        ft_putchar(tmp[nb]);
}

static void scroll_section_64_macho(void *ptr, struct symtab_command *segment, int endian)
{
    struct nlist_64 *nlist;
    uint32_t i;
    void *strtable;
    int     padding;

    nlist = (void *)ptr + segment->symoff;
    strtable = (void *)ptr + segment->stroff;
    i = 0;
    (void)endian;
    while (i < segment->nsyms)
    {
        padding = hex_padding16(nlist->n_value);
        if (padding < 16)
            while (padding--)
                ft_putchar('0');
        else
            while (padding--)
                ft_putchar(' ');
        if (nlist->n_value)
            print_hex(nlist->n_value);
        print_symtype(nlist->n_type);
        // ft_putstr(" X ");
        ft_putendl(strtable + nlist->n_un.n_strx);
        nlist = (void *)nlist + sizeof(struct nlist_64);
        i++;
    }
}

static void scroll_section_32_macho(void *ptr, struct symtab_command *segment, int endian)
{
    struct nlist *nlist;
    uint32_t i;
    void *strtable;
    int     padding;

    nlist = (void *)ptr + segment->symoff;
    strtable = (void *)ptr + segment->stroff;
    i = 0;
    (void)endian;
    while (i < segment->nsyms)
    {
        padding = hex_padding16(nlist->n_value);
        if (padding < 16)
            while (padding--)
                ft_putchar('0');
        else
            while (padding--)
                ft_putchar(' ');
        if (nlist->n_value)
            print_hex(nlist->n_value);
        print_hex(nlist->n_value);
        print_symtype(nlist->n_type);
        // ft_putstr(" X ");
        ft_putendl(strtable + nlist->n_un.n_strx);
        nlist = (void *)nlist + sizeof(struct nlist);
        i++;
    }
}

void arch_64_macho(void *ptr)
{
    void *header;
    void *load;
    void *segment;
    int i;
    int endian;

    endian = (*(uint32_t *)ptr) == MH_CIGAM_64 ? L_ENDIAN : B_ENDIAN;
    header = (struct mach_header_64 *)ptr;
    if (endian == L_ENDIAN)
        swap_mach_header_64(header);
    i = ((struct mach_header_64 *)header)->ncmds;
    load = ptr + sizeof(struct mach_header_64);
    if (endian == L_ENDIAN)
        swap_load_command(load);
    segment = load;
    if (endian == L_ENDIAN)
        swap_segment_command_64(segment);
    while (i > 0)
    {
        if (((struct load_command *)segment)->cmd == LC_SYMTAB)
            scroll_section_64_macho(ptr, segment, endian);
        segment += ((struct load_command *)segment)->cmdsize;
        if (endian == L_ENDIAN)
            swap_segment_command_64(segment);
        i--;
    }
}

void arch_32_macho(void *ptr)
{
    void *header;
    void *load;
    void *segment;
    int i;
    int endian;

    endian = (*(uint32_t *)ptr) == MH_CIGAM ? L_ENDIAN : B_ENDIAN;
    header = (struct mach_header *)ptr;
    if (endian == L_ENDIAN)
        swap_mach_header(header);
    i = ((struct mach_header *)header)->ncmds;
    load = ptr + sizeof(struct mach_header);
    if (endian == L_ENDIAN)
        swap_load_command(load);
    segment = load;
    if (endian == L_ENDIAN)
        swap_segment_command(segment);
    while (i > 0)
    {
        if (((struct load_command *)segment)->cmd == LC_SYMTAB)
            scroll_section_32_macho(ptr, segment, endian);
        segment += ((struct load_command *)segment)->cmdsize;
        if (endian == L_ENDIAN)
            swap_segment_command(segment);
        i--;
    }
}