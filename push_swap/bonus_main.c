/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:35:22 by rabderus          #+#    #+#             */
/*   Updated: 2022/05/06 18:16:11 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	bonus_end(t_list *stack_a)
{
	stek_cheack_error();
	free_stack(&stack_a);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	char	**a;
	t_num	check;
	t_list	*stack_a;
	t_list	*first_elem;

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
	first_elem = stack_a;
	check.flag = 1;
	if (stek_cheack_bonus(&stack_a, &check) == -1)
		return (bonus_end(stack_a));
	read_instructions(&first_elem);
	return (0);
}
