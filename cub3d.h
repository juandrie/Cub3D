/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:14:50 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/15 19:05:21 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <time.h>

#define W 119//65362
#define S 115//65364 
#define D 100//65363 
#define A 97//65361
#define ESC 65307


typedef struct s_vector
{
    double x;
    double y;
}               t_vector;

typedef struct s_player
{
    t_vector pos;
    t_vector dir;
    t_vector plane;
}               t_player;

typedef struct s_window
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     width;
    int     height;
    int     key_pressed;
    int		running;
    double  moveSpeed;
    double  rotSpeed;
}               t_window;

typedef struct s_ray
{
    t_vector    ray_dir;
    t_vector    side_dist;
    t_vector    delta_dist;
    t_vector    map;
    t_vector    step;
    int         hit;
    int         side;
}               t_ray;

typedef struct s_data
{
    t_player    *player;
    t_window    *window;
    t_ray       *ray;
    t_vector    *vector;
    int keycode;
}               t_data;


extern int worldMap[24][24];  // Add this line to declare the array

void draw_vertical_line(t_data *data, int drawStart, int drawEnd, int color);
void perform_ray_casting(t_data *data);
int	determine_color(int wallType, t_data *data);
void update_timing_and_movement(t_data *data);
double get_ticks();
void print_fps(double frameTime);
void init_key_hooks(t_data *data);
int get_key_press(t_data *data);
void read_keys(t_data *data);



#endif 