/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   solver.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/02 15:01:32 by dfreire        #+#    #+#                */
/*   Updated: 2019/03/12 15:34:57 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_canvas_limit(t_tetrimino *tetri, int size)
{
	int row;
	int col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (tetri->tetrimino[row][col] == BLOCK)
				if ((row + tetri->x) >= size || (col + tetri->y) >= size
					|| (row + tetri->x) < 0 || (col + tetri->y) < 0)
					return (0);
			col++;
		}
		row++;
	}
	return (1);
}

static int	is_it_in_place(int x, int y, t_tetrimino *cur)
{
	int row;
	int col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (cur->tetrimino[row][col] == BLOCK)
			{
				if ((cur->x + row == x) && (cur->y + col == y))
					return (0);
			}
			col++;
		}
		row++;
	}
	return (1);
}

static int	check_position(t_tetrimino *start, t_tetrimino *tetri)
{
	int			row;
	int			col;
	t_tetrimino	*cur;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (tetri->tetrimino[row][col] == BLOCK)
			{
				cur = start;
				while (cur->letter != tetri->letter)
				{
					if (!(is_it_in_place(tetri->x + row, tetri->y + col, cur)))
						return (0);
					cur = cur->next;
				}
			}
			col++;
		}
		row++;
	}
	return (1);
}

int			backtrack_tetrimino(t_tetrimino *start, t_tetrimino *tetri,
			int size)
{
	int row;
	int col;

	row = size * -1;
	while (row < size)
	{
		col = size * -1;
		while (col < size)
		{
			tetri->x = row;
			tetri->y = col;
			if (check_canvas_limit(tetri, size) == 1 &&
			check_position(start, tetri) == 1)
			{
				if ((tetri->next) == NULL)
					return (1);
				if ((backtrack_tetrimino(start, tetri->next, size)) == 1)
					return (1);
			}
			col++;
		}
		row++;
	}
	return (0);
}
