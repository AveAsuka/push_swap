/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:59:07 by rabderus          #+#    #+#             */
/*   Updated: 2021/11/13 15:23:39 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void
	ft_strlcat_dop(char *dst, const char *src,
		size_t dstsize, size_t	dest_length)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(dst);
	while (src[i] && (dstsize - 1) > dest_length + i)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dest_length;
	size_t	src_length;

	dest_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (dstsize > 0 && (dstsize - 1) > dest_length)
		ft_strlcat_dop (dst, src, dstsize, dest_length);
	if (src_length == 0)
		return (dest_length);
	if (dest_length == 0)
		return (src_length);
	if (dest_length >= dstsize)
		dest_length = dstsize;
	return (dest_length + src_length);
}
