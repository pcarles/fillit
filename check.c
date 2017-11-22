/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:25:58 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/22 16:16:59 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_valid(uint16_t shape)
{
	uint16_t	val[19] = {0xe800, 0x88c0, 0xe200, 0xc880, 0x4e00, 0xe400, \
						0xf000, 0x8888, 0x4c40, 0x8c80, 0xc600, 0x6c00, \
						0x4c80, 0x8c40, 0xcc00, 0xc440, 0x44c0, 0x2e00, 0x8e00};
	int			i;

	i = 0;
	while ((shape ^ val[i]) != 0 && i <= 18)
		i++;
	if ((shape ^ val[i]) == 0)
		return (1);
	return (0);
}

int			check(t_tetri *lst)
{
	while (lst)
	{
		if(!(is_valid(lst->shape)))
			return (0);
		lst = lst->next;
	}
	return (1);
}
