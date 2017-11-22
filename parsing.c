/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:04:42 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/22 10:17:44 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static uint16_t	top_left(uint16_t shape)
{
	while ((shape & 0xF000) == 0)
		shape = shape << 4;
	while ((shape & 0x8888) == 0)
		shape = shape << 1;
	return (shape);
}

static uint16_t	new_shape(char *shape)
{
	uint16_t	res;
	int			i;
	int			j;

	res = 0;
	i = 0;
	j = TETRI_SIZE - 2;
	while (j >= 0)
	{
		if (shape[j] == CHAR_BLOCK)
			res += ft_pow(2, i);
		if (shape[j] != '\n')
			i++;
		j--;
	}
	return (top_left(res));
}

static t_tetri	*new_tetri(char *shape, int index, t_tetri *next)
{
	t_tetri	*new;

	if (!(new = ft_memalloc(sizeof(*new))))
		return_error("malloc failed ԅ(≖‿≖ԅ)");
	new->tetri_index = index;
	new->shape = new_shape(shape);
	new->next = next;
	return (new);
}

static int		check_tetri(char *tetri)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < TETRI_HEIGHT)
	{
		while (tetri[i] == CHAR_EMPTY || tetri[i] == CHAR_BLOCK)
			i++;
		if ((i + 1) % (TETRI_WIDTH + 1) == 0 && tetri[i] == '\n')
		{
			i++;
			j++;
		}
		else
			return_error("bad tetri format");
	}
	if (tetri[i] == '\n' || tetri[i] == '\0')
		return (1);
	else
	{
		return_error("bad tetri format or double \\n");
		return (0);
	}
}

t_tetri			*parse(char *buf)
{
	int		i;
	t_tetri	*new;

	new = NULL;
	i = 0;
	while (*buf)
	{
		if (check_tetri(buf))
		{
			new = new_tetri(buf, i, new);
			buf += TETRI_SIZE + 1;
			i++;
		}
		else
			return_error("bad format");
	}
	return (new);
}
