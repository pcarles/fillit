/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:25:58 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/28 11:19:09 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

const uint16_t	g_pattern[19] = {
	0xe800,
	0x88c0,
	0xe200,
	0xc880,
	0x4e00,
	0xe400,
	0xf000,
	0x8888,
	0x4c40,
	0x8c80,
	0xc600,
	0x6c00,
	0x4c80,
	0x8c40,
	0xcc00,
	0xc440,
	0x44c0,
	0x2e00,
	0x8e00
};

static int	is_valid(uint16_t shape)
{
	int			i;

	i = 0;
	while ((shape ^ g_pattern[i]) != 0 && i <= 18)
		i++;
	if ((shape ^ g_pattern[i]) == 0)
		return (1);
	return (0);
}

static int	get_height(uint16_t shape)
{
	int			i;
	uint16_t	mask;

	i = 5;
	mask = 0x000f;
	while (i--)
	{
		if ((shape & mask) != 0)
			return (i);
		mask <<= 4;
	}
	return (i);
}

static int	get_width(uint16_t shape)
{
	int			i;
	uint16_t	mask;

	i = 5;
	mask = 0x1111;
	while (i--)
	{
		if ((shape & mask) != 0)
			return (i);
		mask <<= 1;
	}
	return (1);
}

void		check(t_tetri *lst)
{
	while (lst)
	{
		if (!(is_valid(lst->shape)))
			return_error("bad tetrmino fdp");
		lst->height = get_height(lst->shape);
		lst->width = get_width(lst->shape);
		lst = lst->next;
	}
}
