/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:14:50 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/30 18:31:08 by juandrie         ###   ########.fr       */
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

# define W 119
# define S 115
# define D 100
# define A 97
# define ESC 65307
# define RIGHT 0xff51
# define LEFT 0xff53

# define MOVE_SPEED 0.035
# define ROTATE_SPEED 0.035

# define WIDTH 640
# define HEIGHT 480

typedef struct s_vector
{
	double	x;
	double	y;
}t_vector;

typedef struct s_list
{
	char			*line;
	struct s_list	*next;
}t_list;

typedef struct s_map
{
	t_list		*map_list;
	t_list		*text_list;
	t_list		*color_list;
	char		**map_tab;
	char		**text_tab;
	char		**color_tab;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			floor_color[3];
	int			ceiling_color[3];
	int			width;
	int			height;
	double		wall_x;
	double		text_pos;
	int			lineheight;
	int			drawstart;
	int			drawend;
	t_vector	texture;
}t_map;

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
	int			running;
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

/*
typedef struct s_texture
{
	void	*img_ptr;	= Pointeur vers l'image texture
	char	*addr;		= Les données de l'image
	int		width;		= Largeur de la texture
	int		height;		= Hauteur de la texture
	int		bpp;		= Bits par pixel
	int		size_line;	= Taille de ligne en mémoire
	int		endian;		= Endian, qui indique l'ordre des couleurs
	int		texture_num;
}	t_texture;
*/

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
	TEXTURE_SIZE,
	TEXTURE_FORMAT,
	TEXTURE_PATH,
	TEXTURE_MISSING,
	TEXTURE_DUPLICATED,
}t_error;

typedef struct s_data
{
	t_map		*map;
	t_window	*window;
	t_player	*player;
	t_ray		*ray;
	t_vector	*vector;
	t_texture	*texture;
	int			keycode;
	int			player_initialized;
	t_error		error;
}t_data;

/* parse_args.c */
int			is_correct_extension(char *filename, char *str);
int			check_args(int argc, char **argv, char **envp);

/* init_data.c */
void		free_data(t_data **data);
t_data		*init_data(char *filename);

/* init_map.c */
t_map		*init_map(char *filename, t_data *data);

/* init_lists.c */
int			init_lists(t_map *map, char *filename, t_data *data);

/* init_tabs.c */
int			init_tabs(t_map *map);

/* init_window.c */
t_window	*init_window(void);

/* init_map_list_utils.c */
int			open_fd(int *fd, char *filename);
int			ft_replace_nl(t_map *map, char *line);
int			list_size(t_list *list);

/* free_window.c */
void		free_window(t_window **window);

/* free_map.c */
void		free_list(t_list **list);
void		free_lists(t_map *map);
void		free_tabs(t_map *map);
void		free_map(t_map **map);

/* free_data.c */
void		free_data(t_data **data);

/* print_data.c */
void		print_data(t_data *data);

/* parse_textures.c */
int			parse_textures(char **tab);

/* parse_textures_utils.c */
int			check_correct_directions(char **tab);
int			check_every_directions(char **tab);
int			is_valid_texture_format(char **tab);
int			nb_textures(char **tab);

/* A trier */
int			get_texture_color(t_texture *texture, int x, int y);
int			calculate_texture_num(t_data *data);
double		calculate_wall_x(t_data *data);
int			calculate_texture_x(t_data *data);
int			init_player_position(t_data *data);

void		perform_ray_casting(t_data *data);
void		update_timing_and_movement(t_data *data);
double		get_ticks(void);
void		hooks(t_data *data);
int			get_key_press(t_data *data);
void		read_keys(t_data *data);
int			loop_hook(t_data *data);
void		update_timing_and_movement(t_data *data);
void		extract_texture_paths(t_map *map);
void		init_textures(t_data *data);
void		calculate_map_dimensions(t_map *map);
void		calculate_map_dimensions(t_map *map);
void		print_list(t_list *list);
char		*skip_whitespace(char *str);
void		print_err(t_error error);
int			parsing(t_map *map);
int			tab_size(char **tab);

#endif 