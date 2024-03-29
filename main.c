/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:43:30 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/28 11:03:39 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			main(int ac, char **av)
{
	t_tetri		*lst;
	t_map		*map;
	char		*buf;

	if (ac != 2)
		return_usage();
	buf = put_in_buf(av[1]);
	lst = parse(buf);
	free(buf);
	check(lst);
	map = init_map(lst);
	while (!solve(map, lst))
	{
		reset_pos(lst);
		map->size++;
	}
	print(lst, map->size);
	free_all(lst, map);
	exit(EXIT_SUCCESS);
}
