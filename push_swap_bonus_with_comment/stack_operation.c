#include "push_swap.h"

// !Необходимо ещё прочекать момент, что делать, когда элементов стеке 
// СЛИШКОМ мало для манипуляци - 1 или 2.

// Мы принимаем "первый" элемент, вершину стэка
// - нам надо её в конец

t_list *first_b(t_list **lst)
{
    t_list *p;

    p = *lst;
    (*lst) = (*lst)->next;
    p->next = NULL;
    return(p);
}

t_list *stack_s(t_list **lst)
{
    t_list *first_elem;
    t_list *second_elem;

    if(!lst)
        return (NULL);
    if(!(*lst)->next)
        return(*lst); // ?

    first_elem = (*lst);        // первый элемент
    second_elem = (*lst)->next; // второй элемент
    
    first_elem->next = second_elem->next;  // 1. первый элем теперь смотрит на третий
    second_elem->next = first_elem;        // 2. второй элем теперь смотрит на первый
    (*lst) = second_elem;                  // 3. первый элемент теперь второй
    return (*lst);
}

t_list *stack_r(t_list **lst)
{
    t_list *first_elem;
    t_list *second_elem;

    if(!lst)
        return (NULL);
    if(!(*lst)->next)
        return(*lst); // ?

// Cохраняем ссылку на первый элемент
    first_elem = (*lst); 

// Cохраняем ссылку на второй элемент
    second_elem = (*lst)->next; // наш второй элемент

// Тут мы находим последний элемент
    while (lst && *lst && (*lst)->next)
        lst = &(*lst)->next;

// Передаем последнему элементу указатель на первый (вместо NULL)
    (*lst)->next = first_elem;
// Указатель первого элемента нулим, то есть делаем его последним
    first_elem->next = NULL;

// Указатель lst нам теперь фактически не нужен - нулим и его
    lst = NULL;

// Возвращаем второй элемент, который теперь стал первым
    return(second_elem);
}

// Мы принимаем "первый" элемент, вершину стэка
// - нам надо последний элемент поставить выше его
// при двух элементах в стеке б хреново работает
t_list *stack_rr(t_list **lst) // не работает с только двумя элементами!
{
    t_list *first_elem;
    t_list *last_elem;
    t_list *penultimate;

    if(!lst)
        return (NULL);
    if(!(*lst)->next)
        return(*lst); // ?

// Cохраняем ссылку на первый элемент
    first_elem = (*lst); 

// Тут мы находим предпоследний элемент, если он есть
    if((*lst)->next && (*lst)->next->next)
    {
        // write(1, "3", 1);
        while (lst && *lst && (*lst)->next && (*lst)->next->next)
        {
            penultimate = (*lst)->next;
            *lst = (*lst)->next;
        }
    }
    else // Если элемента только два
    {
        last_elem = (*lst)->next;
        last_elem->next = first_elem;
        first_elem->next = NULL;
        return(last_elem);
    }

// Тут последний
    last_elem = (*lst)->next;

// Последний элемент теперь ссылается на первый, а не на NULL
    last_elem->next = first_elem;

// Предпоследний теперь последний
    penultimate->next = NULL;

// Возвращаем новый первый элемент
    return(last_elem); // ??
}

void stack_p(t_list **head_from, t_list **head_to)
{
	t_list	*p;
	t_list	*p2;

    if (!head_from)
        return ;
    if (head_from)
    {
		p = *head_to;
        p2 = *head_from;
	
		(*head_from) = (*head_from)->next;
    
		*head_to = p2;
	    (*head_to)->next = p;
    }
}
