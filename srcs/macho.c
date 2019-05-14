#include "otool.h"

static void scroll_section_64_macho(void *ptr, struct segment_command_64 *segment)
{
    int                 section_nb;
    struct section_64   *section;

    if (segment->cmd == LC_SEGMENT_64)
    {
        section_nb = segment->nsects;
        section = (void*)segment + (segment->cmdsize - (sizeof(struct section_64) * segment->nsects));
        while (section_nb > 0)
        {
            if (!ft_strcmp(section->sectname, SECT_TEXT))
            {
                printf("Contents of (%s,%s) section\n", section->segname, section->sectname);
                DumpHex(ptr + section->offset, section->size);
            }
            section++;
            section_nb--;
        }
    }
}

static void scroll_section_32_macho(void *ptr, struct segment_command *segment)
{
    int                 section_nb;
    struct section   *section;

    if (segment->cmd == LC_SEGMENT)
    {
        section_nb = segment->nsects;
        section = (void*)segment + (segment->cmdsize - (sizeof(struct section) * segment->nsects));
        while (section_nb > 0)
        {
            if (!ft_strcmp(section->sectname, SECT_TEXT))
            {
                printf("Contents of (%s,%s) section\n", segment->segname, section->sectname);
                DumpHex(ptr + section->offset, section->size);
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

    header = (struct mach_header_64*)ptr;
    i = ((struct mach_header_64*)header)->ncmds;
    load = ptr + sizeof(struct mach_header_64);
    segment = load;
    while (i > 0)
    {
        scroll_section_64_macho(ptr, segment);
        segment += ((struct segment_command_64 *)segment)->cmdsize;
        i--;
    }
}

void arch_32_macho(void *ptr)
{
    void *header;
    void *load;
    void *segment;
    int i;

    header = (struct mach_header*)ptr;
    i = ((struct mach_header*)header)->ncmds;
    load = ptr + sizeof(struct mach_header);
    segment = load;
    while (i > 0)
    {
        scroll_section_32_macho(ptr, segment);
        segment += ((struct segment_command *)segment)->cmdsize;
        i--;
    }
}