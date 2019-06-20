#include "nm.h"

static void scroll_section_64_macho(void *ptr, struct symtab_command *segment, int endian, t_nm *file)
{
    struct nlist_64 *nlist;
    uint32_t i;
    void *strtable;

    nlist = (void *)ptr + segment->symoff;
    strtable = (void *)ptr + segment->stroff;
    i = 0;
    (void)endian;
    while (i < segment->nsyms)
    {
        // see this condition
        if (!(nlist->n_type & N_STAB))
        {
            file->res_tmp = malloc(sizeof(t_result));
            ft_bzero(file->res_tmp, sizeof(t_result));
            hex_padding16(nlist->n_value, file);
            get_hex(nlist->n_value, file);
            print_symtype_64(nlist, file);
            file->res_tmp->content = ft_strdup(strtable + nlist->n_un.n_strx);
            get_result(file);
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

    nlist = (void *)ptr + segment->symoff;
    strtable = (void *)ptr + segment->stroff;
    i = 0;
    (void)endian;
    while (i < segment->nsyms)
    {
        if (!(nlist->n_type & N_STAB))
        {
            file->res_tmp = malloc(sizeof(t_result));
            ft_bzero(file->res_tmp, sizeof(t_result));
            hex_padding16(nlist->n_value, file);
            get_hex(nlist->n_value, file);
            print_symtype(nlist, file);
            file->res_tmp->content = ft_strdup(strtable + nlist->n_un.n_strx);
            get_result(file);
        }
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
    file->arch = ARCH64;
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
    print_nm(file);
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
    file->arch = ARCH32;
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
    print_nm(file);
}