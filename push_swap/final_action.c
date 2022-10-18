/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:38:31 by rabderus          #+#    #+#             */
/*   Updated: 2022/05/06 16:18:37 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	final_sort_two(t_list **stack_a, int i)
{
	while (stack_a && *stack_a)
	{
		if ((*stack_a)->rank == 0)
			break ;
		i++;
		if ((*stack_a)->next)
			*stack_a = (*stack_a)->next;
		else
			break ;
	}
	return (i);
}

void	final_sort_three(int j, t_list **stack_a)
{
	while (j != 0)
	{
		*stack_a = stack_rr(stack_a);
		write (1, "rra\n", 4);
		j--;
	}
}

void	final_sort(t_list **stack_a, t_num *check)
{
	t_list	*first_elem_a;
	int		i;
	int		j;

	i = 0;
	check->length_a = ft_lstsize(*stack_a) - 1;
	first_elem_a = *stack_a;
	i = final_sort_two(stack_a, i);
	*stack_a = first_elem_a;
	j = check->length_a - i + 1;
	if (j > i)
	{
		while (i != 0)
		{
			*stack_a = stack_r(stack_a);
			write (1, "ra\n", 3);
			i--;
		}
	}
	else
		final_sort_three(j, stack_a);
	free_stack (stack_a);
}
