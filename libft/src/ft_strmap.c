/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:03:03 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/13 12:08:45 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*p;
	int		i;

	i = 0;
	if (s && f)
	{
		p = ft_strnew(ft_strlen(s));
		if (p)
		{
			while (*s)
			{
				p[i] = f(*s);
				i++;
				s++;
			}
			return (p);
		}
	}
	return (NULL);
}
