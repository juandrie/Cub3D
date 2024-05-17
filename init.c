/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:34:28 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/17 18:09:08 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_player *player)
{
	player->pos.x = 22;
	player->pos.y = 12;
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0.66;
}

void	init_window(t_window *window)
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, 640, 480, "Cub3D");
	window->width = 640;
	window->height = 480;
	window->key_pressed = 0;
	window->running = 1;
	window->movespeed = 0;
	window->rotspeed = 0;
}

void	init_map(t_map *map)
{
	map->map = NULL;
	map->filepath = ft_strdup("path_to_map_file");
	map->width = 0;
	map->height = 0;
	map->fd = 0;
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->player = malloc(sizeof(t_player));
	init_player(data->player);
	if (!data->player)
		return (free(data), NULL);
	data->window = malloc(sizeof(t_window));
	init_window(data->window);
	if (!data->window)
		return (free(data), free(data->player), NULL);
	data->ray = malloc(sizeof(t_ray));
	if (!data->ray)
		return (NULL);
	data->vector = malloc(sizeof(t_vector));
	if (!data->vector)
		return (NULL);
	data->map = malloc(sizeof(t_map));
	init_map(data->map);
	if (!data->map)
		return (free(data), free(data->player), free(data->window), NULL);
	data->keycode = 0;
	return (data);
}

