/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:46:12 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/30 17:53:03 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_texture(t_texture *texture, void *mlx_ptr, char *filepath)
{
	texture->img_ptr = mlx_xpm_file_to_image(mlx_ptr, filepath, &texture->width, &texture->height);
	if (!texture->img_ptr)
	{
		perror("Error");
		exit(1);
	}
	texture->addr = mlx_get_data_addr(texture->img_ptr, &texture->bpp, &texture->size_line, &texture->endian);
}
void    init_textures(t_data *data)
{
	init_texture(&data->texture[0], data->window->mlx_ptr, data->map->north_texture);
	init_texture(&data->texture[1], data->window->mlx_ptr, data->map->south_texture);
	init_texture(&data->texture[2], data->window->mlx_ptr, data->map->west_texture);
	init_texture(&data->texture[3], data->window->mlx_ptr, data->map->east_texture);
}

void	extract_texture_paths(t_map *map)
{
	t_list	*current;
	char	*line;

	current = map->text_list;
	while (current)
	{
		line = current->line;
		if (!ft_strncmp(line, "NO ", 3))
			map->north_texture = ft_strdup(line + 3);
		else if (!ft_strncmp(line, "SO ", 3))
			map->south_texture = ft_strdup(line + 3);
		else if (!ft_strncmp(line, "WE ", 3))
			map->west_texture = ft_strdup(line + 3);
		else if (!ft_strncmp(line, "EA ", 3))
			map->east_texture = ft_strdup(line + 3);
		current = current->next;
	}
}
