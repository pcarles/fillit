/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:58:10 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/27 17:39:28 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	return_error(char *msg)
{
	if (msg && DEBUG)
	{
		ft_putstr_fd("error: ", 1);
		ft_putendl_fd(msg, 1);
	}
	else
		ft_putendl_fd("error", 1);
	exit(EXIT_FAILURE);
}

void	return_usage(void)
{
	ft_putendl_fd("usage: ./fillit fillit_file", 1);
	exit(EXIT_FAILURE);
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
