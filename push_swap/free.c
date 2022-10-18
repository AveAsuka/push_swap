/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:38:59 by rabderus          #+#    #+#             */
/*   Updated: 2022/05/06 18:11:15 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_p(t_list **head_from, t_list **head_to)
{
	t_list	*p;
	t_list	*p2;

	if (!head_from)
		return ;
	if (head_from)
	{
		p = *head_to;
		p2 = *head_from;
		(*head_from) = (*head_from)->next;
		*head_to = p2;
		(*head_to)->next = p;
	}
}

t_list	*first_b(t_list **lst)
{
	t_list	*p;

	p = *lst;
	(*lst) = (*lst)->next;
	p->next = NULL;
	return (p);
}

void	mem_free(char *a)
{
	free(a);
	a = NULL;
}

void	free_stack(t_list **head)
{
	t_list	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		tmp = NULL;
	}
}
