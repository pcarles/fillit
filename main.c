/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:43:30 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/27 15:37:31 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			main(int ac, char **av)
{
	t_tetri		*lol;
	t_map		*map;

	if (ac != 2)
		return_usage();
	lol = parse(put_in_buf(av[1]));
	check(lol);
	map = init_map(lol);
	while (!solve(map, lol))
		map->size++;
	print(lol, map->size);
	exit(EXIT_SUCCESS);
}
