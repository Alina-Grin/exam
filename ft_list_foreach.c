#include "ft_list.h"
#include <stdio.h>

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list  *ptr;

    ptr = begin_list;
    if (begin_list)
    {
        while (ptr)
        {
            (*f)(ptr->data);
            ptr = ptr->next;
        }
    }
}