/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:03:13 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/23 12:52:17 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_data(t_data **data)
{
	if (!(*data) || !(*data))
		return ;
	if ((*data)->map)
	{
        free_map_lists((*data)->map);
        free_tabs((*data)->map);
        free((*data)->map);
    }
    if ((*data)->player)
        free((*data)->player);
    if ((*data)->window)
	{
        mlx_destroy_window((*data)->window->mlx_ptr, (*data)->window->win_ptr);
        mlx_destroy_image((*data)->window->mlx_ptr, (*data)->window->img_ptr);
        free((*data)->window);
    }
    if ((*data)->ray)
        free((*data)->ray);
    if ((*data)->vector)
        free((*data)->vector);
    free(*data);
    *data = NULL;
}

// void init_texture(t_texture *texture, void *mlx_ptr, char *filepath)
// {
// 	texture->img_ptr = mlx_xpm_file_to_image(mlx_ptr, filepath, &texture->width, &texture->height);
//     if (!texture->img_ptr)
//     {
//         printf("Error loading texture from %s\n", filepath);
//         exit(1);
//     }
//     texture->addr = mlx_get_data_addr(texture->img_ptr, &texture->bpp, &texture->size_line, &texture->endian);
// }
t_data	*init_data(char *filename)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
    data->player = ft_calloc(1, sizeof(t_player));
	if (!data->player)
		return (free_data(&data), NULL);
    data->window = init_window();
	if (!data->window)
		return (free_data(&data), NULL);
    data->ray = ft_calloc(1, sizeof(t_ray));
	if (!data->ray)
		return (free_data(&data), NULL);
    data->vector = ft_calloc(1, sizeof(t_vector));
	if (!data->vector)
		return (free_data(&data), NULL);
    data->map = init_map(filename);
    if (!data->map)
		return (free_data(&data), NULL);
    data->texture = ft_calloc(4, sizeof(t_texture));
	// if (!data->texture)
	// 	return (free(data), free(data->player), free(data->window), free(data->map), NULL);
	// init_texture(&data->texture[0], data->window->mlx_ptr, "path_to_north_texture.xpm");
	// init_texture(&data->texture[1], data->window->mlx_ptr, "path_to_south_texture.xpm");
	// init_texture(&data->texture[2], data->window->mlx_ptr, "path_to_west_texture.xpm");
	// init_texture(&data->texture[3], data->window->mlx_ptr, "path_to_east_texture.xpm");
	return (data);
}
