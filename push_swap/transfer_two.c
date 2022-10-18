/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transfer_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:27:47 by rabderus          #+#    #+#             */
/*   Updated: 2022/05/06 22:30:47 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*a_sort(t_list **lst)
{
	int	first;
	int	second;
	int	third;

	first = (*lst)->content;
	second = (*lst)->next->content;
	third = (*lst)->next->next->content;
	if (second > third && second > first && third > first)
	{
		*lst = stack_s(lst);
		write(1, "sa\n", 3);
	}
	if (third > first && third > second && first > second)
	{
		*lst = stack_s(lst);
		write(1, "sa\n", 3);
	}
	if (first > third && first > second && second > third)
	{
		*lst = stack_s(lst);
		write(1, "sa\n", 3);
	}
	return (*lst);
}

void	bubblesort(int *num, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < (size - 1))
	{
		j = (size - 1);
		while (j > i)
		{
			if (num[j - 1] > num[j])
			{
				temp = num[j - 1];
				num[j - 1] = num[j];
				num[j] = temp;
			}
			j--;
		}
		i++;
	}
}

void	ranks_dis(int *num, t_list **lst, t_num *check)
{
	int		i;
	int		j;

	while (lst && *lst)
	{
		i = check->length;
		j = 0;
		while (i != 0)
		{
			if ((*lst)->content == num[j])
			{
				(*lst)->rank = j;
				break ;
			}
			i--;
			j++;
		}
		if ((*lst)->next)
			*lst = (*lst)->next;
		else
			break ;
	}
}

t_list	**find_trio(t_list **lst, t_num *check)
{
	int		i;
	int		j;
	int		*a;
	t_list	*first_elem;

	first_elem = *lst;
	a = malloc(sizeof(int) * check->length);
	i = 0;
	while (lst && *lst && (*lst)->next)
	{
		a[i++] = (*lst)->content;
		*lst = (*lst)->next;
	}
	a[i] = (*lst)->content;
	j = i + 1;
	bubblesort (a, j);
	*lst = first_elem;
	ranks_dis (a, lst, check);
	check->min = a[0];
	check->mean = a[j / 2];
	check->max = a[j - 1];
	*lst = first_elem;
	free (a);
	return (lst);
}
