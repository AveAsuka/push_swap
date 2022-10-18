/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:32:56 by rabderus          #+#    #+#             */
/*   Updated: 2021/11/10 14:10:38 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		
	*ft_strnstr_dop(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l;
	size_t	j;
	size_t	k_len;
	size_t	n_len;

	i = 0;
	k_len = 0;
	while (haystack[i] && len > k_len)
	{
		l = i;
		j = 0;
		n_len = k_len;
		while (needle[j] && haystack[l] == needle[j] && len > n_len)
		{
			l++;
			j++;
			n_len++;
		}
		if (!needle[j])
			return ((char *)haystack + k_len);
		i++;
		k_len++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (haystack == NULL || needle == NULL)
		return (NULL);
	if (ft_strlen(needle) == 0 || needle == haystack)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	return (ft_strnstr_dop(haystack, needle, len));
}
