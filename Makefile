# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 14:45:12 by ryoshio-          #+#    #+#              #
#    Updated: 2022/09/11 14:45:48 by ryoshio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAG = -g -Wall -Wextra -Werror

SRC = main.c

OBJ = ${SRC:.c=.o}

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(LIBRARY) $(OBJ)
	make -C libft
	$(CC) $(CFLAG) $(SRC) $(LIBFT) -o $(NAME)

clean:
	make -C libft clean
	rm -rf $(OBJ)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

.PYTHON: all clean fclean re