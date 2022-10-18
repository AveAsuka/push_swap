#include "push_swap.h"

// Ладно, надо с чего-то начинать - начну с чекера и парсера 
// одновременно - нужно чтобы это точно было число в пределах 
// int-а, и не было дубликатов, и надо учесть кавычки.
// Записывать буду в лист.

void two_elem(t_list *stack_a)
{
    stack_a = stack_s(&stack_a);
    write(1, "sa\n", 3);
}

int main(int argc, char **argv)
{
    int i;
    char **a;
    t_num check;
    t_list *stack_a;

    check.flag = 1;
    stack_a = NULL;
    if (argc < 2)
        return(0);
    i = 1;
    while (argc > i)
    {
        a = ft_split(argv[i], ' ');
        if (perebor(a, &stack_a, &check) == 0)
            return(0);
        i++;
        free(a);
    }
    check.flag = 1;
    if (ft_lstsize(stack_a) == 2 && (stack_a)->content > (stack_a)->next->content)
        two_elem(stack_a);
    else if (ft_lstsize(stack_a) == 1 || stek_cheack(&stack_a, &check) == -1)
    {}
    else
        transfer_a_to_b(&stack_a, &check);
    free_stack(&stack_a);
    return (0);
}
