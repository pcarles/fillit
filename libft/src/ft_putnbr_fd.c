/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:43:07 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/08 17:44:20 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	tmp;

	tmp = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		tmp = -n;
	}
	if (tmp >= 10)
		ft_putnbr_fd(tmp / 10, fd);
	ft_putchar_fd((tmp % 10) + '0', fd);
}
