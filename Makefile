# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 14:45:12 by ryoshio-          #+#    #+#              #
#    Updated: 2022/10/07 05:35:33 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

CFLAG = -g -Wall -Wextra -Werror

SRC = main.c check_arg.c check_line.c  command.c\
	ft_execve.c ft_free_strstr.c ft_strstrdup.c ft_strstrlen.c\
	ft_split_quote.c get_line.c\
	

OBJ = ${SRC:.c=.o}

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBRARY) $(OBJ)
	make -C libft
	$(CC) $(CFLAG) $(SRC) $(LIBFT) -o $(NAME)  -lreadline


teste:
	make -C libft
	$(CC) $(CFLAG)  teste.c $(LIBFT)

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
