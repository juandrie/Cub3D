/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:34:33 by cabdli            #+#    #+#             */
/*   Updated: 2024/05/20 13:46:11 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**init_map_tab(t_data *data)
{
	int		i;
	t_map	*list;
	char	**tab;
	t_map	*tmp;

	i = 0;
	list = data->map_list;
	tmp = NULL;
	tab = ft_calloc((list_size(list)) + 1, sizeof(char *));
	if (!tab)
		return (free_data(&data), NULL);
	while (list)
	{
		tab[i++] = list->line;
		list = list->next;
	}
	return (tab);
}
