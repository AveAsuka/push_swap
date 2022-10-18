/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:59:49 by rabderus          #+#    #+#             */
/*   Updated: 2022/04/22 22:48:50 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *buf;
	
	if (!(*lst))
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	buf = ft_lstlast(*lst); // было - ft_lstlast(*lst)->next = new;
	buf->next = new;
}
