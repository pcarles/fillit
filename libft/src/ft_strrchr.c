/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:37:23 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/10 11:43:36 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	unsigned char	c_uc;
	unsigned char	*s_uc;
	size_t			i;

	c_uc = (unsigned char)c;
	s_uc = (unsigned char *)s;
	i = ft_strlen(s) + 1;
	while (i--)
	{
		if (s_uc[i] == c_uc)
			return ((char *)s_uc + i);
	}
	return (NULL);
}
