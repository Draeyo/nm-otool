#include "nm.h"

static void get_sections(t_nm *file, struct segment_command *segment, int endian)
{
    uint32_t        i;
    struct section  *sect;
    t_sections      *tmp;

    i = 0;
    sect = (void*)segment + (segment->cmdsize - (sizeof(struct segment_command) * segment->nsects));
    if (endian == L_ENDIAN)
        swap_section(sect, segment->nsects);
    while (i < segment->nsects)
    {
        tmp = malloc(sizeof(t_sections));
        ft_strcpy(tmp->segname, sect->segname);
        ft_strcpy(tmp->sectname, sect->sectname);
        tmp->next = NULL;
        if (!file->sections)
        {
            file->sections = tmp;
            file->sect_start = file->sections;
        }
        else
        {
            file->sections->next = tmp;
            file->sections = file->sections->next;
        }
        sect++;
        i++;
    }
}

static void get_sections_64(t_nm *file, struct segment_command_64 *segment, int endian)
{
    uint32_t            i;
    struct section_64   *sect;
    t_sections          *tmp;

    i = 0;
    sect = (void*)segment + (segment->cmdsize - (sizeof(struct segment_command_64) * segment->nsects));
    if (endian == L_ENDIAN)
        swap_section_64(sect, segment->nsects);
    while (i < segment->nsects)
    {
        tmp = malloc(sizeof(t_sections));
        ft_strcpy(tmp->segname, sect->segname);
        ft_strcpy(tmp->sectname, sect->sectname);
        tmp->next = NULL;
        if (!file->sections)
        {
            file->sections = tmp;
            file->sect_start = file->sections;
        }
        else
        {
            file->sections->next = tmp;
            file->sections = file->sections->next;
        }
        sect++;
        i++;
    }
}

static void print_symtype(uint8_t type)
{
    uint8_t tmp;

    tmp = type & N_TYPE;
    // external uppercase, internal lowercase
    // apply mask to check type (check masks in nlist and stab)
    ft_putchar(' ');
    if (tmp == N_UNDF)
        ft_putchar(type & N_EXT ? 'U' : 'u');
    else if (tmp == N_ABS)
        ft_putchar(type & N_EXT ? 'A' : 'a');
    else if (tmp == N_SECT)
        ft_putchar(type & N_EXT ? 'T' : 't');
    else if (tmp == N_PBUD)
        ft_putchar(type & N_EXT ? 'X' : 'x');
    else if (tmp == N_INDR)
        ft_putchar(type & N_EXT ? 'X' : 'x');
    else
        ft_putchar('?');
    ft_putchar(' ');
}

static int hex_padding16(unsigned long nb)
{
    int i;

    i = 16;
    while (nb > 0 && i > 0)
    {
        nb /= 16;
        i--;
    }
    return (i);
}

static void print_hex(unsigned long nb)
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

static void scroll_section_64_macho(void *ptr, struct symtab_command *segment, int endian, t_nm *file)
{
    struct nlist_64 *nlist;
    uint32_t i;
    void *strtable;
    int padding;

    nlist = (void *)ptr + segment->symoff;
    strtable = (void *)ptr + segment->stroff;
    i = 0;
    (void)endian;
    while (i < segment->nsyms)
    {
        if (!(nlist->n_type & N_STAB))
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
            // marche pas, a voir
            // printf(" %#X ", nlist->n_sect);
            ft_putstr(file->sect_start[nlist->n_sect].sectname);
            //
            print_symtype(nlist->n_type);
            ft_putendl(strtable + nlist->n_un.n_strx);
        }
        nlist = (void *)nlist + sizeof(struct nlist_64);
        i++;
    }
}

static void scroll_section_32_macho(void *ptr, struct symtab_command *segment, int endian, t_nm *file)
{
    struct nlist *nlist;
    uint32_t i;
    void *strtable;
    int padding;

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
        // marche pas, a voir
        if (nlist->n_sect > 0)
            printf(" %s ", file->sect_start[nlist->n_sect].sectname);
        //
        print_symtype(nlist->n_type);
        ft_putendl(strtable + nlist->n_un.n_strx);
        nlist = (void *)nlist + sizeof(struct nlist);
        i++;
    }
}

void arch_64_macho(void *ptr, t_nm *file)
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
            scroll_section_64_macho(ptr, segment, endian, file);
        else if (((struct load_command*)segment)->cmd == LC_SEGMENT_64)
            get_sections_64(file, (struct segment_command_64*)segment, endian);
        segment += ((struct load_command *)segment)->cmdsize;
        if (endian == L_ENDIAN)
            swap_segment_command_64(segment);
        i--;
    }
}

void arch_32_macho(void *ptr, t_nm *file)
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
            scroll_section_32_macho(ptr, segment, endian, file);
        else if (((struct load_command*)segment)->cmd == LC_SEGMENT)
            get_sections(file, (struct segment_command*)segment, endian);
        segment += ((struct load_command *)segment)->cmdsize;
        if (endian == L_ENDIAN)
            swap_segment_command(segment);
        i--;
    }
}