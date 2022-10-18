/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:41:07 by rabderus          #+#    #+#             */
/*   Updated: 2021/11/08 20:05:25 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t		i;
	const char	nl = '\n';

	if (s == NULL)
		return ;
	i = ft_strlen(s);
	if (write(fd, s, i) == -1)
		return ;
	write (fd, &nl, 1);
}
