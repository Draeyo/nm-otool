#include "nm.h"

void get_result(t_nm *file)
{
    if (!file->res_start)
    {
        file->result = file->res_tmp;
        file->res_start = file->result;
    }
    else
    {
        file->result->next = file->res_tmp;
        file->result = file->result->next;
    }
}