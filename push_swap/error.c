/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:37:50 by rabderus          #+#    #+#             */
/*   Updated: 2022/05/04 18:52:33 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stek_cheack_error(void)
{
	write(1, "Error.\n", 8);
	return (-1);
}

int	flag_error(char **a, t_list *stack_a, int l)
{
	write(1, "Error.\n", 8);
	mem_free(a[l]);
	free(a);
	free_stack(&stack_a);
	return (0);
}

int	empty_error(char **a, t_list *stack_a, int l)
{
	int	x;

	write(1, "Error.\n", 8);
	free_stack(&stack_a);
	if (a && (&*a[l]))
	{
		x = 0;
		while (&*a[x])
		{
			mem_free(a[l]);
			free(a);
			x++;
		}
	}
	return (0);
}
