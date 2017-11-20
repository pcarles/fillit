/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:35:00 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/13 12:02:40 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				p[i] = f(i, *s);
				i++;
				s++;
			}
			return (p);
		}
	}
	return (NULL);
}
