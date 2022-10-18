/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:39:26 by rabderus          #+#    #+#             */
/*   Updated: 2021/11/10 14:50:44 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char
	*ft_strtrim_dop_one(size_t start, size_t end, char *mid, char const *s1)
{
	size_t	lenght;

	lenght = 0;
	while (start < end)
	{
		mid[lenght] = s1[start];
		lenght++;
		start++;
	}
	mid[lenght] = 0;
	return (mid);
}

static int	perebor_seta(char s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*mid;
	size_t	start;
	size_t	end;
	size_t	lenght;

	if (s1 == NULL || set == NULL)
		return (NULL);
	lenght = ft_strlen(s1);
	start = 0;
	while (s1[start] && perebor_seta(s1[start], set))
		start++;
	end = lenght;
	while (end > start && perebor_seta(s1[end - 1], set))
		end--;
	mid = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!mid)
		return (NULL);
	return (ft_strtrim_dop_one(start, end, mid, s1));
}
