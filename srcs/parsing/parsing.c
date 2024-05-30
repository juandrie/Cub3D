/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:54:24 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/30 14:15:13 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	parsing(t_map *map)
{
	if (parse_colors(map->color_tab))
		return (1);
	// if (parse_textures())
	// 	return (1);
	if (parse_map(map->map_tab))
		return (1);
	return (0);
}
