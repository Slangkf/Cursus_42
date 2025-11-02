# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikayiban <ikayiban@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 17:38:25 by tclouet           #+#    #+#              #
#    Updated: 2025/09/18 15:00:08 by ikayiban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation
CC = cc
CF = -Wall -Wextra -Werror

# Include
INC = 	-L$(LIBFT_DIR) -lft \
  	-L$(MLX_DIR) -lmlx
HEAD = cub3d.h

# Source
SRC =	$(SRC_DIR)
SRC_DIR = sources/main.c \
	sources/parsing/check_map.c sources/parsing/check_map2.c sources/parsing/check_textures.c \
	sources/parsing/check_textures2.c sources/parsing/parser.c sources/parsing/parsing_utils.c \
	sources/structures_manag/init_structures.c sources/structures_manag/free_structures.c \
	sources/init_game/load_textures.c sources/init_game/load_textures2.c \
	sources/event_manag/cmds_manag.c sources/raycasting/display_game.c \
	sources/utils/utils.c sources/raycasting/raycast_algo.c sources/raycasting/draw_map.c \
	sources/raycasting/movements.c sources/raycasting/movements2.c \

# Minilibx
MLX_DIR = include/minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_DIR)$(MLX_NAME)

# Program
PROG = cub3d

# Libft
LIBFT_DIR = include/libft/
LIBFT = $(LIBFT_DIR)/libft.a

all:		$(LIBFT) $(MLX) $(PROG)

$(PROG):	$(SRC)
		$(CC) $(CF) -o $(PROG) $(SRC) $(MLX) $(LIBFT) $(INC) -g -lXext -lX11 -lm

$(MLX):
		@make all -C$(MLX_DIR)
$(LIBFT):
		@make all -C$(LIBFT_DIR)

clean:
		@make fclean -C$(LIBFT_DIR)
		@make clean -C$(MLX_DIR)

fclean:		clean
		@rm -f $(PROG)

re:		fclean all

.PHONY:		re fclean clean all
