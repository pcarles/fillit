/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:43:30 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/20 15:59:27 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	print(t_tetri *list)
{
	while (list)
	{
		ft_putchar(list->character);
		ft_putendl(list->shape);
		list = list->next;
	}
}

int			main(int ac, char **av)
{
	if (ac != 2)
		return_usage();
	print(parse(put_in_buf(av[1])));
	exit(EXIT_SUCCESS);
}
