/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:28:13 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/10 13:41:17 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	unsigned char	*dst_uc;
	unsigned char	*src_uc;
	unsigned char	c_uc;

	dst_uc = (unsigned char *)dst;
	src_uc = (unsigned char *)src;
	c_uc = (unsigned char)c;
	while (n--)
	{
		if (*src_uc == c_uc)
		{
			*dst_uc = *src_uc;
			return ((void *)++dst_uc);
		}
		*dst_uc = *src_uc;
		dst_uc++;
		src_uc++;
	}
	return (NULL);
}
