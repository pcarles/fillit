/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:34:48 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/10 11:19:47 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, char const *src)
{
	size_t	i;

	i = ft_strlen(dst);
	while (*src)
	{
		dst[i++] = *src;
		src++;
	}
	dst[i] = '\0';
	return (dst);
}
