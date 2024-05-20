/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:03:51 by cabdli            #+#    #+#             */
/*   Updated: 2024/05/20 13:34:58 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_data(t_data **data)
{
	if (!(*data))
		return ;
	free_map_list(&(*data)->map_list, NULL);
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
	data->map_list = init_map_list(filename);
	if (!data->map_list)
		return (free_data(data), NULL);
	data->map_tab = init_map_tab(data->map_list);
	if (!data->map_tab)
		return (free_data(data), NULL);
	return (data);
}
