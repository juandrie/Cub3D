/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:46:12 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/04 14:18:13 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	extract_text_paths(char **tab, t_texture **texture)
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


static int	init_textures(t_texture **texture, t_data *data)
{
	int	dir;

	dir = -1;
	extract_text_paths(data->map->text_tab, texture);
	while (++dir < 4)
	{
		if (init_text(texture[dir], data->window->mlx_ptr, \
		texture[dir]->text_path))
			return (1);
	}
	return (0);
}

t_texture	**create_texture(t_data *data)
{
	t_texture	**texture;
	int			i;

	i = -1;
	texture = ft_calloc(4, sizeof(t_texture *));
	if (!texture)
		return (NULL);
	while (++i < 4)
	{
		texture[i] = ft_calloc(1, sizeof(t_texture));
		if (!texture[i])
			return (free_textures(&texture), NULL);
	}
	if (init_textures(texture, data))
		return (NULL);
	return (texture);
}
