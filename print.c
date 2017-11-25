/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:10:02 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/25 18:24:35 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	free_res(char **map, int size)
{
	while (size--)
		free(map[size]);
	free(map);
}

static void	output(char **map)
{
	while (*map)
	{
		ft_putstr(*map);
		ft_putchar('\n');
		map++;
	}
}

static void	put_tetri(t_tetri *tetri, char **map)
{
	int			x;
	int			y;
	uint16_t	mask;

	mask = 0x8000;
	x = tetri->pos_x;
	y = tetri->pos_y;
	while (y < tetri->pos_y + TETRI_HEIGHT)
	{
		while (x < tetri->pos_x + TETRI_WIDTH)
		{
			if ((tetri->shape & mask) != 0)
				map[y][x] = tetri->tetri_index + 'A';
			mask >>= 1;
			x++;
		}
		x = tetri->pos_x;
		y++;
	}
}

void		print(t_tetri *lst, int size)
{
	char	**res;
	int		i;

	i = size;
	if (!(res = ft_memalloc(sizeof(*res) * (size + 1))))
		return_error("malloc failed");
	while (i--)
	{
		if (!(res[i] = ft_strnew(size)))
			return_error("malloc failed");
		ft_memset(res[i], '.', size);
	}
	while (lst)
	{
		put_tetri(lst, res);
		lst = lst->next;
	}
	output(res);
	free_res(res, size);
}
