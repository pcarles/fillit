/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:43:30 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/22 14:33:47 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void	print(t_tetri *list)
{
	while (list)
	{
		printf("%i: ", list->tetri_index);
		printf("%x\n", list->shape);
		list = list->next;
	}
}

int			main(int ac, char **av)
{
	t_tetri		*lol;
	if (ac != 2)
		return_usage();
	lol = parse(put_in_buf(av[1]));
	print(lol);
	printf("valide? %i\n", check(lol));
	exit(EXIT_SUCCESS);
}
