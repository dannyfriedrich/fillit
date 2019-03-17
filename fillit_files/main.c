/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/02 15:47:03 by dfreire        #+#    #+#                */
/*   Updated: 2019/03/08 09:36:39 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		size_canvas(int n_tetriminos)
{
	int size;

	n_tetriminos = n_tetriminos * 4;
	size = ft_sqrt(n_tetriminos);
	while (size == -1)
	{
		n_tetriminos++;
		size = n_tetriminos;
	}
	return (size);
}

static int		print_tetrimino_solution(int n, t_tetrimino *start)
{
	int	valid;

	valid = 0;
	while (!valid)
	{
		valid = backtrack_tetrimino(start, start, n);
		n++;
	}
	if (valid == 0)
	{
		ft_putendl("error");
		return (0);
	}
	printer(start, --n);
	return (1);
}

static void		free_list(t_tetrimino *start)
{
	int			i;
	t_tetrimino	*ptr;

	while (start != NULL)
	{
		ptr = start;
		i = 0;
		while (i < 4)
		{
			ft_memdel((void **)(&(start->tetrimino[i])));
			i++;
		}
		ft_memdel((void **)(start->tetrimino));
		start = start->next;
		ft_memdel((void **)(&ptr));
	}
}

int				main(int argc, char **argv)
{
	t_tetrimino	*start;
	int			n_tetriminos;

	start = NULL;
	if (argc == 2)
	{
		n_tetriminos = allocating_tetriminos(argv[1], &start);
		if (n_tetriminos == -1)
		{
			ft_putendl("error");
			free_list(start);
			return (0);
		}
		n_tetriminos = size_canvas(n_tetriminos);
		print_tetrimino_solution(n_tetriminos, start);
	}
	else
	{
		ft_putendl("usage: ./fillit [input_file]");
		return (1);
	}
	free_list(start);
	return (1);
}
