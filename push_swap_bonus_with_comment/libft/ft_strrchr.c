/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:51:40 by rabderus          #+#    #+#             */
/*   Updated: 2021/11/09 21:59:34 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	d;
	int		i;

	d = (char)c;
	if (!s)
		return (NULL);
	i = ft_strlen((char *)s) - 1;
	if (c == '\0')
		return ((char *)s + i + 1);
	while (i >= 0)
	{
		if (s[i] == d)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
