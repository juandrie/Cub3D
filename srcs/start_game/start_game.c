/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:31:20 by cabdli            #+#    #+#             */
/*   Updated: 2024/06/05 18:46:51 by juandrie         ###   ########.fr       */
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
	int		i;
	int		len;
	char	*new_line;

	map->height = tab_size(tab);
	map->width = find_map_width(tab);

	i = -1;
	while (++i < map->height)
	{
		len = ft_strlen(tab[i]);
		if (len < map->width)
		{
			new_line = ft_calloc(map->width + 1, sizeof(char));
			ft_strcpy(new_line, tab[i]);
			ft_memset(new_line + len, ' ', map->width - len);
			tab[i] = new_line;
		}
	}
}

void	start_the_game(t_data *data)
{
	calculate_map_dimensions(data->map->map_tab, data->map);
	get_player_pos(data);
	hooks(data);
}
