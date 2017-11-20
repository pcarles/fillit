/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:22:07 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/10 11:36:09 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *s, int c)
{
	unsigned char	c_uc;
	unsigned char	*s_uc;

	c_uc = (unsigned char)c;
	s_uc = (unsigned char *)s;
	while (*s_uc)
	{
		if (*s_uc == c_uc)
			return ((char *)s_uc);
		s_uc++;
	}
	if (*s_uc == c_uc)
		return ((char *)s_uc);
	return (NULL);
}
