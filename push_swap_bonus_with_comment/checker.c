#include "push_swap.h"

int stek_sort_cheack(t_list **lst, t_num *check, int i)
{
    while (lst && *lst && (*lst)->next)
    {
        i = (*lst)->content;
        (*lst) = (*lst)->next;
        if(i > (*lst)->content)
            check->flag = 1;
        if ((*lst)->next == NULL)
            break;
    }
    return (check->flag);
}

int stek_cheack(t_list **lst, t_num *check)
{
    t_list *gost;
    t_list *first_elem;
    int i;

    first_elem = (*lst);
    while (lst && *lst && (*lst)->next) // Проверка на дубликаты
    {
        i = (*lst)->content;
        gost = (*lst)->next;
        while (gost)
        {
            if (i == gost->content)
                check->flag = 0;
            gost = gost->next;
        }
        lst = &(*lst)->next;
    }
    if (check->flag == 0)
        return (stek_cheack_error());
    check->flag = 0; // Проверка на сортировку
    lst = &first_elem;
    if (stek_sort_cheack(lst, check, i) == 0)
        return (-1);
    return(1);
}

int stek_cheack_bonus(t_list **lst, t_num *check)
{
    t_list *gost;
    t_list *first_elem;
    int i;

    first_elem = (*lst);
    while (lst && *lst && (*lst)->next) // Проверка на дубликаты
    {
        i = (*lst)->content;
        gost = (*lst)->next;
        while (gost)
        {
            if (i == gost->content)
                check->flag = 0;
            gost = gost->next;
        }
        lst = &(*lst)->next;
    }
    if (check->flag == 0)
        return (-1);
    return(1);
}
