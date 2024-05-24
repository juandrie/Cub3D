# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 17:13:47 by juandrie          #+#    #+#              #
#    Updated: 2024/05/23 19:17:57 by juandrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and compiling flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Name of the executable
NAME = Cub3D

# Source and object files
SRCS = 	srcs/main.c \
		srcs/hooks.c \
		srcs/raycasting/moves.c \
		srcs/map.c \
		srcs/raycasting/raycasting.c \
		srcs/init_data/init_data.c \
		srcs/init_data/init_lists_utils.c \
		srcs/init_data/init_lists.c \
		srcs/init_data/init_map.c \
		srcs/init_data/init_tabs.c \
		srcs/init_data/init_window.c\
		srcs/init_data/init_texture.c\
		srcs/raycasting/time.c \
		srcs/raycasting/texture.c \
		srcs/parsing/parse_player.c \
		srcs/parsing/parse_args.c \
		srcs/free_data/free_data.c \
		srcs/free_data/free_map.c \
		srcs/free_data/free_window.c \
		srcs/print_data/print_data.c \
		

OBJS = $(SRCS:.c=.o)

# mlx library paths
MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I $(MLX_DIR)
MLX_LINK = -L $(MLX_DIR) -lmlx -lXext -lX11 -lm

# libft library paths
LIBFT_DIR = ./Libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I $(LIBFT_DIR)

# Include paths for headers
INC = -I ./includes

# Compiling
all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(MLX_LINK)

# Creating object files
%.o: %.c
	$(CC) $(CFLAGS) $(INC) $(MLX_INC) $(LIBFT_INC) -c $< -o $@

# Clean objects
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

# Full clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Re-compile
re: fclean all

# Phony targets
.PHONY: all clean fclean re