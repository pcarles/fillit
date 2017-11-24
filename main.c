/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:43:30 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/24 11:56:28 by bjaudall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>


static void	print(t_tetri *list, t_map *map)
{
	while (list)
	{
		printf("%i: ", list->tetri_index);
		printf("%x    width: %i  |  height: %i\n", list->shape, list->width, list->height);
		list = list->next;
	}
	printf("Taille de la map: %d\n", map->size);
}

int			main(int ac, char **av)
{
	t_tetri		*lol;
	t_map		*map;

	if (ac != 2)
		return_usage();
	lol = parse(put_in_buf(av[1]));
	check(lol);
	map = init_map(lol);
	print(lol, map);
	exit(EXIT_SUCCESS);
}
