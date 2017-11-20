/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:13:38 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/14 13:54:29 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbfields(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s)
				s++;
			i++;
		}
		if (*s)
			s++;
	}
	return (i);
}

static int	ft_fieldlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s != c && *s)
	{
		s++;
		i++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	i = ft_nbfields(s, c);
	res = (char **)ft_memalloc(sizeof(char *) * (i + 1));
	if (!res)
		return (NULL);
	while (i--)
	{
		while (*s == c)
			s++;
		res[j] = ft_strsub(s, 0, ft_fieldlen(s, c));
		if (!res[j])
			return (NULL);
		s += ft_fieldlen(s, c);
		j++;
	}
	res[j] = NULL;
	return (res);
}
