/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_comand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:53:23 by rabderus          #+#    #+#             */
/*   Updated: 2022/05/06 16:50:18 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	do_comand_four_sorry(t_list **stack_a, t_list **stack_b, char *comand)
{
	if (ft_strcmp(comand, "pa") == 0)
	{
		if (!(*stack_b))
			;
		else
			stack_p(stack_b, stack_a);
	}
	else if (ft_strcmp(comand, "rrr") == 0)
	{
		*stack_a = stack_rr(stack_a);
		if (!(*stack_b))
			;
		else
			*stack_b = stack_rr(stack_b);
	}
	else
		return (0);
	return (1);
}

int	do_comand_three(t_list **stack_a, t_list **stack_b, char *comand)
{
	if (ft_strcmp(comand, "ss") == 0)
	{
		*stack_a = stack_s(stack_a);
		if (!(*stack_b))
			;
		else
			*stack_b = stack_s(stack_b);
	}
	else if (ft_strcmp(comand, "rr") == 0)
	{
		*stack_a = stack_r(stack_a);
		if (!(*stack_b))
			;
		else
			*stack_b = stack_r(stack_b);
	}
	else
		return (0);
	return (1);
}

int	do_comand_two(t_list **stack_a, t_list **stack_b, char *comand)
{
	if (ft_strcmp(comand, "ra") == 0)
		*stack_a = stack_r(stack_a);
	else if (ft_strcmp(comand, "rb") == 0)
	{
		if (!(*stack_b))
			;
		else
			*stack_b = stack_r(stack_b);
	}
	else if (ft_strcmp(comand, "rra") == 0)
		*stack_a = stack_rr(stack_a);
	else if (ft_strcmp(comand, "rrb") == 0)
	{
		if (!(*stack_b))
			;
		else
			*stack_b = stack_rr(stack_b);
	}
	else
		return (0);
	return (1);
}

int	do_comand(t_list **stack_a, t_list **stack_b, char *comand)
{
	if (ft_strcmp(comand, "sa") == 0)
		*stack_a = stack_s(stack_a);
	else if (ft_strcmp(comand, "sb") == 0)
	{
		if (!(*stack_b))
			;
		else
			*stack_b = stack_s(stack_b);
	}
	else if (ft_strcmp(comand, "pb") == 0)
	{
		if (!(*stack_b))
			*stack_b = first_b(stack_a);
		else
			stack_p(stack_a, stack_b);
	}
	else if (do_comand_two(stack_a, stack_b, comand) == 1)
		return (1);
	else if (do_comand_three(stack_a, stack_b, comand) == 1)
		return (1);
	else if (do_comand_four_sorry(stack_a, stack_b, comand) == 1)
		return (1);
	else
		return (0);
	return (1);
}
