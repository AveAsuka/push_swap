#include "push_swap.h"

/*
В финальной сортировке надо решить какой вариант займет меньше действий - ra или rra.
Для этого надо привязаться к максимальному значению и относительно него это высчитать.
*/

int final_sort_two(t_list **stack_a, int i)
{
    while(stack_a && *stack_a)
    {
        if ((*stack_a)->rank == 0)
            break;
        i++;
        if ((*stack_a)->next)
            *stack_a = (*stack_a)->next;
        else
            break;
    }

    return (i);
}

void final_sort(t_list **stack_a, t_num *check)
{
    t_list *first_elem_a;
    int i; // вверх
    int j; // вниз
    
    check->length_a = ft_lstsize(*stack_a) - 1;
    first_elem_a = *stack_a;
    i = 0;
    i = final_sort_two(stack_a, i);
    *stack_a = first_elem_a;
    j = check->length_a - i + 1; // сколько действий, если вниз
    if(j > i) // то тогда надо "вверх"
        while (i != 0)
        {
            *stack_a = stack_r(stack_a);
            write(1, "ra\n", 3);
            i--;
        }
    else // то вниз
        while(j != 0)
        {
            *stack_a = stack_rr(stack_a);
            write(1, "rra\n", 4);
            j--;
        }
// printf("\nИТОГОВАЯ проверка стэка А:\n");
// ft_print_2(*stack_a);
    free_stack(stack_a);
}
