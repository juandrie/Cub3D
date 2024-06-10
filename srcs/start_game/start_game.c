/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:31:20 by cabdli            #+#    #+#             */
/*   Updated: 2024/06/10 18:01:49 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

void	start_the_game(t_data *data)
{
	get_player_pos(data);
	hooks(data);
}
