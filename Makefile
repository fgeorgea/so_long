# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 16:13:35 by fgeorgea          #+#    #+#              #
#    Updated: 2023/03/01 16:40:02 by fgeorgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

DIR = srcs/

SRC =	$(DIR)so_long.c \
		$(DIR)utils.c \
		$(DIR)map_utils.c \
		$(DIR)parsing.c \
		$(DIR)path_finding.c \
		$(DIR)mlx_utils.c \
		$(DIR)movement.c \
		$(DIR)img.c \

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra

LIB  = ar rcs $(NAME) ./includes/mlx/libmlx.a ./includes/libft.a

REMOVE = rm -f

DEPENDS = make -C includes/libft

MLX = make -C includes/mlx

COMPILE = gcc $(CFLAGS) -o $(NAME) -Iincludes/lib -Iincludes/mlx -Lincludes/mlx -Lincludes/Libft -lft -lmlx -framework OpenGL -framework Appkit -D BUFFER_SIZE=1

all: $(NAME)

libft : 
	@$(DEPENDS)
	@$(MLX)

$(NAME): libft $(OBJ)
	@$(COMPILE) $(OBJ)

clean:
	$(REMOVE) $(OBJ) 
	make -C includes/Libft clean
	make -C includes/mlx clean

fclean:	clean
	$(REMOVE) $(NAME)
	make -C includes/Libft fclean

re: fclean all

.PHONY: all clean fclean re
