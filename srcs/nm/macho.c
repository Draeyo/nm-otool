#include "nm.h"

// take symtab_command as argument instead of segment_command
static void scroll_section_64_macho(void *ptr, struct symtab_command *segment, int endian)
{
    struct nlist_64    *nlist;
    uint32_t            i;
    void                *strtable;
    char                *funcname;

    nlist = (void*)ptr + segment->symoff;
    strtable = (void*)ptr + segment->stroff;
    i = 0;
    while (i < segment->nsyms)
    {
        if (nlist->n_value)
            printf("%16X ", nlist->n_value);
        else
            printf("\t\t\t\t ");
        // to change
        printf("X ");
        ft_putendl(strtable + nlist->n_un.n_strx);
        nlist = (void*)nlist + sizeof(struct nlist_64);
        i++;
    }
}

// take symtab_command as argument instead of segment_command
static void scroll_section_32_macho(void *ptr, struct symtab_command *segment, int endian)
{
    struct nlist    *nlist;
    uint32_t        i;
    void            *strtable;

    nlist = (void*)ptr + segment->symoff;
    strtable = (void*)ptr + segment->stroff;
    i = 0;
    while (i < segment->nsyms)
    {
        if (nlist->n_value)
            printf("%16X ", nlist->n_value);
        else
            printf("\t\t\t\t ");
        // to change
        printf("X ");
        ft_putendl(strtable + nlist->n_un.n_strx);
        nlist = (void*)nlist + sizeof(struct nlist);
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

    endian = (*(uint32_t*)ptr) == MH_CIGAM_64 ? L_ENDIAN : B_ENDIAN;
    header = (struct mach_header_64*)ptr;
    if (endian == L_ENDIAN)
        swap_mach_header_64(header);
    i = ((struct mach_header_64*)header)->ncmds;
    load = ptr + sizeof(struct mach_header_64);
    if (endian == L_ENDIAN)
        swap_load_command(load);
    segment = load;
    if (endian == L_ENDIAN)
        swap_segment_command_64(segment);
    while (i > 0)
    {
        if ((uint32_t)segment == LC_SYMTAB)
            scroll_section_64_macho(ptr, segment, endian);
        // segment += ((struct segment_command_64 *)segment)->cmdsize;
        segment = (void*)segment + (uint32_t)((void*)segment + sizeof(uint32_t));
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

    endian = (*(uint32_t*)ptr) == MH_CIGAM ? L_ENDIAN : B_ENDIAN;
    header = (struct mach_header*)ptr;
    if (endian == L_ENDIAN)
        swap_mach_header(header);
    i = ((struct mach_header*)header)->ncmds;
    load = ptr + sizeof(struct mach_header);
    if (endian == L_ENDIAN)
        swap_load_command(load);
    segment = load;
    if (endian == L_ENDIAN)
        swap_segment_command(segment);
    while (i > 0)
    {
        if ((uint32_t)segment == LC_SYMTAB)
            scroll_section_32_macho(ptr, segment, endian);
        segment = (void*)segment + (uint32_t)((void*)segment + sizeof(uint32_t));
        if (endian == L_ENDIAN)
            swap_segment_command(segment);
        i--;
    }
}