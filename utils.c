/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:58:10 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/28 11:36:05 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	return_error(char *msg)
{
	if (msg && DEBUG)
	{
		ft_putstr("error: ");
		ft_putendl(msg);
	}
	else
		ft_putendl("error");
	exit(EXIT_SUCCESS);
}

void	return_usage(void)
{
	ft_putendl("usage: ./fillit fillit_file");
	exit(EXIT_SUCCESS);
}

void	reset_pos(t_tetri *lst)
{
	while (lst)
	{
		lst->pos_x = 0;
		lst->pos_y = 0;
		lst = lst->next;
	}
}
