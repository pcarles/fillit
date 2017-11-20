/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:04:45 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/10 14:57:51 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t n)
{
	unsigned char	*dst_uc;
	unsigned char	*src_uc;

	dst_uc = (unsigned char *)dst;
	src_uc = (unsigned char *)src;
	if (src > dst)
		ft_memcpy(dst, src, n);
	else
	{
		while (n--)
			dst_uc[n] = src_uc[n];
	}
	return (dst);
}
