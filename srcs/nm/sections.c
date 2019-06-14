#include "nm.h"

char *get_sectname_from_list(uint8_t index, t_nm *file)
{
    int i;
    t_sections *tmp;

    i = 0;
    tmp = file->sect_start;
    while (i++ < index)
        tmp = tmp->next;
    return (tmp->sectname);
}

void get_sections(t_nm *file, struct segment_command *segment, int endian)
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

void get_sections_64(t_nm *file, struct segment_command_64 *segment, int endian)
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

void select_nsect_type_64(t_nm *file, struct nlist_64 *nlist)
{
    if (!ft_strcmp(get_sectname_from_list(nlist->n_sect - 1, file), SECT_BSS))
        file->res_tmp->symtype[1] = nlist->n_type & N_EXT ? 'B' : 'b';
    else if (!ft_strcmp(get_sectname_from_list(nlist->n_sect - 1, file), SECT_TEXT))
        file->res_tmp->symtype[1] = nlist->n_type & N_EXT ? 'T' : 't';
    else if (!ft_strcmp(get_sectname_from_list(nlist->n_sect - 1, file), SECT_DATA))
        file->res_tmp->symtype[1] = nlist->n_type & N_EXT ? 'D' : 'd';
    else
        file->res_tmp->symtype[1] = nlist->n_type & N_EXT ? 'S' : 's';
}

void select_nsect_type(t_nm *file, struct nlist *nlist)
{
    if (!ft_strcmp(get_sectname_from_list(nlist->n_sect - 1, file), SECT_BSS))
        file->res_tmp->symtype[1] = nlist->n_type & N_EXT ? 'B' : 'b';
    else if (!ft_strcmp(get_sectname_from_list(nlist->n_sect - 1, file), SECT_TEXT))
        file->res_tmp->symtype[1] = nlist->n_type & N_EXT ? 'T' : 't';
    else if (!ft_strcmp(get_sectname_from_list(nlist->n_sect - 1, file), SECT_DATA))
        file->res_tmp->symtype[1] = nlist->n_type & N_EXT ? 'D' : 'd';
    // else if (!ft_strcmp(file->sect_start[nlist->n_sect - 1].sectname, SECT_COMMON))
    // file->res_tmp->symtype[1] = nlist->n_type & N_EXT ? 'C' : 'c';
    else
        file->res_tmp->symtype[1] = nlist->n_type & N_EXT ? 'S' : 's';
}