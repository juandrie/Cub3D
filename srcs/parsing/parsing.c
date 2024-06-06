/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:54:24 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/06 19:40:45 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

// int	parse_colors_and_textures(t_map *map)
// {
//     // if (texture != 4 || color != 2)
//     // {
//     //     free(map->text_tab);
//     //     free(map->color_tab);
//     //     return (print_err(MISS_DUP_C), 1);
//     // }
// 	if (parse_textures(map->text_tab))
// 		return (1);
// 	if (parse_colors(map->color_tab))
// 		return (1);
// 	return (0);
// }

// int	parsing(t_map *map)
// {
// 	if (parse_colors_and_textures(map))
// 		return (1);
// 	if (parse_map(map->map_tab))f
// 		return (1);
// 	return (0);
// }

int	find_map_width(char **tab)
{
	int	i;
	int	len;
	int	longer;

	i = -1;
	len = 0;
	longer = 0;
	while (tab[++i])
	{
		len = ft_strlen(tab[i]);
		if (len > longer)
			longer = len;
	}
	return (longer);
}

void	calculate_map_dimensions(char **tab, t_map *map)
{
	map->height = tab_size(tab);
	map->width = find_map_width(tab);
}

int	dup_tab(t_map *map)
{
	int		i;
	int		len;
	char	**tmp;
	char	**new_tab;

	i = -1;
	len = 0;
	tmp = map->map_tab;
	new_tab = ft_calloc(map->height + 1, sizeof(char *));
	while (++i < map->height)
	{
		new_tab[i] = ft_calloc(map->width + 1, sizeof(char));
		ft_strcpy(new_tab[i], map->map_tab[i]);
		len = ft_strlen(map->map_tab[i]);
		if (len < map->width)
			ft_memset(new_tab[i] + len, '1', (map->width - len));
	}
	map->map_tab = new_tab;
	free_tab(&tmp);
	return (0);
}

int	parsing(t_map *map)
{
	calculate_map_dimensions(map->map_tab, map);

	dup_tab(map);
	if (parse_colors(map->color_tab))
		return (1);
	if (parse_textures(map->text_tab))
		return (1);
	if (parse_map(map->map_tab))
		return (1);
	return (0);
}