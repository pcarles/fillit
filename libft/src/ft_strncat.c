/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:41:01 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/10 11:19:19 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, char const *src, size_t n)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(dst);
	while (*src && j < n)
	{
		dst[i++] = *src;
		src++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
