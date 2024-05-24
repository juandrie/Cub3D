# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 17:13:47 by juandrie          #+#    #+#              #
#    Updated: 2024/05/24 15:48:19 by cabdli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
# Regular
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

#Bold
BRED = \033[1;31m	
BGREEN = \033[1;32m	
BYELLOW = \033[1;33m	
BBLUE = \033[1;34m
BPURPLE = \033[1;35m
BCYAN = \033[1;36m
BWHITE = \033[1;37m

# Compiler and compiling flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Name of the executable
NAME = cub3D

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
	@echo "$(PURPLE)Making cub3D...$(RESET)"
	@make --no-print-directory -C $(LIBFT_DIR)
	@echo "$(CYAN)Making minilibx...$(RESET)"
	@make --no-print-directory -C $(MLX_DIR)
	@echo "$(CYAN)Minilibx done !$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(MLX_LINK)
	@echo "$(PURPLE)Cub3D done !$(RESET)"

# Creating object files
%.o: %.c
	@$(CC) $(CFLAGS) $(INC) $(MLX_INC) $(LIBFT_INC) -c $< -o $@

# Clean objects
clean:
	@echo "Cleaning in progress..."
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)
	@make --no-print-directory -C $(MLX_DIR) clean
	@echo "$(YELLOW)Cleaning done !$(RESET)"

# Full clean
fclean: clean
	@echo "Full cleaning in progress..."
	@make --no-print-directory -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@echo "$(YELLOW)Full cleaning done !$(RESET)"

# Re-compile
re: fclean all

# Phony targets
.PHONY: all clean fclean re