# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 13:55:49 by dmanuel-          #+#    #+#              #
#    Updated: 2023/03/14 11:17:35 by dmanuel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Werror -Wextra -O3 -g
MLXFLAGS=-L ./minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11
DEPS= minilibx-linux/mlx.h libft/libft.a

NAME=fdf
SRC=src/main.c src/draw.c src/read_file.c src/calc.c
OBJ=$(SRC:.c=.o)

LIBFT = libft/libft.a

all: deps $(NAME)
deps:
	@$(MAKE) -C ./libft
	@$(MAKE) -C ./minilibx-linux
$(NAME): $(OBJ) $(DEPS)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)
clean:
	@$(MAKE) $@ -C ./libft
	@$(MAKE) $@ -C ./minilibx-linux
	@rm -rf $(OBJ)
fclean: clean
	@$(MAKE) $@ -C ./libft
	@rm -rf $(NAME)
re: fclean all
	@$(MAKE) $@ -C ./libft
	@$(MAKE) $@ -C ./minilibx-linux
