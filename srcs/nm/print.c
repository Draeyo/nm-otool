#include "nm.h"

void print_symtype_64(struct nlist_64 *nlist, t_nm *file)
{
    uint8_t tmp;

    file->res_tmp->symtype[3] = '\0';
    tmp = nlist->n_type & N_TYPE;
    // ft_putchar(' ');
    file->res_tmp->symtype[0] = ' ';
    if (tmp == N_UNDF)
        file->res_tmp->symtype[1] = nlist->n_type & N_EXT ? 'U' : 'u';
    else if (tmp == N_ABS)
        file->res_tmp->symtype[1] = nlist->n_type & N_EXT ? 'A' : 'a';
    else if (tmp == N_SECT)
        select_nsect_type_64(file, nlist);
    else if (tmp == N_PBUD)
        file->res_tmp->symtype[1] = nlist->n_type & N_EXT ? 'X' : 'x';
    else if (tmp == N_INDR)
        file->res_tmp->symtype[1] = nlist->n_type & N_EXT ? 'Y' : 'y';
    else
        file->res_tmp->symtype[1] = '?';
    // ft_putchar(' ');
    file->res_tmp->symtype[2] = ' ';
}

void print_symtype(struct nlist *nlist, t_nm *file)
{
    uint8_t tmp;

    file->res_tmp->symtype[3] = '\0';
    tmp = nlist->n_type & N_TYPE;
    // ft_putchar(' ');
    file->res_tmp->symtype[0] = ' ';
    if (tmp == N_UNDF)
        file->res_tmp->symtype[1] = nlist->n_type & N_EXT ? 'U' : 'u';
    else if (tmp == N_ABS)
        file->res_tmp->symtype[1] = nlist->n_type & N_EXT ? 'A' : 'a';
    else if (tmp == N_SECT)
        select_nsect_type(file, nlist);
    else if (tmp == N_PBUD)
        file->res_tmp->symtype[1] = nlist->n_type & N_EXT ? 'X' : 'x';
    else if (tmp == N_INDR)
        file->res_tmp->symtype[1] = nlist->n_type & N_EXT ? 'Y' : 'y';
    else
        file->res_tmp->symtype[1] = '?';
    // ft_putchar(' ');
    file->res_tmp->symtype[2] = ' ';
}

void    hex_padding16(unsigned long nb, t_nm *file)
{
    int i;

    i = 16;
    while (nb > 0 && i > 0)
    {
        nb /= 16;
        i--;
    }
    file->res_tmp->padding = i;
}

void print_hex(unsigned long nb)
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

void get_hex(unsigned long nb, t_nm *file)
{
    const char  *tmp = "0123456789abcdef";
    int         i;

	i = 0;
	file->res_tmp->offset[16] = '\0';
	while (i < 16)
	{
		file->res_tmp->offset[i] = nb ? '0' : ' ';
		i++;
	}
    i = nb ? 15 : 0;
    while (i > 0)
    {
        if (nb >= 16)
            file->res_tmp->offset[i] = tmp[nb % 16];
        else
            file->res_tmp->offset[i] = tmp[nb];
        nb /= 16;
        i--;
    }
}