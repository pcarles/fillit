/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:43:30 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/24 10:12:33 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void	print(t_tetri *list)
{
	while (list)
	{
		printf("%i: ", list->tetri_index);
		printf("%x    width: %i  |  height: %i\n", list->shape, list->width, list->height);
		list = list->next;
	}
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
	print(lol);
	exit(EXIT_SUCCESS);
}
