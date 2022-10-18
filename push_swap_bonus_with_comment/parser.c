#include "push_swap.h"

int perebor(char **a, t_list **stack_a, t_num *check)
{
    int l;
    int d;
    t_list *tmp;

    l = 0;
    d = 0;
    if (a == NULL || (*a) == NULL)
        return (empty_error(a, *stack_a, l));
    while(&*a[l])
    {
        d = fatoi(&*a[l], check);
        if (check->flag == 0)
            return (flag_error(a, *stack_a, l));
        else
        {
            if(!stack_a)
                (*stack_a) = ft_lstnew(d);
            else
            {
                tmp = ft_lstnew(d);
                ft_lstadd_back(stack_a, tmp);
            }
        }
        mem_free(a[l]);
        l++;
    }
    return(1);
}