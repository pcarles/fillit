/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:32:53 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/24 15:27:44 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	put_shape(uint16_t map, uint16_t tetri)
{
	if ((map && tetri) == 0)
	{
		map |= tetri;
		return (1);
	}
	return (0);
}

int			set(t_map *map, t_tetri *tetri)
{
	int		index;
	int		x;
	int		y;

	if ((tetri->pos_x + tetri->width) > map->size)
		return (0);
	if ((tetri->pos_y + tetri->height) > map->size)
		return (0);
	index = tetri->pos_x / TETRI_WIDTH + (tetri->pos_y / TETRI_HEIGHT) * 4;
	x = tetri->pos_x % TETRI_WIDTH;
	y = tetri->pos_y % TETRI_HEIGHT;
	if (x >= tetri->width && y < TETRI_HEIGHT)
	{
		if (x == 4)
			x = 0;
		if (put_shape(map->map[index], (tetri->shape >>= x)))
			if (put_shape(map->map[index + 1], (tetri->shape <<= x)))
				return (1);
		return (0);
	}
	else if (y >= tetri->height && x < TETRI_WIDTH)
	{
		if (put_shape(map->map[index], (tetri->shape >>= (y * 4))))
			if (put_shape(map->map[index + 4], (tetri->shape <<= (y * 4))))
				return (1);
		return (0);
	}
	else
		return (0);
	printf("map index: %i\nx in index: %i\ny in index: %i\n", index, x, y);
	return (0);
}
