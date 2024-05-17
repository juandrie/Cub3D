/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:14:50 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/17 18:07:44 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
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

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}	t_player;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	int		key_pressed;
	int		running;
	double	movespeed;
	double	rotspeed;
}	t_window;

typedef struct s_ray
{
	t_vector	ray_dir;
	t_vector	side_dist;
	t_vector	delta_dist;
	t_vector	map;
	t_vector	step;
	int			hit;
	int			side;
}	t_ray;

typedef struct s_map
{
	char	**map;
	char	*filepath;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor_color[3];
	int		ceiling_color[3];
	int		width;
	int		height;
	int		fd;
}	t_map;

typedef struct s_data
{
	t_player	*player;
	t_window	*window;
	t_ray		*ray;
	t_vector	*vector;
	t_map		*map;
	int			keycode;
}	t_data;

void	draw_vertical_line(t_data *data, int drawStart, int drawEnd, int color);
void	perform_ray_casting(t_data *data);
int		determine_color(char wallChar, t_data *data);
void	update_timing_and_movement(t_data *data);
double	get_ticks(void);
void	print_fps(double frameTime);
void	hooks(t_data *data);
int		get_key_press(t_data *data);
void	read_keys(t_data *data);
int		loop_hook(t_data *data);
int		read_map(t_data *data);
void	update_timing_and_movement(t_data *data);
void	init_player(t_player *player);
void	init_window(t_window *window);
void	init_map(t_map *map);
t_data	*init_data(void);

#endif 