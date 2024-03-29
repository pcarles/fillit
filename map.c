/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 10:00:52 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/27 15:53:36 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	sqrt(int nb)
{
	int i;

	i = 0;
	while (i * i < nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i);
}

static int	get_map_size(t_tetri *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	i *= 4;
	return (sqrt(i));
}

t_map		*init_map(t_tetri *lst)
{
	int		i;
	t_map	*map;

	i = 0;
	if (!(map = ft_memalloc(sizeof(*map))))
		return_error("malloc failed");
	map->size = get_map_size(lst);
	while (i < 16)
	{
		ft_bzero(&map->map[i], sizeof(map->map[0]));
		i++;
	}
	return (map);
}
