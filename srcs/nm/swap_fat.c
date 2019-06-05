#include "nm.h"

void swap_fat_header(struct fat_header *fh)
{
    fh->magic = swap_uint32(fh->magic);
    fh->nfat_arch = swap_uint32(fh->nfat_arch);
}

void swap_fat_arch(struct fat_arch *fa)
{
    fa->cputype = swap_int32(fa->cputype);       /* cpu specifier (int) */
    fa->cpusubtype = swap_int32(fa->cpusubtype); /* machine specifier (int) */
    fa->offset = swap_uint32(fa->offset);        /* file offset to this object file */
    fa->size = swap_uint32(fa->size);            /* size of this object file */
    fa->align = swap_uint32(fa->align);          /* alignment as a power of 2 */
}

void swap_fat_arch_64(struct fat_arch_64 *fa)
{
    fa->cputype = swap_int32(fa->cputype);       /* cpu specifier (int) */
    fa->cpusubtype = swap_int32(fa->cpusubtype); /* machine specifier (int) */
    fa->offset = swap_uint64(fa->offset);          /* file offset to this object file */
    fa->size = swap_uint64(fa->size);            /* size of this object file */
    fa->align = swap_uint32(fa->align);           /* alignment as a power of 2 */
    fa->reserved = swap_uint32(fa->reserved);        /* reserved */
}
