/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:37:18 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/10 18:39:59 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	step_ray(t_data *data)
{
	if (data->ray->side_dist.x < data->ray->side_dist.y)
	{
		data->ray->side_dist.x += data->ray->delta_dist.x;
		data->ray->map.x += data->ray->step.x;
		data->ray->side = 0;
	}
	else
	{
		data->ray->side_dist.y += data->ray->delta_dist.y;
		data->ray->map.y += data->ray->step.y;
		data->ray->side = 1;
	}
}

void	initialize_step_and_side_distance(t_data *data)
{
	if (data->ray->ray_dir.x < 0)
	{
		data->ray->step.x = -1;
		data->ray->side_dist.x = (data->player->pos.x - data->ray->map.x) \
		* data->ray->delta_dist.x;
	}
	else
	{
		data->ray->step.x = 1;
		data->ray->side_dist.x = (data->ray->map.x + 1.0 - data->player->pos.x) \
		* data->ray->delta_dist.x;
	}
	if (data->ray->ray_dir.y < 0)
	{
		data->ray->step.y = -1;
		data->ray->side_dist.y = (data->player->pos.y - data->ray->map.y) \
		* data->ray->delta_dist.y;
	}
	else
	{
		data->ray->step.y = 1;
		data->ray->side_dist.y = (data->ray->map.y + 1.0 - data->player->pos.y) \
		* data->ray->delta_dist.y;
	}
}

void	calculate_ray_direction(t_data *data)
{
	double	camera_x;

	camera_x = (2 * (data->vector->x / (double) WIDTH)) - 1;
	data->ray->ray_dir.x = data->player->dir.x + \
	data->player->plane.x * camera_x;
	data->ray->ray_dir.y = data->player->dir.y + \
	data->player->plane.y * camera_x;
}

void	calculate_delta_distances(t_data *data)
{
	if (data->ray->ray_dir.x == 0)
		data->ray->delta_dist.x = 1e30;
	else
		data->ray->delta_dist.x = fabs(1 / data->ray->ray_dir.x);
	if (data->ray->ray_dir.y == 0)
		data->ray->delta_dist.y = 1e30;
	else
		data->ray->delta_dist.y = fabs(1 / data->ray->ray_dir.y);
}
