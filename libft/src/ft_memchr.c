/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:47:05 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/09 17:43:19 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned char	c_uc;
	unsigned char	*s_uc;

	c_uc = (unsigned char)c;
	s_uc = (unsigned char *)s;
	while (n--)
	{
		if (*s_uc == c_uc)
			return (s_uc);
		s_uc++;
	}
	return (NULL);
}
