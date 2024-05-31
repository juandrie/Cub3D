/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:18:40 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/31 12:57:01 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"



int	check_borders(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (is_space_or_one(map->map_tab[0][i]) || \
		is_space_or_one(map->map_tab[map->height - 1]))
			return (1);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (is_space_or_one(map->map_tab[0][i]) || \
		is_space_or_one(map->map_tab[map->width - 2]))
			return (1);
		i++;
	}
	return (0);
}

int	parse_map(t_map *map)
{
	// if (map_missing(tab))
	// 	return (print_err(EMPTY), 1);
	// if (empty_line(tab))
	// 	return (print_err(EMPTY_L), 1);
	// if (wrong_char(tab))
	// 	return (print_err(WRONG_C), 1);
	// if (no_player(tab))
	// 	return (print_err(NO_PLAYER), 1);
	// if (too_much_players(tab))
	// 	return (print_err(MUCH_PLAYERS), 1);
	// if (player_on_edge(tab))
	// 	return (print_err(MUCH_PLAYERS), 1);
	if (check_borders(map))
		return (print_err(MAP_BORDERS), 1);
	return (0);
}