#include "push_swap.h"

/*
!!! В интовом массиве 
(int) 0 равно (void *) 0, то есть 0 == '\0'
Как перебирать такой массив? Только через его длину.

!Скрытая сега заключалась в том, что когда в первый раз переносим из а в б не нулился 
некст первого элемента б, поэтому к нему цеплялась всякая хрень!
Для её обнаружения использовался 
*/

t_list *A_sort(t_list **lst, t_num *check)
{   
    if ((*lst)->content == check->min)
    {
        *lst = stack_r(lst);
        write(1, "ra\n", 3);
    }
    if ((*lst)->next->content == check->min)
    {
        *lst = stack_rr(lst);
        write(1, "rra\n", 4);
    }
    if ((*lst)->content == check->max && (*lst)->next->content == check->mean)
    {
        *lst = stack_s(lst);
        write(1, "sa\n", 3);
    }
    return(*lst);
}

void bubbleSort(int *num, int size)
{
    int i;
    int j;
    int temp;

    i = 0;
    while (i < (size - 1)) // Для всех элементов
    {
        j = (size - 1);
        while (j > i) // для всех элементов после i-ого
        {
            if (num[j - 1] > num[j]) // если текущий элемент меньше предыдущего
            {
                temp = num[j - 1]; // меняем их местами
                num[j - 1] = num[j];
                num[j] = temp;
            }
            j--;
        }
        i++;
    }
}

void ranks_dis(int *num, t_list **lst, t_num *check)
{
    int i;
    int j;

    while (lst && *lst) 
    {   
        i = check->length;
        j = 0;
        while(i != 0)
        {
            if((*lst)->content == num[j])
            {
                (*lst)->rank = j;
                break;
            }    
            i--;
            j++;
        }
        if ((*lst)->next)
            *lst = (*lst)->next;
        else
            break;
    }
}

// Так, у нас забит в стек_а числа, теперь нам надо перевести в стек_б
// все, кроме трёх[ТРИО] - "медиана-максимум-минимум"](!)
// Здесь и реализуем
t_list **find_trio(t_list **lst, t_num *check)
{
    int i;
    int j;
    int *a;

    t_list *first_elem;
    first_elem = *lst;
    a = malloc(sizeof(int) * check->length);
    i = 0;
    while (lst && *lst && (*lst)->next) 
    {   
        a[i++] = (*lst)->content;
        *lst = (*lst)->next;
    }
    a[i] = (*lst)->content;
    j = i+1;
    bubbleSort(a, j);
    *lst = first_elem;
    ranks_dis(a, lst, check);
    check->min = a[0];
    check->mean = a[j/2];
    check->max = a[j-1];
    *lst = first_elem; // не лишняя строчка!
    free(a);
    return(lst);
}

void steak_a_ra(t_list **first_elem, t_list **lst)
{
    *lst = stack_r(lst);
    write(1, "ra\n", 3);
    lst = first_elem;
}

void transfer_a_to_b_sort(t_list **lst, t_num *check, t_list *stack_b)
{
    *lst = A_sort(lst, check);
    pre_sorting(lst, &stack_b, check);
    final_sort(lst, check);
}

void transfer_a_to_b(t_list **lst, t_num *check)
{
    t_list **first_elem;
    t_list *stack_b;

    check->length = ft_lstsize(*lst);
    lst = find_trio(lst, check);
    first_elem = lst;
    stack_b = NULL;
    while (lst && *lst)
    {
        if (*lst)
            check->length = ft_lstsize(*lst);
        if (check->length == 3)
            break;
        if( (*lst)->content == check->mean
            || (*lst)->content == check->min || (*lst)->content == check->max )
            steak_a_ra(first_elem, lst);
        else
        {
            if(!stack_b)
                stack_b = first_b(lst);
            else
                stack_p(lst, &stack_b);
            write(1, "pb\n", 3);
        }
    }
    transfer_a_to_b_sort(lst, check, stack_b);
}
