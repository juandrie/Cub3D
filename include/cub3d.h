/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:14:50 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/10 20:26:21 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <time.h>

#define KEY_COUNT 65308


# ifndef X_CROSS
#  define X_CROSS 17
# endif /*X_CROSS*/

# define W 119
# define S 115
# define D 100
# define A 97
# define ESC 65307
# define RIGHT 0xff51
# define LEFT 0xff53

# define MOVE_SPEED  0.5
# define ROTATE_SPEED 0.5

# define WIDTH 1200
# define HEIGHT 800

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

typedef struct s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	void		*img_data;
	int			bpp;
	int			size_line;
	int			endian;
	int			key_pressed;
	double		movespeed;
	double		rotspeed;
}t_window;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}t_player;

typedef struct s_ray
{
	t_vector	ray_dir;
	t_vector	side_dist;
	t_vector	delta_dist;
	t_vector	map;
	t_vector	step;
	int			hit;
	int			side;
	double		perpwalldist;
}t_ray;

typedef struct s_texture
{
	void	*img_ptr;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	int		texture_num;
}	t_texture;

typedef enum s_error
{
	EMPTY,
	UNCLOSED,
	MISS_DUP_C,
	INVAL_RGB,
	EMPTY_L,
	WRONG_C,
	NO_PLAYER,
	MUCH_PLAYERS,
	TEXTURE_SIZE,
	TEXTURE_PATH,
	TEXTURE_INVAL,
	TEXTURE_DUPLICATED,
	MAP_BORDERS,
	SPACE_WALLS
}t_error;

typedef struct s_data
{
	t_map		*map;
	t_window	*window;
	t_player	*player;
	t_ray		*ray;
	t_vector	*vector;
	t_texture	*texture;
	char		**text_path;
	int			keycode;
	int			player_initialized;
	bool		key_states[KEY_COUNT]; 
}t_data;

/******************** INITIALIZATION *************************/

/* init_data.c */
int			init_data(t_data **data, char *filename, int step);

/* init_map.c */
t_map		*init_map(char *filename);

/* init_lists.c */
int			init_lists(t_map *map, char *filename);

/* init_tabs.c */
int			init_tabs(t_map *map);

/* init_window.c */
t_window	*init_window(void);

/* init_map_list_utils.c */
int			open_fd(int *fd, char *filename);
int			ft_replace_nl(t_map *map, char *line);
int			list_size(t_list *list);

/* init_texture.c */
char		**create_text_path(t_data *data);

/* init_colors.c */
int			init_colors(char **tab, int *ceiling, int *floor);

/* init_tabs_utils.c */
void		get_nb_text_color(t_list *text_color_list, int *tc);

/******************** PARSING *************************/

/* parsing.c */
int			parsing(t_map *map);

/* parse_args.c */
int			is_correct_extension(char *filename, char *str);
int			check_args(int argc, char **argv, char **envp);

/* parse_colors.c */
int			parse_colors(char **tab);
int			is_nb(char c);

/* parse_colors_utils.c */
char		*remove_spaces(char *str);
int			is_comma(char c);

/* parse_rgb_values.c */
int			check_comma_nbs(char *tab);
int			check_nb_of_nbs(char *tab);
int			check_nb_of_commas(char *tab);
int			check_nbs_range(char *tab);

/* parse_map.c */
int			parse_map(char **tab);

/* parse_textures.c */
int			parse_textures(char **tab);

/* parse_textures_utils.c */
int			check_nb_textures(char **tab);

/* check_around_spaces.c */
int			invalid_block_around(char **tab, int i, int j);
int			check_around_spaces(char **tab);

/* check_borders.c */
int			check_line_rl(char *tab);
int			check_borders_right_left(char **tab);
int			check_borders_up_down(char **tab);
int			check_borders(char **tab);

/* check_player.c */
int			check_player(char *tab);
int			no_player(char **tab);
int			too_much_players(char **tab);

/* parse_map_utils.c */
int			is_space_or_one(char c);
int			is_wrong_char(char c);
int			is_player(char c);
int			map_missing(char **tab);

/******************** FREE *************************/

/* free_window.c */
void		free_window(t_window **window);

/* free_textures.c */
void		free_text_path(char ***texture);
// void		free_textures(t_texture **texture);
void		free_textures(t_texture *texture, t_data *data);

/* free_map.c */
void		free_tabs(t_map *map, int tab);
void		free_map(t_map **map, int tab);
void		free_full_tab(char **tab);
void		free_tab(char ***tab);

/* free_lists.c */
void		free_list(t_list **list);
void		free_lists(t_map *map);

/* free_data.c */
void		free_data(t_data **data, int tab);

/* PRINT */

/* print_data.c */
void		print_list(t_list *list);
void		print_tab(char **tab);
void		print_map(t_map *map);
void		print_data(t_data *data);

/******************** RAYCASTING *************************/

/* raycasting.c */
void		perform_raycasting(t_data *data);

/* moves.c */
void		move_back(t_data *data);
void		move_forward(t_data *data);
void		move_side(t_data *data, double angle);
void		rotate_camera(t_data *data, double angle);

/* keys.c */
int			get_key_press(t_data *data);
void		read_keys(t_data *data);

/* textures.c */
int			get_texture_color(t_texture *texture, int x, int y);
int			calculate_texture_num(t_data *data);
double		calculate_wall_x(t_data *data);
int			calculate_texture_x(t_data *data);

/* calculate_textures.c */
void		draw_textured_wall_slice(t_data *data);
void		draw(t_data *data);
void		draw_wall_slice(t_data *data);

/* calculate_colors.c */
void		draw_ceiling(t_data *data);
void		draw_floor(t_data *data);

/* calculate_position.c */
void		step_ray(t_data *data);
void		initialize_step_and_side_distance(t_data *data);
void		calculate_ray_direction(t_data *data);
void		calculate_delta_distances(t_data *data);

/* time.c */
void		update_timing_and_movement(t_data *data);
double		get_ticks(void);

/******************** START GAME *************************/

/* start_game.c */
int			get_player_pos(t_data *data);
void		start_the_game(t_data *data);

/* get_player.c */
void		handle_player(char c, t_data *data, int x, int y);

/******************** SRCS *************************/

/* hooks.c */
void		hooks(t_data *data);
int			loop_hook(t_data *data);
int			close_window(t_data *data);

/* error.c */
void		print_err(t_error error);

/* utils.c */
char		*skip_whitespace(char *str);
int			tab_size(char **tab);
char		*rev_skip_whitespace_borders(char *str);
char		*rev_skip_whitespace_path(char *str);
char		*get_text_path(char *str);

#endif 