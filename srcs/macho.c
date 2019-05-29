#include "otool.h"

static void scroll_section_64_macho(void *ptr, struct segment_command_64 *segment, int endian)
{
    int                 section_nb;
    struct section_64   *section;

    if (segment->cmd == LC_SEGMENT_64)
    {
        section_nb = segment->nsects;
        section = (void*)segment + (segment->cmdsize - (sizeof(struct section_64) * segment->nsects));
        if (endian == L_ENDIAN)
            swap_section_64(section, segment->nsects);
        while (section_nb > 0)
        {
            if (!ft_strcmp(section->sectname, SECT_TEXT))
            {
                printf("Contents of (%s,%s) section\n", section->segname, section->sectname);
                DumpHex(ptr, section->offset, section->size);
            }
            section++;
            section_nb--;
        }
    }
}

static void scroll_section_32_macho(void *ptr, struct segment_command *segment, int endian)
{
    int                 section_nb;
    struct section      *section;

    if (segment->cmd == LC_SEGMENT)
    {
        section_nb = segment->nsects;
        section = (void*)segment + (segment->cmdsize - (sizeof(struct section) * segment->nsects));
        if (endian == L_ENDIAN)
            swap_section(section, segment->nsects);
        while (section_nb > 0)
        {
            if (!ft_strcmp(section->sectname, SECT_TEXT))
            {
                printf("Contents of (%s,%s) section\n", segment->segname, section->sectname);
                DumpHex(ptr, section->offset, section->size);
            }
            section++;
            section_nb--;
        }
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