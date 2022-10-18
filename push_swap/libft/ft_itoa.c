/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:23:26 by rabderus          #+#    #+#             */
/*   Updated: 2021/11/11 20:44:42 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_leng(int n)
{
	int	lenght;

	lenght = 0;
	if (n < 0)
	{
		lenght++;
		n = n * (-1);
	}
	while (n / 10 != 0)
	{
		lenght++;
		n = n / 10;
	}
	lenght++;
	return (lenght);
}

static char	*save_refund(int lenght, int i, int n, char *vozvrat)
{
	int	l;
	int	m;

	if (n < 0)
	{
		vozvrat[0] = '-';
		i++;
		lenght = (lenght - 1);
		n = n * (-1);
	}
	while (lenght > 0)
	{
		l = 1;
		m = 1;
		while (lenght > l)
		{
			m = m * 10;
			l++;
		}
		vozvrat[i] = (n / m) + '0';
		n = n % m;
		i++;
		lenght--;
	}
	return (vozvrat);
}

char	*ft_itoa(int n)
{
	int		lenght;
	int		i;
	char	*vozvrat;

	lenght = count_leng(n);
	i = 0;
	vozvrat = (char *)malloc((lenght + 1) * sizeof(char));
	if (!vozvrat)
		return (NULL);
	vozvrat[lenght] = '\0';
	if (n == -2147483648)
	{
		vozvrat[0] = '-';
		vozvrat[1] = 2 + '0';
		i = i + 2;
		lenght = (lenght - 2);
		n = 147483648;
	}
	return (save_refund(lenght, i, n, vozvrat));
}
