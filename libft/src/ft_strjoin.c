/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:28:05 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/13 12:06:13 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		i;

	i = 0;
	if (s1 && s2)
	{
		p = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (p)
		{
			while (*s1)
			{
				p[i++] = *s1;
				s1++;
			}
			while (*s2)
			{
				p[i++] = *s2;
				s2++;
			}
		}
		return (p);
	}
	return (NULL);
}
