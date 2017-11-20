/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:55:24 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/09 19:02:44 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void const *s1, void const *s2, size_t n)
{
	unsigned char	*s1_uc;
	unsigned char	*s2_uc;

	s1_uc = (unsigned char *)s1;
	s2_uc = (unsigned char *)s2;
	if (!n)
		return (0);
	while (--n && *s1_uc == *s2_uc)
	{
		s1_uc++;
		s2_uc++;
	}
	return (*s1_uc - *s2_uc);
}
