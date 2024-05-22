/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:03:13 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/22 19:00:34 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_data(t_data **data)
{
	if (!(*data))
		return ;
	free_map_list(&(*data)->map->map_list, NULL);
	free_map_tab();
	free(*data);
	*data = NULL;
}

t_data	*init_data(char *filename)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(data));
	if (!data)
		return (NULL);
    data->player = ft_calloc(1, sizeof(t_player));
	if (!data->player)
		return (free_data(data), NULL);
    data->window = init_window(data->window);
		return (free_data(data), NULL);
    data->ray = ft_calloc(1, sizeof(t_ray));
	if (!data->ray)
		return (free_data(data), NULL);
    data->vector = ft_calloc(1, sizeof(t_vector));
	if (!data->vector)
		return (free_data(data), NULL);
    data->map = init_map(filename);
    if (!data->map)
		return (free_data(data), NULL);
    
	return (data);
}
