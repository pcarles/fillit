/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:35:58 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/12 20:12:06 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int		len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int				len;
	unsigned int	n_ui;
	char			*p;

	len = ft_nbrlen(n);
	n_ui = n;
	p = ft_strnew(len);
	if (p)
	{
		if (n < 0)
		{
			n_ui = -n;
			*p = '-';
		}
		len--;
		while (len > 0)
		{
			p[len--] = n_ui % 10 + '0';
			n_ui /= 10;
		}
		if (*p != '-')
			*p = n_ui + '0';
	}
	return (p);
}
