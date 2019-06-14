#include "nm.h"

void print_nm(t_nm *file)
{
    while (file->res_start)
    {
        ft_putstr(file->res_start->offset);
        ft_putstr(file->res_start->symtype);
        ft_putendl(file->res_start->content);
        file->res_start = file->res_start->next;
    }
}