/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   open_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/01 18:40:03 by dfreire        #+#    #+#                */
/*   Updated: 2019/03/05 16:55:11 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	open_file(char *file, char *buf)
{
	int fd;
	int ret;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret > BUFF_SIZE || ret == -1)
		return (-1);
	buf[ret] = '\0';
	if (close(fd) == -1)
		return (-1);
	return (ret);
}

static int	validate_tetriminos_list(t_tetrimino **start, char *buf)
{
	t_tetrimino	*cur;
	char		*tmp;
	int			n_tetriminos;
	int			i;

	tmp = buf;
	n_tetriminos = create_tetriminos_list(tmp, start);
	if (n_tetriminos == 0)
		return (-1);
	i = n_tetriminos;
	cur = *start;
	while (i)
	{
		if (!check_tetrimino_format(cur->tetrimino)
			|| !check_tetrimino_size(cur->tetrimino))
			return (-1);
		cur = cur->next;
		i--;
	}
	return (n_tetriminos);
}

static int	check_buf_size(char *file, char *buf)
{
	int size;

	if ((size = open_file(file, buf)) == -1)
		return (-1);
	if (!check_symbols(buf, size))
		return (-1);
	if (!validate_buffer_format(buf, size))
		return (-1);
	return (size);
}

int			allocating_tetriminos(char *file, t_tetrimino **start)
{
	int		size;
	char	*buf;
	int		n_tetriminos;

	buf = (char *)ft_memalloc(BUFF_SIZE);
	size = check_buf_size(file, buf);
	if (size == -1)
	{
		ft_memdel((void **)&buf);
		return (-1);
	}
	n_tetriminos = validate_tetriminos_list(start, buf);
	if (n_tetriminos == -1)
	{
		ft_memdel((void **)&buf);
		return (-1);
	}
	ft_memdel((void **)&buf);
	return (n_tetriminos);
}
