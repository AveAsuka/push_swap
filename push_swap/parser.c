/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:39:33 by rabderus          #+#    #+#             */
/*   Updated: 2022/05/04 18:41:09 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_elem(t_list *tmp, int d, t_list **stack_a)
{
	tmp = ft_lstnew(d);
	ft_lstadd_back(stack_a, tmp);
}

int	perebor(char **a, t_list **stack_a, t_num *check)
{
	int		l;
	int		d;
	t_list	*tmp;

	tmp = NULL;
	l = 0;
	d = 0;
	if (a == NULL || (*a) == NULL)
		return (empty_error(a, *stack_a, l));
	while (&*a[l])
	{
		d = fatoi(&*a[l], check);
		if (check->flag == 0)
			return (flag_error(a, *stack_a, l));
		else
		{
			if (!stack_a)
				(*stack_a) = ft_lstnew(d);
			else
				new_elem(tmp, d, stack_a);
		}
		mem_free (a[l]);
		l++;
	}
	return (1);
}
