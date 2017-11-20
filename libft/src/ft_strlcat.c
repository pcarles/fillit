/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:37:25 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/15 09:12:57 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	i;
	size_t	end;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[i] && i < size)
		i++;
	end = i;
	while (i < size - 1 && src[i - end])
	{
		dst[i] = src[i - end];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	return (end + ft_strlen(src));
}
