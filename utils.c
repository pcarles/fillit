/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:58:10 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/18 16:13:18 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	return_error(char *msg)
{
	if (msg && DEBUG)
	{
		ft_putendl_fd("\
 _____ ___ _     _     ___ _____ \n\
|  ___|_ _| |   | |   |_ _|_   _|\n\
| |_   | || |   | |    | |  | |  \n\
|  _|  | || |___| |___ | |  | |  \n\
|_|   |___|_____|_____|___| |_|\n\
              error\n", 1);
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
