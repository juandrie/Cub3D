/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:31:20 by cabdli            #+#    #+#             */
/*   Updated: 2024/06/04 17:08:37 by cabdli           ###   ########.fr       */
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

void	start_the_game(t_data *data)
{
	calculate_map_dimensions(data->map->map_tab, data->map);
	get_player_pos(data);
	hooks(data);
}
