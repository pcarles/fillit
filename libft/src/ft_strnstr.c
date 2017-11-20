/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:20:21 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/11 15:18:31 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t n)
{
	size_t	i;

	i = ft_strlen(needle);
	if (i == 0)
		return ((char *)haystack);
	while (*haystack && i <= n)
	{
		if (ft_strncmp(haystack, needle, i) == 0)
		{
			return ((char *)haystack);
		}
		haystack++;
		n--;
	}
	return (NULL);
}
