/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:54:24 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/05 16:14:47 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	create_parse_tabs(t_map *map, int *texture, int *color)
{
	int	i;

	i = 0;
	while (map->text_color_tab[i] != NULL)
	{
		if (!ft_strncmp(map->text_color_tab[i], "NO", 2) || \
		!ft_strncmp(map->text_color_tab[i], "SO", 2) || \
		!ft_strncmp(map->text_color_tab[i], "WE", 2) || \
		!ft_strncmp(map->text_color_tab[i], "EA", 2))
		{
			(*texture)++;
		}
		else if (!ft_strncmp(map->text_color_tab[i], "F", 1) || \
		!ft_strncmp(map->text_color_tab[i], "C", 1))
		{
			(*color)++;
		}
		i++;
	}
	map->text_tab = ft_calloc(*texture + 1, sizeof(char *));
	map->color_tab = ft_calloc(*color + 1, sizeof(char *));
	if (!map->text_tab || !map->color_tab)
		return (1);
	return (0);
}

int	fill_tabs(t_map *map)
{
	int	i;
	int	texture;
	int	color;

	i = -1;
	texture = 0;
	color = 0;
	while (map->text_color_tab[++i] != NULL)
	{
		if (!ft_strncmp(map->text_color_tab[i], "NO", 2) || \
		!ft_strncmp(map->text_color_tab[i], "SO", 2) || \
		!ft_strncmp(map->text_color_tab[i], "WE", 2) || \
		!ft_strncmp(map->text_color_tab[i], "EA", 2))
		{
			map->text_tab[texture] = map->text_color_tab[i];
			texture++;
		}
		else if (!ft_strncmp(map->text_color_tab[i], "F", 1) || \
		!ft_strncmp(map->text_color_tab[i], "C", 1))
		{
			map->color_tab[color] = map->text_color_tab[i];
			color++;
		}
	}
	return (0);
}

int	parse_colors_and_textures(t_map *map)
{
	int	texture;
	int	color;

	texture = 0;
	color = 0;
	if (create_parse_tabs(map, &texture, &color))
		return (1);
	fill_tabs(map);
    // if (texture != 4 || color != 2)
    // {
    //     free(map->text_tab);
    //     free(map->color_tab);
    //     return (print_err(MISS_DUP_C), 1);
    // }
	if (parse_textures(map->text_tab))
		return (1);
	if (parse_colors(map->color_tab))
		return (1);
	return (0);
}

int	parsing(t_map *map)
{
	if (parse_colors_and_textures(map))
		return (1);
	if (parse_map(map->map_tab))
		return (1);
	return (0);
}
// int	parsing(t_map *map)
// {
// 	if (parse_colors(map->color_tab))
// 		return (1);
// 	if (parse_textures(map->text_tab))
// 		return (1);
// 	if (parse_map(map->map_tab))
// 		return (1);
// 	return (0);
// }