/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:46:12 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/07 15:22:35 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	extract_text_paths(char **tab, char **texture)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (!ft_strncmp(tab[i], "NO", 2))
			texture[NORTH] = get_text_path(tab[i]);
		else if (!ft_strncmp(tab[i], "SO", 2))
			texture[SOUTH] = get_text_path(tab[i]);
		else if (!ft_strncmp(tab[i], "WE", 2))
			texture[WEST] = get_text_path(tab[i]);
		else if (!ft_strncmp(tab[i], "EA", 2))
			texture[EAST] = get_text_path(tab[i]);
	}
}

static int	init_text(t_texture *texture, void *mlx_ptr, char *filepath)
{
	texture->img_ptr = mlx_xpm_file_to_image(mlx_ptr, filepath, \
	&texture->width, &texture->height);
	if (!texture->img_ptr)
		return (perror("Error"), 1);
	texture->addr = mlx_get_data_addr(texture->img_ptr, &texture->bpp, \
	&texture->size_line, &texture->endian);
	return (0);
}

static int	init_textures(t_texture *texture, char **text_path, t_data *data)
{
	int	dir;

	dir = -1;
	while (++dir < 4)
	{
		if (init_text(&texture[dir], data->window->mlx_ptr, \
		text_path[dir]))
			return (1);
	}
	return (0);
}

char	**create_text_path(t_data *data)
{
	char	**text_path;
	int		i;

	i = -1;
	text_path = ft_calloc(4, sizeof(char *));
	if (!text_path)
		return (NULL);
	extract_text_paths(data->map->text_tab, text_path);
	if (init_textures(data->texture, text_path, data))
		return (NULL);
	return (text_path);
}
