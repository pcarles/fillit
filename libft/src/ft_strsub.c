/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:18:07 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/13 12:05:12 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t n)
{
	char	*p;
	int		i;

	i = 0;
	if (s)
	{
		p = ft_strnew(n);
		if (p)
		{
			while (n--)
			{
				p[i++] = s[start++];
			}
		}
		return (p);
	}
	return (NULL);
}
