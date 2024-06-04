# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 17:13:47 by juandrie          #+#    #+#              #
#    Updated: 2024/06/04 14:12:38 by juandrie         ###   ########.fr        #
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
		srcs/error.c \
		srcs/hooks.c \
		srcs/map.c \
		srcs/utils.c \
		srcs/raycasting/raycasting.c \
		srcs/raycasting/moves.c \
		srcs/raycasting/time.c \
		srcs/raycasting/texture.c \
		srcs/init_data/init_data.c \
		srcs/init_data/init_lists_utils.c \
		srcs/init_data/init_lists.c \
		srcs/init_data/init_map.c \
		srcs/init_data/init_tabs.c \
		srcs/init_data/init_window.c\
		srcs/init_data/init_texture.c\
		srcs/init_data/init_player.c \
		srcs/parsing/parsing.c \
		srcs/parsing/colors/parse_colors.c \
		srcs/parsing/colors/parse_colors_utils.c \
		srcs/parsing/colors/parse_rgb_values.c \
		srcs/parsing/map/parse_map.c \
		srcs/parsing/parse_args.c \
		srcs/parsing/parse_utils.c \
		srcs/parsing/textures/parse_textures.c \
		srcs/parsing/textures/parse_textures_utils.c \
		srcs/free_data/free_data.c \
		srcs/free_data/free_map.c \
		srcs/free_data/free_window.c \
		srcs/free_data/free_textures.c \
		srcs/print_data/print_data.c \
		srcs/start_game/start_game.c \

BUILD_DIR = .build
OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)	

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

# Create build directory and subdirectories
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)/srcs
	@mkdir -p $(BUILD_DIR)/srcs/raycasting
	@mkdir -p $(BUILD_DIR)/srcs/init_data
	@mkdir -p $(BUILD_DIR)/srcs/parsing
	@mkdir -p $(BUILD_DIR)/srcs/parsing/colors
	@mkdir -p $(BUILD_DIR)/srcs/parsing/map
	@mkdir -p $(BUILD_DIR)/srcs/parsing/textures
	@mkdir -p $(BUILD_DIR)/srcs/free_data
	@mkdir -p $(BUILD_DIR)/srcs/print_data
	@mkdir -p $(BUILD_DIR)/srcs/start_game

# Compiling
all: $(NAME)
	@./start_cub3d.sh

$(NAME): $(BUILD_DIR) $(OBJS)
	@echo "$(PURPLE)Making cub3D...$(RESET)"
	@make --no-print-directory -C $(LIBFT_DIR)
	@echo "$(CYAN)Making minilibx...$(RESET)"
	@make --no-print-directory -C $(MLX_DIR)
	@echo "$(CYAN)Minilibx done !$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(MLX_LINK)
	@echo "$(PURPLE)Cub3D done !$(RESET)"

# Creating object files
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) $(MLX_INC) $(LIBFT_INC) -c $< -o $@

# Clean objects
clean:
	@echo "Cleaning in progress..."
	@make --no-print-directory -C $(LIBFT_DIR) clean
	@rm -rf $(BUILD_DIR)
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