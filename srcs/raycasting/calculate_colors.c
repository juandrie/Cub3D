/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:26:07 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/10 18:27:42 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_floor(t_data *data)
{
	int	x;
	int	y;
	int	color;
	int	pixel_index;

	y = HEIGHT / 2;
	color = create_trgb(0, data->map->floor_color[0], \
	data->map->floor_color[1], data->map->floor_color[2]);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_index = (y * data->window->size_line) \
			+ (x * (data->window->bpp / 8));
			*(int *)(data->window->img_data + pixel_index) = color;
			x++;
		}
		y++;
	}
}

void	draw_ceiling(t_data *data)
{
	int	x;
	int	y;
	int	color;
	int	pixel_index;

	y = 0;
	color = create_trgb(0, data->map->ceiling_color[0], \
	data->map->ceiling_color[1], data->map->ceiling_color[2]);
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_index = (y * data->window->size_line) \
			+ (x * (data->window->bpp / 8));
			*(int *)(data->window->img_data + pixel_index) = color;
			x++;
		}
		y++;
	}
}
