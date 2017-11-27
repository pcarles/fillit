/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:43:30 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/27 18:10:15 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			main(int ac, char **av)
{
	t_tetri		*lst;
	t_map		*map;

	if (ac != 2)
		return_usage();
	lst = parse(put_in_buf(av[1]));
	check(lst);
	map = init_map(lst);
	while (!solve(map, lst))
	{
		reset_pos(lst);
		map->size++;
	}
	print(lst, map->size);
	exit(EXIT_SUCCESS);
}
