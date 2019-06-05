#include "otool.h"

void    swap_mach_header_64(struct mach_header_64 *mh)
{
	mh->magic = swap_int32(mh->magic);
	mh->cputype = swap_int32(mh->cputype);
	mh->cpusubtype = swap_int32(mh->cpusubtype);
	mh->filetype = swap_int32(mh->filetype);
	mh->ncmds = swap_int32(mh->ncmds);
	mh->sizeofcmds = swap_int32(mh->sizeofcmds);
	mh->flags = swap_int32(mh->flags);
	mh->reserved = swap_int32(mh->reserved);
}

void    swap_mach_header(struct mach_header *mh)
{
	mh->magic = swap_int32(mh->magic);
	mh->cputype = swap_int32(mh->cputype);
	mh->cpusubtype = swap_int32(mh->cpusubtype);
	mh->filetype = swap_int32(mh->filetype);
	mh->ncmds = swap_int32(mh->ncmds);
	mh->sizeofcmds = swap_int32(mh->sizeofcmds);
	mh->flags = swap_int32(mh->flags);
}

void    swap_load_command(struct load_command *lc)
{
	lc->cmd = swap_int32(lc->cmd);
	lc->cmdsize = swap_int32(lc->cmdsize);
}

void    swap_segment_command(struct segment_command *sg)
{
	/* segname[16] */
	sg->cmd = swap_int32(sg->cmd);
	sg->cmdsize = swap_int32(sg->cmdsize);
	sg->vmaddr = swap_int32(sg->vmaddr);
	sg->vmsize = swap_int32(sg->vmsize);
	sg->fileoff = swap_int32(sg->fileoff);
	sg->filesize = swap_int32(sg->filesize);
	sg->maxprot = swap_int32(sg->maxprot);
	sg->initprot = swap_int32(sg->initprot);
	sg->nsects = swap_int32(sg->nsects);
	sg->flags = swap_int32(sg->flags);
}

void    swap_segment_command_64(struct segment_command_64* sg)
{
	/* char segname[16] */
	sg->cmd = swap_int32(sg->cmd);
	sg->cmdsize = swap_int32(sg->cmdsize);
	sg->vmaddr = swap_int64(sg->vmaddr);
	sg->vmsize = swap_int64(sg->vmsize);
	sg->fileoff = swap_int64(sg->fileoff);
	sg->filesize = swap_int64(sg->filesize);
	sg->maxprot = swap_int32(sg->maxprot);
	sg->initprot = swap_int32(sg->initprot);
	sg->nsects = swap_int32(sg->nsects);
	sg->flags = swap_int32(sg->flags);
}

void    swap_section(struct section *s, uint32_t nsects)
{
    uint32_t i;

    i = 0;
	while (i < nsects)
    {
	    /* sectname[16] */
	    /* segname[16] */
	    s[i].addr = swap_int32(s[i].addr);
	    s[i].size = swap_int32(s[i].size);
	    s[i].offset = swap_int32(s[i].offset);
	    s[i].align = swap_int32(s[i].align);
	    s[i].reloff = swap_int32(s[i].reloff);
	    s[i].nreloc = swap_int32(s[i].nreloc);
	    s[i].flags = swap_int32(s[i].flags);
	    s[i].reserved1 = swap_int32(s[i].reserved1);
	    s[i].reserved2 = swap_int32(s[i].reserved2);
        i++;
	}
}

void    swap_section_64(struct section_64 *s, uint32_t nsects)
{
    uint32_t i;

    i = 0;
	while (i < nsects)
    {
	    /* sectname[16] */
	    /* segname[16] */
	    s[i].addr = swap_int64(s[i].addr);
	    s[i].size = swap_int64(s[i].size);
	    s[i].offset = swap_int32(s[i].offset);
	    s[i].align = swap_int32(s[i].align);
	    s[i].reloff = swap_int32(s[i].reloff);
	    s[i].nreloc = swap_int32(s[i].nreloc);
	    s[i].flags = swap_int32(s[i].flags);
	    s[i].reserved1 = swap_int32(s[i].reserved1);
	    s[i].reserved2 = swap_int32(s[i].reserved2);
	    s[i].reserved3 = swap_int32(s[i].reserved3);
        i++;
	}
}
