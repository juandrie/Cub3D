/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:54:24 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/06 13:01:12 by cabdli           ###   ########.fr       */
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
// 	if (parse_map(map->map_tab))
// 		return (1);
// 	return (0);
// }

int	parsing(t_map *map)
{
	if (parse_colors(map->color_tab))
		return (1);
	if (parse_textures(map->text_tab))
		return (1);
	if (parse_map(map->map_tab))
		return (1);
	return (0);
}