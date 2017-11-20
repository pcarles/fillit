/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:44:26 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/11 13:06:15 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *haystack, char const *needle)
{
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
		{
			return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
