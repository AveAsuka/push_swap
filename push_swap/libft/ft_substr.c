/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:21:00 by rabderus          #+#    #+#             */
/*   Updated: 2021/11/12 23:47:46 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char
	*ft_substr_dop_two(size_t j, char const *s, size_t len, char *substring)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s[j] && k < len)
	{
		substring[i] = s[j];
		j++;
		k++;
		i++;
	}
	substring[i] = 0;
	return (substring);
}

static char
	*ft_substr_dop_one(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*substring;

	j = start;
	i = 0;
	k = 0;
	while (s[start] && k < len)
	{
		start++;
		i++;
		k++;
	}
	substring = (char *) malloc((i + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	return (ft_substr_dop_two(j, s, len, substring));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (s == NULL || len < 0)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	return (ft_substr_dop_one(s, start, len));
}
