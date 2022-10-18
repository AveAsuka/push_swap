#include "push_swap.h"

/*
Так, 1) надо принять числа через парсер,
2) потом пробить энтер, после этого 
3) надо принимать команды до того как 
4) не пришло control+D
5) потом либо OK либо KO
*/

int	main(int argc, char **argv)
{
    int i;
    char **a;
    t_num check;
    t_list *stack_a;

    t_list  *first_elem;
    

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

    first_elem = stack_a;
    // printf("\nпроверка стэка А:\n");
    // ft_print_2(first_elem);

// мы тут парсим как обычно, но потом идёт наш случай, когда не делаем команды, а принимаем их
    check.flag = 1;
    if (stek_cheack_bonus(&stack_a, &check) == -1)
    {
        stek_cheack_error();
        free_stack(&stack_a);
        return (0);
    }
    read_instructions(&first_elem); // stack_a
    // free_stack(&stack_a);
    return (0);
}