/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:31:20 by cabdli            #+#    #+#             */
/*   Updated: 2024/05/24 16:33:57 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	calculate_map_dimensions(t_map *map)
{
	t_list	*current;
	int		max_width;
	int		height;
	int		line_length;

	current = map->map_list;
	max_width = 0;
	height = 0;
	while (current)
	{
		line_length = ft_strlen(current->line);
		if (line_length > max_width)
		{
			max_width = line_length;
		}
		height++;
		current = current->next;
	}
	map->height = height;
	map->width = max_width;
}
