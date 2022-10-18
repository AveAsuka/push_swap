#include "push_swap.h"

/*
Теперь основное действо - мы перекачали в стек б все элементы,
после этого нам надо понять как считать [СКОРы], и после этого  
перекидывать элемент.

Следующий алгоритм: 1. Найти -> 2. Cчитать -> 3. Cравнивать -> 4. Выбирать
1. Найти где пара ранговая, должна быть в другом стеке;
2. Посчитать скольки им движений нужно для достижения вверха;
3. Сравнить с другими парами;
4. Выбрать самую оптимальную.
*/

void realize_two(t_list **stack_a, t_list **stack_b, t_num *check)
{
    while (check->rra > 0)
    {
        *stack_a = stack_rr(stack_a);
        write(1, "rra\n", 4);
        check->rra--;
    }
    while (check->rrb > 0)
    {
        *stack_b = stack_rr(stack_b);
        write(1, "rrb\n", 4);
        check->rrb--;
    }
    while (check->rrr > 0)
    {
        *stack_a = stack_rr(stack_a);
        *stack_b = stack_rr(stack_b);
        write(1, "rrr\n", 4);
        check->rrr--;
    }
}

void realize(t_list **stack_a, t_list **stack_b, t_num *check)
{
    while (check->ra > 0)
    {
        *stack_a = stack_r(stack_a);
        write(1, "ra\n", 3);
        check->ra--;
    }
    while (check->rb > 0)
    {
        *stack_b = stack_r(stack_b);
        write(1, "rb\n", 3);
        check->rb--;
    }
    while (check->rr > 0)
    {
        *stack_a = stack_r(stack_a);
        *stack_b = stack_r(stack_b);
        write(1, "rr\n", 3);
        check->rr--;
    }
    realize_two(stack_a, stack_b, check);
}

void save_move_two(t_list *current_a, t_list *current_b, t_num *check)
{
    if(check->code_1 == 0) // y
    {
        check->ra = current_a->a_up;
        check->rrb = current_b->b_down;
    }
    if(check->code_1 == 1) // x
    {
        check->rb = current_b->b_up;
        check->rra = current_a->a_down;
    }
    if(check->code_1 == 2) // i_2
    {
        if (current_a->a_up == current_b->b_up)
            check->rr = current_b->b_up;
        else if(current_a->a_up > current_b->b_up)
        {
            check->rr = current_b->b_up;
            check->ra = current_a->a_up - current_b->b_up;
        }
        else
        {
            check->rr = current_a->a_up;
            check->rb = current_b->b_up - current_a->a_up;
        }
    }
}

// 4.
void save_move(t_list *current_a, t_list *current_b, t_num *check)
{
    check->ra = 0;
    check->rb = 0;
    check->rr = 0;
    check->rra = 0;
    check->rrb = 0;
    check->rrr = 0;

    save_move_two(current_a, current_b, check);
    if(check->code_1 == 3) // i_1
    {
        if (current_a->a_down == current_b->b_down)
            check->rrr = current_b->b_down;
        else if(current_a->a_down > current_b->b_down)
        {
            check->rrr = current_b->b_down;
            check->rra = current_a->a_down - current_b->b_down;
        }
        else
        {
            check->rrr = current_a->a_down;
            check->rrb = current_b->b_down - current_a->a_down;
        }
    }
}

int search_min_two(int x, int i_1, int i_2, t_num *check)
{
    if (i_1 > i_2)
    {
        i_1 = i_2;
        check->code_2 = 2; // "i_2" меньшая
    }
    else 
        check->code_2 = 3; // "i_1" меньшая
    if (x > i_1)
    {
        x = i_1;
        check->code_1 = check->code_2;
    }
    return(x);
}

int search_min(t_list *current_a, t_list *current_b, t_num *check)
{
    int x;
    int y;
    int i_1;
    int i_2;
    
    x = current_a->a_down + current_b->b_up;
    y = current_a->a_up + current_b->b_down;
    if(current_a->a_down > current_b->b_down)
        i_1 = current_a->a_down;
    else
        i_1 = current_b->b_down;
    if(current_a->a_up > current_b->b_up)
        i_2 = current_a->a_up;
    else
        i_2 = current_b->b_up;
    if (x > y)
    {
        x = y;
        check->code_1 = 0; // "y" меньшая
    }
    else
        check->code_1 = 1; // "x" меньшая
    return(search_min_two(x, i_1, i_2, check));
}

// 2. 
void move_score(t_list *stack_a, t_list *stack_b, t_num *check)
{
    int    current_min;
    t_list *current_a;
    t_list *current_b;

    stack_a->a_down = ft_lstsize(stack_a); // Сколько до "вверха", если идти "вниз"
    stack_b->b_down = ft_lstsize(stack_b);
    stack_a->a_up = check->length_a - stack_a->a_down; // Сколько до "вверха", если идти "вверх"
    stack_b->b_up = check->length_b - stack_b->b_down;
    current_a = stack_a;
    current_b = stack_b;
    current_min = search_min(current_a, current_b, check);
    if(check->a == 0)
    {
        check->a = 1;
        check->move_min = current_min;
        current_a = stack_a;
        current_b = stack_b;
        save_move(current_a, current_b, check);
    }
    else
        if (check->move_min > current_min)
        {
            check->move_min = current_min;
            current_a = stack_a;
            current_b = stack_b;
            save_move(current_a, current_b, check);
        }
}

int last_a_rank(t_list *stack_a)
{
    int i;
    while (stack_a)
    {
        i = (stack_a)->rank;
		stack_a = stack_a -> next;    
    }
    return(i);
}

// 1. Надо перебрать сначала стэк а, если пары там не находится, то считать "мувы" (2.)
void pre_sorting(t_list **stack_a, t_list **stack_b, t_num *check)
{
    t_list *first_elem_a;
    t_list *first_elem_b;
    t_list *previus = (*stack_a)->next->next;

    first_elem_a = *stack_a;
    first_elem_b = *stack_b;
    while(stack_b && *stack_b)
    {
        check->a = 0;
        check->length_a = ft_lstsize(*stack_a);
        check->length_b = ft_lstsize(*stack_b);
        while(stack_a && *stack_a)
        {
            *stack_b = first_elem_b;
            while(stack_b && *stack_b)
            {
                if  ((previus->rank < (*stack_b)->rank)
                    && ((*stack_b)->rank < (*stack_a)->rank))
                    move_score(*stack_a, *stack_b, check);   // 2.
                if ((*stack_b)->next)
                    *stack_b = (*stack_b)->next;
                else
                    break;
            }
            if ((*stack_a)->next)
            {
                previus = *stack_a;
                *stack_a = (*stack_a)->next;
            }
            else
                break;
        }
        if(check->ra != 0 || check->rb != 0 || check->rr != 0 || check->rra != 0 || check->rrb != 0 || check->rrr != 0)
            realize(&first_elem_a, &first_elem_b, check);
        stack_p(&first_elem_b, &first_elem_a);
        write(1, "pa\n", 3);
        while (stack_a && *stack_a)
        {
		    if ((*stack_a)->next)
                *stack_a = (*stack_a)->next;
            else
                break;  
        }
        previus = *stack_a;
        *stack_a = first_elem_a;
        *stack_b = first_elem_b;
    }
}
