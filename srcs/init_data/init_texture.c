/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:46:12 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/27 19:07:39 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_texture(t_texture *texture, void *mlx_ptr, char *filepath)
{
	texture->img_ptr = mlx_xpm_file_to_image(mlx_ptr, filepath, &texture->width, &texture->height);
	if (!texture->img_ptr)
	{
		printf("Error loading texture from %s\n", filepath);
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

// char	*skip_whitespace(char *str)
// {
//     while (*str == ' ' || *str == '\t' || *str == '\r' || *str == '\v')
//         str++;
//     return (str);
// }

void extract_texture_paths(t_map *map)
{
    t_list  *current;
    char    *line;
    char    *path;
    char    *full_path;

    current = map->text_list;
    while (current)
    {
        line = current->line;
        printf("texture: %s\n", line);
        if (!ft_strncmp(line, "NO", 2))
        {
            path = skip_whitespace(line + 2);
            full_path = ft_strjoin(path, ".xpm");
            map->north_texture = ft_strdup(full_path);
            free(full_path);
        } 
        else if (!ft_strncmp(line, "SO", 2))
        {
            path = skip_whitespace(line + 2);
            full_path = ft_strjoin(path, ".xpm");
            map->south_texture = ft_strdup(full_path);
            free(full_path);
        }
        else if (!ft_strncmp(line, "WE", 2))
        {
            path = skip_whitespace(line + 2);
            full_path = ft_strjoin(path, ".xpm");
            map->west_texture = ft_strdup(full_path);
            free(full_path);
        }
        else if (!ft_strncmp(line, "EA", 2))
        {
            path = skip_whitespace(line + 2);
            full_path = ft_strjoin(path, ".xpm");
            map->east_texture = ft_strdup(full_path);
            free(full_path);
        }
        current = current->next;
    }
}
