# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 14:45:12 by ryoshio-          #+#    #+#              #
#    Updated: 2022/09/22 03:46:22 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

CFLAG = -g -Wall -Wextra -Werror

SRC = main.c check_arg.c get_line.c

OBJ = ${SRC:.c=.o}

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBRARY) $(OBJ)
	make -C libft
	$(CC) $(CFLAG) $(SRC) $(LIBFT) -o $(NAME)  -lreadline


run1: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes --suppressions=readline.supp ./minishell

run2: all
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp ./minishell



clean:
	make -C libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

.PYTHON: all clean fclean re
