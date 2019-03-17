/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_solution.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/02 15:11:54 by dfreire        #+#    #+#                */
/*   Updated: 2019/03/04 09:17:30 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**new_canvas(int size)
{
	char	**canvas;
	int		i;

	canvas = (char **)ft_memalloc(sizeof(*canvas) * size);
	if (!canvas)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(canvas[i] = ft_strnew(size)))
			return (NULL);
		i++;
	}
	canvas[i] = NULL;
	return (canvas);
}

static char	**fill_empty_spaces(char **canvas, int size)
{
	int row;
	int col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			canvas[row][col] = EMPTY;
			col++;
		}
		row++;
	}
	return (canvas);
}

static void	free_canvas(char **canvas, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putendl(canvas[i]);
		ft_strdel(&canvas[i]);
		i++;
	}
	ft_memdel((void **)canvas);
}

void		printer(t_tetrimino *ptr, int size)
{
	int		row;
	int		col;
	char	**canvas;

	canvas = new_canvas(size);
	fill_empty_spaces(canvas, size);
	while (ptr != NULL)
	{
		row = 0;
		while (row < 4)
		{
			col = 0;
			while (col < 4)
			{
				if (ptr->tetrimino[row][col] == BLOCK)
					canvas[ptr->x + row][ptr->y + col] = ptr->letter;
				col++;
			}
			row++;
		}
		ptr = ptr->next;
	}
	free_canvas(canvas, size);
}
