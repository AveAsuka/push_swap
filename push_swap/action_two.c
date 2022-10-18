/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:20:12 by rabderus          #+#    #+#             */
/*   Updated: 2022/05/06 18:24:29 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	realize_two(t_list **stack_a, t_list **stack_b, t_num *check)
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

void	realize(t_list **stack_a, t_list **stack_b, t_num *check)
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

void	save_move_two(t_list *current_a, t_list *current_b, t_num *check)
{
	if (check->code_1 == 0)
	{
		check->ra = current_a->a_up;
		check->rrb = current_b->b_down;
	}
	if (check->code_1 == 1)
	{
		check->rb = current_b->b_up;
		check->rra = current_a->a_down;
	}
	if (check->code_1 == 2)
	{
		if (current_a->a_up == current_b->b_up)
			check->rr = current_b->b_up;
		else if (current_a->a_up > current_b->b_up)
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

void	save_move(t_list *current_a, t_list *current_b, t_num *check)
{
	check->ra = 0;
	check->rb = 0;
	check->rr = 0;
	check->rra = 0;
	check->rrb = 0;
	check->rrr = 0;
	save_move_two(current_a, current_b, check);
	if (check->code_1 == 3)
	{
		if (current_a->a_down == current_b->b_down)
			check->rrr = current_b->b_down;
		else if (current_a->a_down > current_b->b_down)
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
