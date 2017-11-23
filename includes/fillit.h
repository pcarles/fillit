/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:27:56 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/23 10:39:49 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>

# define CHAR_EMPTY		'.'
# define CHAR_BLOCK		'#'
# define TETRI_WIDTH	4
# define TETRI_HEIGHT	4
# define TETRI_SIZE		((TETRI_WIDTH + 1) * TETRI_HEIGHT)
# define TETRI_MAX		26
# define MAXBUF_SIZE	((TETRI_SIZE + 1) * TETRI_MAX) - 1
# define DEBUG 			1

typedef struct		s_tetri
{
	uint16_t		shape;
	int				tetri_index;
	struct s_tetri	*next;
}					t_tetri;

int					main(int ac, char **av);
void				return_error(char *msg);
void				return_usage(void);
char				*put_in_buf(char *file_path);
t_tetri				*parse(char *buf);
void				check(t_tetri *lst);

#endif
