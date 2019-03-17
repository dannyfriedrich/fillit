# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dfreire <dfreire@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/05 10:45:18 by ihering-       #+#    #+#                 #
#    Updated: 2019/03/12 14:59:22 by dfreire       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = ./fillit_files/open_file.c ./fillit_files/validate_tetriminos.c\
	./fillit_files/list_tetriminos.c ./fillit_files/solver.c\
	./fillit_files/print_solution.c ./fillit_files/main.c
HEADER = ./fillit_files

all: $(NAME)

$(NAME):
		make -C ./libft
		gcc -o $(NAME) $(SRC) -I$(HEADER) -L ./libft/ -lft -Wall -Wextra -Werror

clean:
		make -C ./libft/ clean

fclean: clean
		rm -f $(NAME)
		make -C ./libft/ fclean

re: fclean all
