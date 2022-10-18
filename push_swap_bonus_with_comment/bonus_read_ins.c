#include "push_swap.h"

/*
1. Ломается на бонусах, когда в стеке б ничего нет или один элемент, а мы делаем rr или rrr
2. Так же сегается по неизвестной причине, когда прогоняем много команд в бонусах
3. Не фришит стек б при работе по непонятной причине - это самая сложная ошибка
*/

int not_sorted(t_list **stack_a)
{
    // printf("\n1) проверка стэка А:\n");
    // ft_print_2(*stack_a);

    while(stack_a && *stack_a && (*stack_a)->next)
    {
        if ((*stack_a)->content > (*stack_a)->next->content)
            return(0);
        *stack_a = (*stack_a)->next;
    }
    // printf("\n2) проверка стэка А:\n");
    // ft_print_2(*stack_a);
    return(1);
}

int do_comand_two(t_list **stack_a, t_list **stack_b, char *comand)
{
    if (ft_strcmp(comand, "ra") == 0)
        *stack_a = stack_r(stack_a);
	else if (ft_strcmp(comand, "rb") == 0)
    {
        if(!(*stack_b))
            {}
        else
            *stack_b = stack_r(stack_b);
    }
	else if (ft_strcmp(comand, "rr") == 0)
    {
        *stack_a = stack_r(stack_a);
        if(!(*stack_b))
            {}
        else
            *stack_b = stack_r(stack_b);
    }
	else if (ft_strcmp(comand, "rra") == 0)
        *stack_a = stack_rr(stack_a);
	else if (ft_strcmp(comand, "rrb") == 0)
    {
        if(!(*stack_b))
            {}
        else
            *stack_b = stack_rr(stack_b);
    }
	else if (ft_strcmp(comand, "rrr") == 0)
    {
        *stack_a = stack_rr(stack_a);
        if(!(*stack_b))
            {}
        else
            *stack_b = stack_rr(stack_b);
    }
    else
		return (0);
	return (1);
}

int do_comand(t_list **stack_a, t_list **stack_b, char *comand)
{
    if (ft_strcmp(comand, "sa") == 0)
		*stack_a = stack_s(stack_a);
	else if (ft_strcmp(comand, "sb") == 0)
    {
        if(!(*stack_b))
            {}
        else
		    *stack_b = stack_s(stack_b);
    }
	else if (ft_strcmp(comand, "ss") == 0)
    {
		*stack_a = stack_s(stack_a);
        if(!(*stack_b))
            {}
        else
		    *stack_b = stack_s(stack_b);
    }
	else if (ft_strcmp(comand, "pa") == 0)
    {
        if(!(*stack_b))
            {}
        else
		    stack_p(stack_b, stack_a);
    }
	else if (ft_strcmp(comand, "pb") == 0)
    {
        if(!(*stack_b))
            *stack_b = first_b(stack_a);
        else
            stack_p(stack_a, stack_b);
    }
	else if (do_comand_two(stack_a, stack_b, comand) == 0)  
        return(0);
    return(1);
}

int length_instructions(char (*comand)[5])
{
    int size;
    char symbol[2];
    
    *comand[0] = '\0'; // перед анализом строки нулим её начало
	size = read(0, symbol, 1); // читаем один символ с терминала, подразумевается, что это symbol[0]
	symbol[1] = '\0'; // сразу нулим его, для нормального анализа

    while (size == 1 && symbol[0] != '\n')
    {
        ft_strlcat(*comand, symbol, 5); // приращиваем куда, откуда, до какой длины
		size = read(0, symbol, 1); // не накапливает длина, возращает 1
    }
    return(size);
}

void    read_instructions(t_list **stack_a)
{
    t_list  *stack_b;
    char    comand[5];
    int     size;

    t_list  *first_elem; // потом удалить

    stack_b = NULL;
    size = length_instructions(&comand); // запускаем цикл
// printf("2. size = %d, buf = 1) %c 2) %c 3) %c 4) %c 5) %c\n", size, comand[0],comand[1], comand[2], comand[3], comand[4]);

    while(size == 1) // в цикле 
    {
        if (do_comand(stack_a, &stack_b, comand) == 0)
        {
            free_stack(&stack_b);
            stek_cheack_error();
            return ;
        }
        size = length_instructions(&comand);
// printf("3. size = %d, buf = 1) %c 2) %c 3) %c 4) %c 5) %c\n", size, comand[0],comand[1], comand[2], comand[3], comand[4]);
    }

// printf("\n0 проверка стэка А:\n");
// ft_print_2(*stack_a);
// printf("\n0 проверка стэка Б:\n");
// ft_print_2(stack_b);

first_elem = *stack_a;

    if (ft_lstsize(stack_b) > 0 || not_sorted(stack_a) == 0)
	{
		ft_putstr_fd("KO\n", 1);

// printf("\nKO - проверка стэка А:\n");
// ft_print_2(first_elem);
// printf("\nKO - проверка стэка Б:\n");
// ft_print_2(stack_b);

	}
	else
    {
    
// printf("\nOK - проверка стэка А:\n");
// ft_print_2(first_elem);
// printf("\nOK - проверка стэка Б:\n");
// ft_print_2(stack_b);

		ft_putstr_fd("OK\n", 1);
    }

    // first_elem = NULL;
    if(stack_a)
        free_stack(&first_elem);
        // free_stack(stack_a);
    if(stack_b)
        free_stack(&stack_b);
}
