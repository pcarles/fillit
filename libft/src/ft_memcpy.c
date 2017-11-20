/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:26:09 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/09 11:22:22 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned char *dst_c;
	unsigned char *src_c;

	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	while (n--)
	{
		*dst_c = *src_c;
		dst_c++;
		src_c++;
	}
	return (dst);
}
