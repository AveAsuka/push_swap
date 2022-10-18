/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabderus <rabderus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:34:08 by rabderus          #+#    #+#             */
/*   Updated: 2022/05/04 18:44:17 by rabderus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int
	ft_split_num_of_sep(char const *s, char c, t_split_list *lt)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			lt->num_of_sep++;
			while (s[i] == c)
				i++;
		}
		else if (s[i] != c)
			i++;
	}
	if (i == lt->num_of_sep || s[0] == '\0')
		return (-1);
	if (s[0] == c)
		lt->num_of_sep--;
	if (s[i - 1] == c && i != 0)
		lt->num_of_sep--;
	return (lt->num_of_sep);
}

static char	**mem_free(char **a, size_t i)
{
	free(a[i]);
	while (i != 0)
	{
		i--;
		free(a[i]);
	}
	free(a);
	return (0);
}

static char
	**split_substring(t_split_list *lt, char **a, char const *s, char c)
{
	if (lt->i + 1 == lt->end && s[lt->i] != c)
		lt->j++;
	a[lt->line] = (char *) malloc((lt->j + 1) * sizeof(char));
	if (a[lt->line] == NULL)
		mem_free (a, lt->line);
	while (s[lt->k] == c)
	{
		lt->k++;
		lt->l++;
	}
	lt->k = lt->i;
	lt->j = 0;
	while (lt->i > lt->l)
	{
		a[lt->line][lt->j] = s[lt->l];
		lt->j++;
		lt->l++;
	}
	if (lt->i + 1 == lt->end && s[lt->i] != c)
	{
		a[lt->line][lt->j] = s[lt->l];
		lt->j++;
	}
	a[lt->line][lt->j] = '\0';
	return (a);
}

static char
	**ft_split_cut_seg(char const *s, char c, char **a, t_split_list *lt)
{
	lt->end = ft_strlen(s);
	lt->i = 0;
	lt->j = 0;
	lt->line = 0;
	while (s[lt->i])
	{
		if (s[lt->i] != c && lt->i + 1 != lt->end)
		{
			lt->i++;
			lt->j++;
		}
		else if ((s[lt->i] == c || lt->i + 1 == lt->end) && lt->j > 0)
		{
			split_substring(lt, a, s, c);
			lt->j = 0;
			lt->line++;
		}
		else if (lt->i + 1 == lt->end && lt->j == 0
			&& (lt->num_of_sep + 1) > lt->line)
			lt->j++;
		else
			lt->i++;
	}
	a[lt->line] = NULL;
	return (a);
}

char	**ft_split(char const *s, char c)
{
	t_split_list	lt;
	char			**a;

	lt.l = 0;
	lt.k = 0;
	lt.num_of_sep = 0;
	if (!s)
		return (NULL);
	lt.num_of_sep = ft_split_num_of_sep(s, c, &lt);
	if (lt.num_of_sep == -1)
		return (NULL);
	a = (char **) malloc((lt.num_of_sep + 2) * sizeof(a));
	if (!a)
		return (NULL);
	a = ft_split_cut_seg(s, c, a, &lt);
	return (a);
}
