/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:28:43 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/04 17:25:20 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_key_press(t_data *data)
{
	int	last_key;

	last_key = data->window->key_pressed;
	data->window->key_pressed = 0;
	return (last_key);
}

void	rotate_camera(t_data *data, double angle)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = data->player->dir.x;
	data->player->dir.x = data->player->dir.x * cos(angle) \
	- data->player->dir.y * sin(angle);
	data->player->dir.y = old_dirx * sin(angle) \
	+ data->player->dir.y * cos(angle);
	old_planex = data->player->plane.x;
	data->player->plane.x = data->player->plane.x * cos(angle) \
	- data->player->plane.y * sin(angle);
	data->player->plane.y = old_planex * sin(angle) \
	+ data->player->plane.y * cos(angle);
}

void	move_side(t_data *data, double angle)
{
	double	newx;
	double	newy;

	newx = data->player->pos.x + data->player->plane.x * angle;
	newy = data->player->pos.y + data->player->plane.y * angle;
	if (newx >= 0 && newx < data->map->width && newy >= 0 \
	&& newy < data->map->height)
	{
		if (data->map->map_tab[(int)newy][(int)newx] == '0')
		{
			data->player->pos.x = newx;
			data->player->pos.y = newy;
		}
	}
}

void	move_forward(t_data *data)
{
	double	newx;
	double	newy;

	newx = data->player->pos.x + data->player->dir.x * data->window->movespeed;
	newy = data->player->pos.y + data->player->dir.y * data->window->movespeed;
	if (newx >= 0 && newx < data->map->width && \
	newy >= 0 && newy < data->map->height)
	{
		if (data->map->map_tab[(int)data->player->pos.y][(int)newx] == '0')
			data->player->pos.x = newx;
		if (data->map->map_tab[(int)newy][(int)data->player->pos.x] == '0')
			data->player->pos.y = newy;
	}
}

void	move_back(t_data *data)
{
	double	newx;
	double	newy;

	newx = data->player->pos.x - data->player->dir.x * data->window->movespeed;
	newy = data->player->pos.y - data->player->dir.y * data->window->movespeed;
	if (newx >= 0 && newx < data->map->width && \
	newy >= 0 && newy < data->map->height)
	{
		if (data->map->map_tab[(int)data->player->pos.y][(int)newx] == '0')
			data->player->pos.x = newx;
		if (data->map->map_tab[(int)newy][(int)data->player->pos.x] == '0')
			data->player->pos.y = newy;
	}
}

void	read_keys(t_data *data)
{
	int	key;

	key = get_key_press(data);
	if (key == W)
		move_forward(data);
	if (key == S)
		move_back(data);
	if (key == D)
		move_side(data, data->window->rotspeed);
	if (key == A)
		move_side(data, -data->window->rotspeed);
	if (key == RIGHT)
		rotate_camera(data, data->window->rotspeed);
	if (key == LEFT)
		rotate_camera(data, -data->window->rotspeed);
	if (key == ESC)
		close_window(data);
}
