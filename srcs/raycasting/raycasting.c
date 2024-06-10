/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:29:32 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/10 18:40:13 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	perform_dda(t_data *data)
{
	int	hit;
	int	mapx;
	int	mapy;

	hit = 0;
	mapx = (int)data->ray->map.x;
	mapy = (int)data->ray->map.y;
	while (!hit)
	{
		step_ray(data);
		mapx = (int)data->ray->map.x;
		mapy = (int)data->ray->map.y;
		if (mapx >= 0 && mapx < data->map->width && \
		mapy >= 0 && mapy < data->map->height)
		{
			if (data->map->map_tab[mapy][mapx] == '1')
				hit = 1;
		}
	}
}

void	perform_raycasting(t_data *data)
{
	draw_floor(data);
	draw_ceiling(data);
	data->vector->x = 0;
	while (data->vector->x < WIDTH)
	{
		data->ray->map.x = (int)data->player->pos.x;
		data->ray->map.y = (int)data->player->pos.y;
		calculate_ray_direction(data);
		calculate_delta_distances(data);
		initialize_step_and_side_distance(data);
		perform_dda(data);
		draw_wall_slice(data);
		draw(data);
		data->vector->x++;
	}
}
