/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_read_ins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:36:05 by rabderus          #+#    #+#             */
/*   Updated: 2022/05/06 18:14:16 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	not_sorted(t_list **stack_a)
{
	while (stack_a && *stack_a && (*stack_a)->next)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			return (0);
		*stack_a = (*stack_a)->next;
	}
	return (1);
}

int	length_instructions(char (*comand)[5])
{
	int		size;
	char	symbol[2];

	*comand[0] = '\0';
	size = read(0, symbol, 1);
	symbol[1] = '\0';
	while (size == 1 && symbol[0] != '\n')
	{
		ft_strlcat(*comand, symbol, 5);
		size = read(0, symbol, 1);
	}
	return (size);
}

void	comand_enter(t_list	**stack_a, t_list *stack_b)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(&stack_b);
	free_stack(&stack_b);
	stek_cheack_error();
	return ;
}

void	read_instructions(t_list **stack_a)
{
	t_list	*stack_b;
	char	comand[5];
	int		size;
	t_list	*first_elem;

	stack_b = NULL;
	size = length_instructions(&comand);
	while (size == 1)
	{
		if (do_comand(stack_a, &stack_b, comand) == 0)
			return (comand_enter(stack_a, stack_b));
		size = length_instructions(&comand);
	}
	first_elem = *stack_a;
	if (ft_lstsize(stack_b) > 0 || not_sorted(stack_a) == 0)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	if (stack_a)
		free_stack(&first_elem);
	if (stack_b)
		free_stack(&stack_b);
}
