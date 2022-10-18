/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:44:02 by rabderus          #+#    #+#             */
/*   Updated: 2022/05/06 22:29:36 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	steak_a_ra(t_list **first_elem, t_list **lst)
{
	*lst = stack_r(lst);
	write(1, "ra\n", 3);
	lst = first_elem;
}

void	transfer_a_to_b_sort(t_list **lst, t_num *check, t_list *stack_b)
{
	*lst = a_sort (lst);
	pre_sorting (lst, &stack_b, check);
	final_sort (lst, check);
}

void	lst_length(t_list **lst, t_num *check)
{
	if (*lst)
		check->length = ft_lstsize(*lst);
}

void	transfer_a_to_b(t_list **lst, t_num *check)
{
	t_list	**first_elem;
	t_list	*stack_b;

	check->length = ft_lstsize(*lst);
	lst = find_trio(lst, check);
	first_elem = lst;
	stack_b = NULL;
	while (lst && *lst)
	{
		lst_length(lst, check);
		if (check->length == 3)
			break ;
		if ((*lst)->content == check->mean
			|| (*lst)->content == check->min || (*lst)->content == check->max)
			steak_a_ra(first_elem, lst);
		else
		{
			if (!stack_b)
				stack_b = first_b(lst);
			else
				stack_p(lst, &stack_b);
			write(1, "pb\n", 3);
		}
	}
	transfer_a_to_b_sort(lst, check, stack_b);
}
