/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:22:12 by rabderus          #+#    #+#             */
/*   Updated: 2022/05/06 18:25:05 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_min_two(int x, int i_1, int i_2, t_num *check)
{
	if (i_1 > i_2)
	{
		i_1 = i_2;
		check->code_2 = 2;
	}
	else
		check->code_2 = 3;
	if (x > i_1)
	{
		x = i_1;
		check->code_1 = check->code_2;
	}
	return (x);
}

int	search_min(t_list *current_a, t_list *current_b, t_num *check)
{
	int	x;
	int	y;
	int	i_1;
	int	i_2;

	x = current_a->a_down + current_b->b_up;
	y = current_a->a_up + current_b->b_down;
	if (current_a->a_down > current_b->b_down)
		i_1 = current_a->a_down;
	else
		i_1 = current_b->b_down;
	if (current_a->a_up > current_b->b_up)
		i_2 = current_a->a_up;
	else
		i_2 = current_b->b_up;
	if (x > y)
	{
		x = y;
		check->code_1 = 0;
	}
	else
		check->code_1 = 1;
	return (search_min_two(x, i_1, i_2, check));
}

int	move_score_two(t_list *stack_a, t_list *stack_b, t_num *check)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = stack_a;
	current_b = stack_b;
	return (search_min(current_a, current_b, check));
}

void	move_score(t_list *stack_a, t_list *stack_b, t_num *check)
{
	int		current_min;
	t_list	*current_a;
	t_list	*current_b;

	stack_a->a_down = ft_lstsize(stack_a);
	stack_b->b_down = ft_lstsize(stack_b);
	stack_a->a_up = check->length_a - stack_a->a_down;
	stack_b->b_up = check->length_b - stack_b->b_down;
	current_min = move_score_two(stack_a, stack_b, check);
	if (check->a == 0)
	{
		check->a = 1;
		check->move_min = current_min;
		current_a = stack_a;
		current_b = stack_b;
		save_move(current_a, current_b, check);
	}
	else if (check->move_min > current_min)
	{
		check->move_min = current_min;
		current_a = stack_a;
		current_b = stack_b;
		save_move(current_a, current_b, check);
	}
}
