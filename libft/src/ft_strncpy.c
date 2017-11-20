/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 09:31:51 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/14 11:35:14 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char const *src, size_t n)
{
	size_t	i;

	i = ft_strlen(src);
	if (i < n)
	{
		ft_strcpy(dst, src);
		ft_bzero((dst + i), n - i);
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
