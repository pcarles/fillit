/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:11:18 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/09 09:28:59 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int c, size_t n)
{
	unsigned char	*p_uc;
	unsigned char	c_uc;

	p_uc = (unsigned char *)p;
	c_uc = (unsigned char)c;
	while (n--)
	{
		*p_uc = c_uc;
		p_uc++;
	}
	return (p);
}
