/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:54:24 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/07 17:56:28 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
		if (ft_strncmp(map->map_tab[i], "\n", 2) && len < map->width)
			ft_memset(new_tab[i] + len, '1', (map->width - len));
	}
	map->map_tab = new_tab;
	free_tab(&tmp);
	return (0);
}

void	fill_spaces(char **tab)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == ' ')
				tab[i][j] = '1';
		}
	}
}

int	parsing(t_map *map)
{
	calculate_map_dimensions(map->map_tab, map);
	// dup_tab(map);
	fill_spaces(map->map_tab);
	printf("\n\n");
	print_tab(map->map_tab);
	if (parse_colors(map->color_tab))
		return (1);
	if (parse_textures(map->text_tab))
		return (1);
	if (parse_map(map->map_tab))
		return (1);
	return (0);
}
