/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:25:21 by pcarles           #+#    #+#             */
/*   Updated: 2017/11/20 15:33:48 by pcarles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		open_file(char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return_error("open failed (╯°□°）╯︵ ┻━┻");
	return (fd);
}

static int		read_file(int fd, char *buf)
{
	int		count;

	ft_bzero(buf, MAXBUF_SIZE + 1);
	count = read(fd, buf, MAXBUF_SIZE);
	if (count == -1)
		return_error("read failed ¯\\_(ツ)_/¯");
	return (count);
}

static void		pre_check(int count, char *buf)
{
	if (((count + 1) % (TETRI_SIZE + 1)) != 0)
		return_error("bad file size");
	while (*buf)
	{
		if (*buf != CHAR_EMPTY && *buf != CHAR_BLOCK && *buf != '\n')
			return_error("bad character in file t(-_-t)");
		buf++;
	}
}

char			*put_in_buf(char *file_path)
{
	int		fd;
	char	*buf;
	int		count;

	if (!(buf = ft_memalloc(MAXBUF_SIZE + 1)))
		return_error("malloc of buffer failed");
	fd = open_file(file_path);
	count = read_file(fd, buf);
	pre_check(count, buf);
	close(fd);
	return (buf);
}
