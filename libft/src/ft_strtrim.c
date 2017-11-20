/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:34:34 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/13 13:44:28 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*p;
	size_t	i;

	if (s)
	{
		while (*s == ' ' || *s == '\t' || *s == '\n')
			s++;
		if (*s == '\0')
			return (ft_strnew(0));
		i = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i--;
		i++;
		p = ft_strnew(i);
		if (p)
		{
			ft_strncpy(p, s, i);
			p[i] = '\0';
		}
		return (p);
	}
	return (NULL);
}
