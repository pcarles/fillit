/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:27:56 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/28 10:57:29 by pcarles          ###   ########.fr       */
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
# define DEBUG 			0

typedef struct		s_tetri
{
	uint16_t		shape;
	int				tetri_index;
	int				width;
	int				height;
	int				pos_x;
	int				pos_y;
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_map
{
	int				size;
	uint16_t		map[16];
}					t_map;

int					main(int ac, char **av);
void				return_error(char *msg);
void				return_usage(void);
char				*put_in_buf(char *file_path);
t_tetri				*parse(char *buf);
void				check(t_tetri *lst);
t_map				*init_map(t_tetri *lst);
void				print(t_tetri *lst, int size);
int					solve(t_map *map, t_tetri *tetri);
void				reset_pos(t_tetri *lst);
void				free_all(t_tetri *lst, t_map *map);

#endif
