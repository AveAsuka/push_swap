/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:34:05 by rabderus          #+#    #+#             */
/*   Updated: 2022/05/06 18:25:00 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perebor_b(t_list **stack_a, t_list **stack_b,
	t_list	*previus, t_num *check)
{
	while (stack_b && *stack_b)
	{
		if ((previus->rank < (*stack_b)->rank)
			&& ((*stack_b)->rank < (*stack_a)->rank))
			move_score(*stack_a, *stack_b, check);
		if ((*stack_b)->next)
			*stack_b = (*stack_b)->next;
		else
			break ;
	}
}

void	new_previus(t_list **stack_a,
		t_list	**previus, t_list **first_elem_a)
{
	while (stack_a && *stack_a)
	{
		if ((*stack_a)->next)
			*stack_a = (*stack_a)->next;
		else
			break ;
	}
	*previus = *stack_a;
	*stack_a = *first_elem_a;
}

void	pre_sorting_three(t_list **first_elem_a,
		t_list **first_elem_b, t_num *check)
{
	if (check->ra != 0 || check->rb != 0 || check->rr != 0
		|| check->rra != 0 || check->rrb != 0 || check->rrr != 0)
		realize(first_elem_a, first_elem_b, check);
	stack_p(first_elem_b, first_elem_a);
	write(1, "pa\n", 3);
}

void	perebor_a(t_list **stack_a, t_list **previus)
{
	*previus = *stack_a;
	*stack_a = (*stack_a)->next;
}

void	pre_sorting(t_list **stack_a, t_list **stack_b, t_num *check)
{
	t_list	*first_elem_a;
	t_list	*first_elem_b;
	t_list	*previus;

	previus = (*stack_a)->next->next;
	first_elem_a = *stack_a;
	first_elem_b = *stack_b;
	while (stack_b && *stack_b)
	{
		check->a = 0;
		check->length_a = ft_lstsize(*stack_a);
		check->length_b = ft_lstsize(*stack_b);
		while (stack_a && *stack_a)
		{
			*stack_b = first_elem_b;
			perebor_b(stack_a, stack_b, previus, check);
			if ((*stack_a)->next)
				perebor_a(stack_a, &previus);
			else
				break ;
		}
		pre_sorting_three(&first_elem_a, &first_elem_b, check);
		new_previus(stack_a, &previus, &first_elem_a);
		*stack_b = first_elem_b;
	}
}
