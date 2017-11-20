/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:41:49 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/12 16:37:53 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	unsigned char	*s1_uc;
	unsigned char	*s2_uc;

	s1_uc = (unsigned char *)s1;
	s2_uc = (unsigned char *)s2;
	if (!n)
		return (0);
	while (*s1_uc && *s2_uc && --n && *s1_uc == *s2_uc)
	{
		s1_uc++;
		s2_uc++;
	}
	return ((int)(*s1_uc - *s2_uc));
}
