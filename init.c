/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:34:28 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/22 13:06:00 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


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
	window->bpp = 0;
	window->endian = 0;
	window->size_line = 0;
	window->img_ptr = mlx_new_image(window->mlx_ptr, window->width, window->height);
    window->img_data = mlx_get_data_addr(window->img_ptr, &window->bpp, &window->size_line, &window->endian);
}

void	init_map(t_map *map)
{
	map->map = NULL;
	map->filepath = ft_strdup("path_to_map_file");
	map->width = 0;
	map->height = 0;
	map->fd = 0;
	map->wall_x = 0;
	map->lineheight = 0;
	map->drawstart = 0;
	map->drawend = 0;
	map->texture.x = 0;
	map->texture.y = 0;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->east_texture = NULL;
	map->west_texture = NULL;
	map->text_pos = 0;
}

void init_texture(t_texture *texture, void *mlx_ptr, char *filepath)
{
	texture->img_ptr = NULL;
    texture->addr = NULL;
    texture->width = 0;
    texture->height = 0;
    texture->bpp = 0;
    texture->size_line = 0;
    texture->endian = 0; 
	texture->texture_num = 0;
	texture->img_ptr = mlx_xpm_file_to_image(mlx_ptr, filepath, &texture->width, &texture->height);
    if (!texture->img_ptr)
    {
        printf("Error loading texture from %s\n", filepath);
        exit(1);
    }
    texture->addr = mlx_get_data_addr(texture->img_ptr, &texture->bpp, &texture->size_line, &texture->endian);
}
t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->player = malloc(sizeof(t_player));
	if (!data->player)
		return (free(data), NULL);
	data->window = malloc(sizeof(t_window));
	if (!data->window)
		return (free(data->player), free(data), NULL);
	init_window(data->window);
	data->ray = malloc(sizeof(t_ray));
	if (!data->ray)
		return (free(data->window), free(data->player), free(data), NULL);
	data->vector = malloc(sizeof(t_vector));
	if (!data->vector)
		return (free(data->ray), free(data->window), free(data->player), free(data), NULL);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (free(data->vector), free(data->ray), free(data->window), free(data->player), free(data), NULL);
	init_map(data->map);
	data->texture = malloc(sizeof(t_texture) * 4);
	if (!data->texture)
		return (free(data), free(data->player), free(data->window), free(data->map), NULL);
	init_texture(&data->texture[0], data->window->mlx_ptr, "path_to_north_texture.xpm");
	init_texture(&data->texture[1], data->window->mlx_ptr, "path_to_south_texture.xpm");
	init_texture(&data->texture[2], data->window->mlx_ptr, "path_to_west_texture.xpm");
	init_texture(&data->texture[3], data->window->mlx_ptr, "path_to_east_texture.xpm");
	data->keycode = 0;
	return (data);
}

