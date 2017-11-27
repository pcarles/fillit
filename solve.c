/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:32:53 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/27 18:46:43 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	set(t_map *map, t_tetri *tetri, int index)
{
	uint16_t	mask;

	mask = 0xf000;
	mask >>= index * TETRI_WIDTH;
	if (index == tetri->height)
		return (1);
	if (((tetri->pos_x + tetri->width) > map->size) || ((tetri->pos_y + tetri->height) > map->size))
		return (0);
	if (((((tetri->shape & mask) << (index * TETRI_HEIGHT)) >> tetri->pos_x) & map->map[tetri->pos_y + index]) != 0)
		return (0);
	else
	{
		if (set(map, tetri, index + 1))
		{
			map->map[tetri->pos_y + index] |= (((tetri->shape & mask) << (index * TETRI_HEIGHT)) >> tetri->pos_x);
			return (1);
		}
		return (0);
	}
}

int			solve(t_map *map, t_tetri *tetri)
{
	uint16_t	back[16];

	ft_memcpy(back, map->map, (sizeof(uint16_t) * 16));
	if (!tetri)
		return (1);
	while (tetri->pos_y + tetri->height <= map->size)
	{
		while (tetri->pos_x + tetri->width <= map->size)
		{
			if (set(map, tetri, 0))
			{
				reset_pos(tetri->next);
				if (solve(map, tetri->next))
					return (1);
				else
					ft_memcpy(map->map, back, (sizeof(uint16_t) * 16));
			}
			tetri->pos_x++;
		}
		tetri->pos_x = 0;
		tetri->pos_y++;
	}
	return (0);
}
