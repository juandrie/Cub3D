/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcultate_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:24:17 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/10 18:30:12 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_textured_wall_slice(t_data *data)
{
	int		y;
	int		pixel_index;
	int		color;
	double	step;

	y = data->map->drawstart;
	step = 1.0 * data->texture[data->texture->texture_num].height \
	/ data->map->lineheight;
	data->map->text_pos = (data->map->drawstart - HEIGHT / 2 \
	+ data->map->lineheight / 2) * step;
	while (y < data->map->drawend)
	{
		data->map->texture.y = (int)data->map->text_pos & \
		(data->texture[data->texture->texture_num].height - 1);
		data->map->text_pos += step;
		color = get_texture_color(&data->texture[data->texture->texture_num], \
		data->map->texture.x, data->map->texture.y);
		if (data->ray->side == 1)
			color = (color >> 1) & 8355711;
		pixel_index = (y * data->window->size_line) \
		+ (data->vector->x * (data->window->bpp / 8));
		*(int *)(data->window->img_data + pixel_index) = color;
		y++;
	}
}

void	draw(t_data *data)
{
	data->texture->texture_num = calculate_texture_num(data);
	data->map->wall_x = calculate_wall_x(data);
	data->map->texture.x = calculate_texture_x(data);
	draw_textured_wall_slice(data);
}

void	draw_wall_slice(t_data *data)
{
	if (data->ray->side == 0)
	{
		data->ray->perpwalldist = (data->ray->map.x - data->player->pos.x + \
		(1 - data->ray->step.x) / 2) / data->ray->ray_dir.x;
	}
	else
	{
		data->ray->perpwalldist = (data->ray->map.y - data->player->pos.y + \
		(1 - data->ray->step.y) / 2) / data->ray->ray_dir.y;
	}
	data->ray->perpwalldist = fabs(data->ray->perpwalldist);
	data->map->lineheight = (int)(HEIGHT / data->ray->perpwalldist);
	data->map->drawstart = -data->map->lineheight / 2 + HEIGHT / 2;
	if (data->map->drawstart < 0)
		data->map->drawstart = 0;
	data->map->drawend = data->map->lineheight / 2 + HEIGHT / 2;
	if (data->map->drawend >= HEIGHT)
		data->map->drawend = HEIGHT - 1;
}
