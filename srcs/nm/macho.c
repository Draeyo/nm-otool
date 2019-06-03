#include "nm.h"

// take symtab_command as argument instead of segment_command
static void scroll_section_64_macho(void *ptr, struct segment_command_64 *segment, int endian)
{
    // use nlist.h and stab.h to get structure for symtab
    // offset and nb of symbols are in symtab_commmand
    if (segment->cmd == LC_SYMTAB)
    {
        // if (endian == L_ENDIAN)
            // swap_section_64(section, segment->nsects);
        // DumpHex(ptr, section->offset, section->size);
    }
}

// take symtab_command as argument instead of segment_command
static void scroll_section_32_macho(void *ptr, struct segment_command *segment, int endian)
{
    // use nlist.h and stab.h to get structure for symtab
    // offset and nb of symbols are in symtab_commmand
    if (segment->cmd == LC_SYMTAB)
    {
        // if (endian == L_ENDIAN)
            // swap_section(section, segment->nsects);
        // DumpHex(ptr, section->offset, section->size);
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
        scroll_section_64_macho(ptr, segment, endian);
        segment += ((struct segment_command_64 *)segment)->cmdsize;
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
        scroll_section_32_macho(ptr, segment, endian);
        segment += ((struct segment_command *)segment)->cmdsize;
        if (endian == L_ENDIAN)
            swap_segment_command(segment);
        i--;
    }
}