/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:03:51 by cabdli            #+#    #+#             */
/*   Updated: 2024/05/20 12:53:17 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_map_in_tab(char *filename, t_data *data)
{
	t_map	*map_lst;
	int		i;
	t_map	*tmp;
	int		m;

	i = 0;
	m = 0;
	map_lst = map_in_list(filename, &m);
	if (!map_lst && m == 0)
		return (ft_printf("Error, the map is empty, (or malloc error)!\n"), 0);
	if (!map_lst && m == 1)
		return (0);
	data->map = ft_calloc((list_size(map_lst)) + 1, sizeof (char *));
	if (!data->map)
		return (free_map_in_list(map_lst, NULL), 0);
	while (map_lst)
	{
		tmp = map_lst;
		map_lst = map_lst->next;
		data->map[i++] = tmp->line;
		free(tmp);
	}
	return (1);
}

t_data	*init_data(char *filename)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(data));
	if (!data)
		return (NULL);
	data->map_list = init_map_list(filename);
	if (!data->map_list)
		return (free(data), NULL);
	data->map_tab = init_map_tab(data->map_list);
	if (!data->map_tab)
		return (free_data(data), NULL);
	return (data);
}
