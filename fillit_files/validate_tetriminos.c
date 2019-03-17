/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_tetriminos.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ihering- <ihering-@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/01 19:04:16 by dfreire        #+#    #+#                */
/*   Updated: 2019/03/05 17:28:19 by ihering-      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_symbols(char *buf, int size)
{
	while (size > 0)
	{
		size--;
		if ((buf[size] != EMPTY) && (buf[size] != BLOCK) && (buf[size] != '\n'))
			return (0);
	}
	return (1);
}

int	validate_buffer_format(char *buf, int size)
{
	int			row;
	int			col;

	while (size >= 0)
	{
		size--;
		col = 0;
		while (col < 4)
		{
			row = 0;
			if (buf[size] != '\n')
				return (0);
			while (row < 4)
			{
				size--;
				if (size < 0 || buf[size] == '\n')
					return (0);
				row++;
			}
			col++;
			size--;
		}
	}
	return (1);
}

int	check_tetrimino_size(char **tetrimino)
{
	int			row;
	int			col;
	int			size;

	row = 0;
	size = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (tetrimino[row][col] == BLOCK)
				size++;
			col++;
		}
		row++;
	}
	if (size == 4)
		return (1);
	return (0);
}

int	do_blocks_touch(char **tetrimino, int row, int col)
{
	int i;

	i = 0;
	if (col < 3 && tetrimino[row][col + 1] == BLOCK)
		i++;
	if (row < 3 && tetrimino[row + 1][col] == BLOCK)
		i++;
	if (col > 0 && tetrimino[row][col - 1] == BLOCK)
		i++;
	if (row > 0 && tetrimino[row - 1][col] == BLOCK)
		i++;
	return (i);
}

int	check_tetrimino_format(char **tetrimino)
{
	int	row;
	int col;
	int i;
	int count;

	count = 0;
	i = 0;
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (tetrimino[row][col] == BLOCK)
			{
				i = do_blocks_touch(tetrimino, row, col);
				count = count + i;
			}
			col++;
		}
		row++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}
