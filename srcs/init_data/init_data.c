/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:03:13 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/31 18:29:28 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_data	*init_data(char *filename)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->map = init_map(filename, data);
	if (!data->map)
		return (print_err(data->error), free_data(&data), NULL);
	// data->window = init_window();
	// if (!data->window)
	// 	return (free_data(&data), NULL);
	// data->player = ft_calloc(1, sizeof(t_player));
	// if (!data->player)
	// 	return (free_data(&data), NULL);
	// data->ray = ft_calloc(1, sizeof(t_ray));
	// if (!data->ray)
	// 	return (free_data(&data), NULL);
	// data->vector = ft_calloc(1, sizeof(t_vector));
	// if (!data->vector)
	// 	return (free_data(&data), NULL);
	// data->texture = ft_calloc(4, sizeof(t_texture));
	// if (!data->texture)
	// 	return (free_data(&data), NULL);
	// init_textures(data);
	return (data);
}
