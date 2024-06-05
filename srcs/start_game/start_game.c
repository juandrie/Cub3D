/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:31:20 by cabdli            #+#    #+#             */
/*   Updated: 2024/06/05 16:47:56 by juandrie         ###   ########.fr       */
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

	for (int i = 0; i < map->height; i++)
    {
        int len = ft_strlen(tab[i]);
        if (len < map->width)
        {
            char *new_line = ft_calloc(map->width + 1, sizeof(char));
            strcpy(new_line, tab[i]);
            ft_memset(new_line + len, ' ', map->width - len);
            tab[i] = new_line;
        }
    }
}

void	start_the_game(t_data *data)
{
	calculate_map_dimensions(data->map->map_tab, data->map);
	//printf("Map dimensions: width = %d, height = %d\n", data->map->width, data->map->height);
	get_player_pos(data);
	hooks(data);
}
