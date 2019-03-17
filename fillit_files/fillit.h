/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dfreire <dfreire@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/01 18:40:45 by dfreire        #+#    #+#                */
/*   Updated: 2019/03/12 14:57:37 by dfreire       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BLOCK '#'
# define EMPTY '.'
# include "../libft/libft.h"
# include <fcntl.h>
# define BUFF_SIZE 547

typedef struct			s_tetrimino
{
	char				**tetrimino;
	int					x;
	int					y;
	char				letter;
	struct s_tetrimino	*next;
}						t_tetrimino;

int						allocating_tetriminos(char *file, t_tetrimino **start);
int						check_symbols(char *buf, int size);
int						validate_buffer_format(char *buf, int size);
int						check_tetrimino_size(char **tetrimino);
int						do_blocks_touch(char **tetrimino, int row, int col);
int						check_tetrimino_format(char **tetrimino);
int						create_tetriminos_list(char *buf, t_tetrimino **start);
int						backtrack_tetrimino(t_tetrimino *start,
						t_tetrimino *tetri, int size);
void					printer(t_tetrimino *ptr, int size);

#endif
