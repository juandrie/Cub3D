/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:28:43 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/10 19:53:17 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
