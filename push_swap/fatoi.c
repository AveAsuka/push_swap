/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:38:04 by rabderus          #+#    #+#             */
/*   Updated: 2022/05/04 19:14:28 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	miss_tab(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

static long long	int
	schet_itog(const char *str, int znak, int i, t_num *check)
{
	long long int	itog;

	itog = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			itog = (itog * 10) + (str[i] - '0');
		else
			check->flag = 0;
		i++;
	}
	itog = znak * itog;
	return (itog);
}

int	out(t_num *check)
{
	check->flag = 0;
	return (0);
}

int	fatoi(const char *str, t_num *check)
{
	int				i;
	int				znak;
	long long int	itog;

	i = 0;
	znak = 1;
	if (!str)
		return (out(check));
	i = miss_tab(str);
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		znak = -1;
		i++;
	}
	else if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	else if ((str[i] >= '0' && str[i] <= '9'))
		;
	else
		return (out(check));
	itog = schet_itog(str, znak, i, check);
	if (-2147483648 <= itog && itog <= 2147483647)
		return ((int)itog);
	return (out(check));
}
