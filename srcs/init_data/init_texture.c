/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:46:12 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/03 18:15:00 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	init_text(t_texture *texture, void *mlx_ptr, char *filepath)
{
	texture->img_ptr = mlx_xpm_file_to_image(mlx_ptr, filepath, \
	&texture->width, &texture->height);
	if (!texture->img_ptr)
		return (perror("Error"), 1);
	texture->addr = mlx_get_data_addr(texture->img_ptr, &texture->bpp, \
	&texture->size_line, &texture->endian);
	return (0);
}

void	extract_text_paths(char **tab, t_texture **texture)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (!ft_strncmp(tab[i], "NO", 2))
			texture[NORTH]->text_path = get_text_path(tab[i]);
		else if (!ft_strncmp(tab[i], "SO", 2))
			texture[SOUTH]->text_path = get_text_path(tab[i]);
		else if (!ft_strncmp(tab[i], "WE", 2))
			texture[WEST]->text_path = get_text_path(tab[i]);
		else if (!ft_strncmp(tab[i], "EA", 2))
			texture[EAST]->text_path = get_text_path(tab[i]);
	}
}

int	init_textures(t_data *data)
{
	int	dir;

	dir = -1;
	extract_text_paths(data->map->text_tab, data->texture);
	while (++dir < 4)
	{
		if (init_text(data->texture[dir], data->window->mlx_ptr, \
		data->texture[dir]->text_path))
			return (1);
	}
	return (0);
}

