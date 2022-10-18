/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:39:53 by rabderus          #+#    #+#             */
/*   Updated: 2022/05/06 18:12:16 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_elem(t_list *stack_a)
{
	stack_a = stack_s(&stack_a);
	write (1, "sa\n", 3);
}

int	end(t_list	*stack_a)
{
	free_stack(&stack_a);
	return (0);
}

int	inilaize(t_num *check)
{
	check->flag = 1;
	return (1);
}

int	perebor_two(int i, char **a)
{
	i++;
	free(a);
	return (i);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**a;
	t_num	check;
	t_list	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		return (0);
	i = inilaize(&check);
	while (argc > i)
	{
		a = ft_split(argv[i], ' ');
		if (perebor(a, &stack_a, &check) == 0)
			return (0);
		i = perebor_two(i, a);
	}
	check.flag = 1;
	if (ft_lstsize(stack_a) == 2
		&& (stack_a)->content > (stack_a)->next->content)
		two_elem(stack_a);
	else if (ft_lstsize(stack_a) == 1 || stek_cheack(&stack_a, &check) == -1)
		return (end(stack_a));
	else
		transfer_a_to_b(&stack_a, &check);
	return (end(stack_a));
}
