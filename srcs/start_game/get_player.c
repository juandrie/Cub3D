/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:35:10 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/04 17:05:03 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

void	handle_player(char c, t_data *data, int x, int y)
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
	data->map->map_tab[y][x] = '0';
	data->player_initialized = 1;
}

int	get_player_pos(t_data *data)
{
	int		y;
	int		x;
	char	c;

	y = -1;
	while (++y < data->map->height)
	{
		x = -1;
		while (++x < data->map->width)
		{
			c = data->map->map_tab[y][x];
			if (is_player(c))
			{
				handle_player(c, data, x, y);
				return (1);
			}
		}
	}
	return (0);
}
