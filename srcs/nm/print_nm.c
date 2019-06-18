#include "nm.h"

static void     sort_nm(t_nm *file)
{
    t_result    *tmp;
    t_result    *res;
    t_result    *prev;

    tmp = NULL;
    res = file->res_start;
    prev = NULL;
    while (res->next)
    {
        if (ft_strcmp(res->content, res->next->content) > 0)
        {
            tmp = res->next;
            res->next = tmp->next;
            if (prev)
                prev->next = tmp;
            else
                file->res_start = tmp;
            tmp->next = res;
            res = file->res_start;
            prev = NULL;           
        }
        else
        {
            prev = res;
            res = res->next;
        }
    }
}

void print_nm(t_nm *file)
{
    t_result    *tmp;

    sort_nm(file);
    tmp = file->res_start;
    while (tmp)
    {
        ft_putstr(tmp->offset);
        ft_putstr(tmp->symtype);
        ft_putendl(tmp->content);
        tmp = tmp->next;
    }
}