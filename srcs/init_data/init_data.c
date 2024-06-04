/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:03:13 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/04 17:49:47 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	init_first_step(t_data **data, char *filename)
{
	*data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (perror("Error"), 1);
	(*data)->map = init_map(filename);
	if (!(*data)->map)
		return (free_data(data), 1);
	return (0);
}

int	init_second_step(t_data **data)
{
	int	i;

	i = -1;
	(*data)->window = init_window();
	if (!(*data)->window)
		return (free_data(data), 1);
	(*data)->texture = ft_calloc(1, sizeof(t_texture));
	if (!(*data)->texture)
		return (free_data(data), 1);
	(*data)->text_path = create_text_path(*data);
	if (!(*data)->text_path)
		return (free_data(data), 1);
	if (init_colors((*data)->map->color_tab, \
	(*data)->map->ceiling_color, (*data)->map->floor_color))
		return (free_data(data), 1);
	(*data)->player = ft_calloc(1, sizeof(t_player));
	if (!(*data)->player)
		return (free_data(data), 1);
	(*data)->ray = ft_calloc(1, sizeof(t_ray));
	if (!(*data)->ray)
		return (free_data(data), 1);
	(*data)->vector = ft_calloc(1, sizeof(t_vector));
	if (!(*data)->vector)
		return (free_data(data), 1);
	return (0);
}

int	init_data(t_data **data, char *filename, int step)
{

	if (step == 0)
	{
		if (init_first_step(data, filename))
			return (1);
	}
	else
	{
		if (init_second_step(data))
			return (1);
	}
	return (0);
}
