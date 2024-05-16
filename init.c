/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:34:28 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/16 18:36:53 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_player(t_player *player)
{
    player->pos.x = 22;
    player->pos.y = 12;
    player->dir.x = -1;
    player->dir.y = 0;
    player->plane.x = 0;
    player->plane.y = 0.66;
}

void init_window(t_window *window)
{
    window->mlx_ptr = mlx_init();
    window->win_ptr = mlx_new_window(window->mlx_ptr, 640, 480, "Cub3D");
    window->width = 640;
    window->height = 480;
    window->key_pressed = 0;
    window->running = 1;
    window->moveSpeed = 0;
    window->rotSpeed = 0;
}

void init_map(t_map *map)
{
    map->map = NULL;
    map->filepath = ft_strdup("path_to_map_file");
    map->width = 0;
    map->height = 0;
    map->fd = 0;
}

t_data *init_data()
{
    t_data *data = malloc(sizeof(t_data));
    data->player = malloc(sizeof(t_player));
    init_player(data->player);
    data->window = malloc(sizeof(t_window));
    init_window(data->window);
    data->ray = malloc(sizeof(t_ray)); 
    data->vector = malloc(sizeof(t_vector));
    data->map = malloc(sizeof(t_map));
    init_map(data->map);
    data->keycode = 0;
    return (data);
}

