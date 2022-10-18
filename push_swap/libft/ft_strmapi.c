/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 23:25:55 by rabderus          #+#    #+#             */
/*   Updated: 2021/10/27 23:29:43 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s2;

	i = 0;
	if (s == NULL)
		return (NULL);
	s2 = ft_strdup(s);
	if (!s2)
		return (NULL);
	i = 0;
	while (s2[i])
	{
		s2[i] = (*f)(i, s2[i]);
		i++;
	}
	return (s2);
}
