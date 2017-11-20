/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 15:04:42 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/20 15:59:09 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*new_shape(char *shape)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(new = ft_strnew(TETRI_WIDTH * TETRI_HEIGHT)))
		return_error("malloc failed ԅ(≖‿≖ԅ)");
	while (i < TETRI_SIZE)
	{
		new[j] = shape[i];
		i++;
		j++;
		if (shape[i] == '\n')
			i++;
	}
	return (new);
}

static t_tetri	*new_tetri(char *shape, char c, t_tetri *next)
{
	t_tetri	*new;

	if (!(new = ft_memalloc(sizeof(*new))))
		return_error("malloc failed ԅ(≖‿≖ԅ)");
	new->character = c;
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
			new = new_tetri(buf, i + 'A', new);
			buf += TETRI_SIZE + 1;
			i++;
		}
		else
			return_error("bad format");
	}
	return (new);
}
