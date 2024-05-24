/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:52:40 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/24 12:45:31 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_map	*init_map(char *filename)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	if (init_lists(map, filename))
		return (free_lists(map), NULL);
	if (init_tabs(map))
		return (free_tabs(map), NULL);
	return (map);
}
