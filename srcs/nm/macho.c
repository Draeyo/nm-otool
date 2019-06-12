#include "nm.h"

static char *get_sectname_from_list(uint8_t index, t_nm *file)
{
    int         i;
    t_sections  *tmp;

    i = 0;
    tmp = file->sect_start;
    while (i++ < index)
        tmp = tmp->next;
    return (tmp->sectname);
}

static void get_sections(t_nm *file, struct segment_command *segment, int endian)
{
    uint32_t i;
    struct section *sect;
    t_sections *tmp;

    i = 0;
    if (segment->nsects > 0)
    {
        sect = (void *)segment + (segment->cmdsize - (sizeof(struct section) * segment->nsects));
        if (endian == L_ENDIAN)
            swap_section(sect, segment->nsects);
    }
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
    uint32_t i;
    struct section_64 *sect;
    t_sections *tmp;

    i = 0;
    if (segment->nsects > 0)
    {
        sect = (void *)segment + (segment->cmdsize - (sizeof(struct section_64) * segment->nsects));
        if (endian == L_ENDIAN)
            swap_section_64(sect, segment->nsects);
    }
    while (i < segment->nsects)
    {
        tmp = malloc(sizeof(t_sections));
        ft_bzero(tmp, sizeof(t_sections));
        ft_strcpy(tmp->segname, sect->segname);
        ft_strcpy(tmp->sectname, sect->sectname);
        tmp->next = NULL;
        if (file->sect_start)
            file->sections->next = tmp;
        else
            file->sect_start = tmp;
        file->sections = tmp;
        sect++;
        i++;
    }
}

static void select_nsect_type_64(t_nm *file, struct nlist_64* nlist)
{
    if (!ft_strcmp(get_sectname_from_list(nlist->n_sect - 1, file), SECT_BSS))
        ft_putchar(nlist->n_type & N_EXT ? 'B' : 'b');
    else if (!ft_strcmp(get_sectname_from_list(nlist->n_sect - 1, file), SECT_TEXT))
        ft_putchar(nlist->n_type & N_EXT ? 'T' : 't');
    else if (!ft_strcmp(get_sectname_from_list(nlist->n_sect - 1, file), SECT_DATA))
        ft_putchar(nlist->n_type & N_EXT ? 'D' : 'd');
    else    
        ft_putchar(nlist->n_type & N_EXT ? 'S' : 's');
}

static void select_nsect_type(t_nm *file, struct nlist* nlist)
{
    if (!ft_strcmp(get_sectname_from_list(nlist->n_sect - 1, file), SECT_BSS))
        ft_putchar(nlist->n_type & N_EXT ? 'B' : 'b');
    else if (!ft_strcmp(get_sectname_from_list(nlist->n_sect - 1, file), SECT_TEXT))
        ft_putchar(nlist->n_type & N_EXT ? 'T' : 't');
    else if (!ft_strcmp(get_sectname_from_list(nlist->n_sect - 1, file), SECT_DATA))
        ft_putchar(nlist->n_type & N_EXT ? 'D' : 'd');
    // else if (!ft_strcmp(file->sect_start[nlist->n_sect - 1].sectname, SECT_COMMON))
        // ft_putchar(nlist->n_type & N_EXT ? 'C' : 'c');
    else    
        ft_putchar(nlist->n_type & N_EXT ? 'S' : 's');
}

static void print_symtype_64(struct nlist_64 *nlist, t_nm *file)
{
    uint8_t tmp;

    tmp = nlist->n_type & N_TYPE;
    ft_putchar(' ');
    if (tmp == N_UNDF)
        ft_putchar(nlist->n_type & N_EXT ? 'U' : 'u');
    else if (tmp == N_ABS)
        ft_putchar(nlist->n_type & N_EXT ? 'A' : 'a');
    else if (tmp == N_SECT)
        select_nsect_type_64(file, nlist);
    else if (tmp == N_PBUD)
        ft_putchar(nlist->n_type & N_EXT ? 'X' : 'x');
    else if (tmp == N_INDR)
        ft_putchar(nlist->n_type & N_EXT ? 'Y' : 'y');
    else
        ft_putchar('?');
    ft_putchar(' ');
}

static void print_symtype(struct nlist *nlist, t_nm *file)
{
    uint8_t tmp;

    tmp = nlist->n_type & N_TYPE;
    ft_putchar(' ');
    if (tmp == N_UNDF)
        ft_putchar(nlist->n_type & N_EXT ? 'U' : 'u');
    else if (tmp == N_ABS)
        ft_putchar(nlist->n_type & N_EXT ? 'A' : 'a');
    else if (tmp == N_SECT)
        select_nsect_type(file, nlist);
    else if (tmp == N_PBUD)
        ft_putchar(nlist->n_type & N_EXT ? 'X' : 'x');
    else if (tmp == N_INDR)
        ft_putchar(nlist->n_type & N_EXT ? 'Y' : 'y');
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
            // printf(" %#X ", nlist->n_sect);
            //
            print_symtype_64(nlist, file);
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
        // if (nlist->n_sect > 0)
        //     printf(" %s ", file->sect_start[nlist->n_sect].sectname);
        //
        print_symtype(nlist, file);
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
        else if (((struct load_command *)segment)->cmd == LC_SEGMENT_64)
            get_sections_64(file, segment, endian);
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
        else if (((struct load_command *)segment)->cmd == LC_SEGMENT)
            get_sections(file, segment, endian);
        segment += ((struct load_command *)segment)->cmdsize;
        if (endian == L_ENDIAN)
            swap_segment_command(segment);
        i--;
    }
}