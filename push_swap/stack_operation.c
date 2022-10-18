/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:42:16 by rabderus          #+#    #+#             */
/*   Updated: 2022/05/06 18:11:10 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*stack_s(t_list **lst)
{
	t_list	*first_elem;
	t_list	*second_elem;

	if (!lst)
		return (NULL);
	if (!(*lst)->next)
		return (*lst);
	first_elem = (*lst);
	second_elem = (*lst)->next;
	first_elem->next = second_elem->next;
	second_elem->next = first_elem;
	(*lst) = second_elem;
	return (*lst);
}

t_list	*stack_r(t_list **lst)
{
	t_list	*first_elem;
	t_list	*second_elem;

	if (!lst)
		return (NULL);
	if (!(*lst)->next)
		return (*lst);
	first_elem = (*lst);
	second_elem = (*lst)->next;
	while (lst && *lst && (*lst)->next)
		lst = &(*lst)->next;
	(*lst)->next = first_elem;
	first_elem->next = NULL;
	lst = NULL;
	return (second_elem);
}

t_list	*stack_rr_two_elem(t_list **lst)
{
	t_list	*first_elem;
	t_list	*last_elem;

	first_elem = (*lst);
	last_elem = (*lst)->next;
	last_elem->next = first_elem;
	first_elem->next = NULL;
	return (last_elem);
}

void	stack_rr_else(t_list **lst, t_list **penultimate)
{
	while (lst && *lst && (*lst)->next && (*lst)->next->next)
	{
		*penultimate = (*lst)->next;
		*lst = (*lst)->next;
	}
}

t_list	*stack_rr(t_list **lst)
{
	t_list	*first_elem;
	t_list	*last_elem;
	t_list	*penultimate;

	first_elem = (*lst);
	if ((*lst)->next && (*lst)->next->next)
		stack_rr_else(lst, &penultimate);
	else
		return (stack_rr_two_elem(lst));
	last_elem = (*lst)->next;
	last_elem->next = first_elem;
	penultimate->next = NULL;
	return (last_elem);
}
