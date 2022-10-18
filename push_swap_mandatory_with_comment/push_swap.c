#include "push_swap.h"

// Ладно, надо с чего-то начинать - начну с чекера и парсера 
// одновременно - нужно чтобы это точно было число в пределах 
// int-а, и не было дубликатов, и надо учесть кавычки.
// Записывать буду в лист.

int stek_cheack(t_list **lst, t_num *check)
{
    t_list *gost;
    t_list *first_elem;
    int i;

    first_elem = (*lst);
//////// Проверка на дубликаты
    while (lst && *lst && (*lst)->next)
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
    {
        // write("Ошибка - есть дубликаты.\n");
        write(1, "Error.\n", 8);
        return (-1);
    }

//////// Проверка на сортировку
    check->flag = 0;
    (lst) = &first_elem; //Возвращаем lst ссылку на первый элемент  
    // printf("(*lst)->content = %d\n", (*lst)->content);

//! Тут важно, чтобы мы проверяли наличие ссылки на следующий элемент
    while (lst && *lst && (*lst)->next)
    {
        i = (*lst)->content;
        // printf("i = %d\n", i);

        (*lst) = (*lst)->next;
        // printf("(*lst)->content = %d\n", (*lst)->content);

        if(i > (*lst)->content)
            check->flag = 1;

        if ((*lst)->next == NULL)
            break;
    }

    if (check->flag == 0)
    {
        // printf("Ошибка - уже отсортировано.\n");
        // write(1, "Error.\n", 8);
        return (-1);
    }
    return(1);
}

void mem_free(char *a)
{
	free(a);
    a = NULL;
}

void	free_stack(t_list **head)
{
	t_list	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		tmp = NULL;
	}
}

int main(int argc, char **argv)
{
    char **a;
    
    int i;
    int l;
    int d;
    int x;

    t_num check;
    t_list *tmp;
    t_list *stack_a;

    i = 1;
    check.flag = 1;
    stack_a = NULL;
    
    if (argc < 2)
        return(0);

    while (argc > i)
    {
        l = 0;
        d = 0;

        a = ft_split(argv[i], ' ');

        if (a == NULL || (*a) == NULL)
        {
            write(1, "Error.\n", 8);
            free_stack(&stack_a);
            if (a && (&*a[l]))
            {
                x = 0;
                while(&*a[x])
                {
                    mem_free(a[l]);
                    free(a);
                    x++;
                }
            }
            return (0);
        }
       
        while(&*a[l])
        {
        // 1.1) потом провести через atoi + 
        // 1.2) проверить на то, что это число +
        // 3) потом запихнуть в стек +
        // printf("flag = %d\n", check.flag);
            d = fatoi(&*a[l], &check);
            if (check.flag == 0)
            {   
                write(1, "Error!\n", 8);
                mem_free(a[l]);
                free(a);
                free_stack(&stack_a);
                return (0);
            }
            else
            {
                if(!stack_a)
                    stack_a = ft_lstnew(d);
                else
                {
                    tmp = ft_lstnew(d);
                    ft_lstadd_back(&stack_a, tmp); //! Надо записывать в конец, а не в начало
                }
            }
            mem_free(a[l]);

            l++;
        }
        i++;
        free(a);
    }
    // У нас все числа в стеке. Теперь надо проверить что: 
    // 1) они идут не по порядку; 
    // 2) в них нету дубликатов

    check.flag = 1;
    i = ft_lstsize(stack_a);

    if (i == 2 && (stack_a)->content > (stack_a)->next->content)
    {
        stack_a = stack_s(&stack_a);
        write(1, "sa\n", 3);
    }
    else if (i == 1 || stek_cheack(&stack_a, &check) == -1)
    {}
    else
        transfer_a_to_b(&stack_a, &check);

    free_stack(&stack_a);
    return (0);
}



















/*
    int main(int argc, char **argv)
{
    char **a;
    int i;
    // int k = 0;
    // int j;
    int l;

    i = 1;
    
    if (argc < 2)
        return(0);

    while (argc > i)
    {
        // j = ft_strlen(argv[i]);
        // // printf("%d\n", j);
    
        a = ft_split(argv[i], ' ');
        
        l = 0;
        // j = ft_strlen(a[l]);
        while(&*a[l])
        {
            // printf("%s\n", &*a[l]);

            l++;
        }

        i++;
    }

    return 0;
}


*/