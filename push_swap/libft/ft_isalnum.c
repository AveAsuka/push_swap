/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:17:20 by rabderus          #+#    #+#             */
/*   Updated: 2021/11/11 20:43:21 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int ch)
{
	if ((ch >= 'A' && ch <= 'Z')
		|| (ch >= 'a' && ch <= 'z')
		|| (ch >= '0' && ch <= '9'))
		return (1);
	return (0);
}
