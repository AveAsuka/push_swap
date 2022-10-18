/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:30:12 by rabderus          #+#    #+#             */
/*   Updated: 2022/02/10 23:07:46 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	uns_char(char s1, char s2)
{
	if ((unsigned char)s1 != (unsigned char)s2)
		return ((unsigned char)s1 - (unsigned char)s2);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && n > i)
	{
		if (uns_char(s1[i], s2[i]))
		{
			if (uns_char(s1[i], s2[i]))
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (n > i)
		return (uns_char(s1[i], s2[i]));
	return (0);
}
