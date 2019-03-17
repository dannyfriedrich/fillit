/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_tetriminos.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/02 14:55:55 by dfreire        #+#    #+#                */
/*   Updated: 2019/03/04 10:59:27 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetrimino	*fill_list(char *buf, t_tetrimino *new)
{
	int row;
	int col;
	int i;

	i = 0;
	row = 0;
	while (buf[i] == '\n')
		buf++;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			new->tetrimino[row][col] = buf[i];
			col++;
			i++;
		}
		i++;
		row++;
	}
	return (new);
}

static t_tetrimino	*insert_new_item(char *buf)
{
	t_tetrimino	*new;
	int			i;

	new = (t_tetrimino *)ft_memalloc(sizeof(t_tetrimino));
	if (!new)
		return (NULL);
	new->tetrimino = (char **)ft_memalloc(sizeof(char *) * 4);
	if (!new->tetrimino)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		new->tetrimino[i] = ft_strnew(4);
		if (!new->tetrimino[i])
			return (NULL);
		i++;
	}
	new->x = -1;
	new->y = -1;
	return (fill_list(buf, new));
}

static int			get_number_tetriminos(char *buf)
{
	int n_blocks;
	int i;

	i = 0;
	n_blocks = 0;
	while (buf[i])
	{
		if (buf[i] == BLOCK)
			n_blocks++;
		i++;
	}
	if ((n_blocks % 4) != 0)
		return (0);
	return (n_blocks / 4);
}

int					create_tetriminos_list(char *buf, t_tetrimino **start)
{
	int			n_tetriminos;
	int			i;
	int			cur;
	t_tetrimino	*tmp;

	n_tetriminos = get_number_tetriminos(buf);
	if (n_tetriminos == 0)
		return (0);
	tmp = insert_new_item(buf);
	*start = tmp;
	tmp->letter = 'A';
	i = 1;
	cur = 21;
	*buf == '\n' && buf++;
	while (i < n_tetriminos)
	{
		tmp->next = insert_new_item(buf + cur);
		if (!tmp->next)
			return (0);
		tmp = tmp->next;
		tmp->letter = 'A' + i++;
		cur = cur + 21;
	}
	tmp->next = NULL;
	return (n_tetriminos);
}
