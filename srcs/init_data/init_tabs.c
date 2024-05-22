/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:28:27 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/22 19:00:49 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	**init_tab(t_list *list)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_calloc((list_size(list)) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	while (list)
	{
		tab[i++] = list->line;
		list = list->next;
	}
	return (tab);
}

int init_tabs(t_map *map)
{
	map->map_tab = init_tab(map->map_list);
	if (!map->map_tab)
		return (0);
	map->color_tab = init_tab(map->color_list);
	if (!map->color_tab)
		return (0);
	map->text_tab = init_tab(map->text_list);
	if (!map->text_tab)
		return (0);
}
