# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgeorgea <fgeorgea@student.s19be>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 14:44:40 by fgeorgea          #+#    #+#              #
#    Updated: 2023/02/06 14:48:17 by fgeorgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
DIR		= srcs/
MLX		= ./includes/mlx/libmlx.a
CC		= gcc
FLAGS	= -Wall -Werror -Wextra
MFLAGS	= -L./includes/mlx -lmlx -framework OpenGL -framework AppKit

SRCS = main.c \

OBJS = $(SRCS:.c=.o)

all: $(MLX) $(NAME)

$(MLX):
	make -sC ./includes/mlx

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(MFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make clean -C ./includes/mlx

re: fclean all

.PHONY:	all clean fclean re
