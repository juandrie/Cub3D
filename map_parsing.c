/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:14:06 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/22 13:15:29 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pos_n(t_data *data)
{
	data->player->dir.x = -1.0;
	data->player->dir.y = 0.0;
	data->player->plane.x = 0.0;
	data->player->plane.y = 0.66;
}

void	pos_s(t_data *data)
{
	data->player->dir.x = 1.0;
	data->player->dir.y = 0.0;
	data->player->plane.x = 0.0;
	data->player->plane.y = -0.66;
}
void	pos_e(t_data *data)
{
	data->player->dir.x = 0.0;
	data->player->dir.y = 1.0;
	data->player->plane.x = 0.66;
	data->player->plane.y = 0.0;
}
void	pos_w(t_data *data)
{
	data->player->dir.x = 0.0;
	data->player->dir.y = -1.0;
	data->player->plane.x = -0.66;
	data->player->plane.y = 0.0;
}

int	init_player_position(t_data *data)
{
	int		y;
	int		x;
	char	c;
	
	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			c = data->map->map[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				data->player->pos.x = x + 0.5;
				data->player->pos.y = y + 0.5;
				if (c == 'N')
					pos_n(data);
				else if (c == 'S')
					pos_s(data);
				else if (c == 'E')
					pos_e(data);
				else if (c == 'W')
					pos_w(data);
				data->map->map[y][x] = '0';
				data->player_initialized = 1;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
