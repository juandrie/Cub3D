/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:22:02 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/04 14:40:53 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*get_color_path(char *str)
{
	char	*path;

	path = str + 1;
	path = skip_whitespace(path);
	return (path);
}

int	extract_colors(char *tab, int color[3])
{
	char	**rgb;
	int		i;

	i = -1;
	tab = get_color_path(tab);
	rgb = ft_split(tab, ',');
	if (!rgb)
		return (1);
	while (++i < 3)
		color[i] = ft_atoi(rgb[i]);
	free_full_tab(rgb);
	return (0);
}

int	init_colors(char **tab, int *ceiling, int *floor)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (ft_strncmp(tab[i], "C", 1) == 0)
			extract_colors(tab[i], ceiling);
		else
			extract_colors(tab[i], floor);
	}
	return (0);
}

	// if (ft_strncmp(line, "F ", 2) == 0)
// 		return (parse_color(line, data->map->floor_color));
// 	if (ft_strncmp(line, "C ", 2) == 0)
// 		return (parse_color(line, data->map->ceiling_color));