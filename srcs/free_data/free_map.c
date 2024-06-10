/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:14:53 by cabdli            #+#    #+#             */
/*   Updated: 2024/06/10 17:07:30 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_tab(char ***tab)
{
	if (!(*tab))
		return ;
	free(*tab);
	*tab = NULL;
}

void	free_full_tab(char **tab)
{
	int	i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
}

void	free_tabs(t_map *map, int tab)
{
	free_tab(&map->color_tab);
	free_tab(&map->text_tab);
	if (tab)
		free_tab(&map->map_tab);
	else
		free_full_tab(map->map_tab);
}

void	free_map(t_map **map, int tab)
{
	if (!(*map))
		return ;
	free_lists(*map);
	free_tabs((*map), tab);
	free(*map);
	*map = NULL;
}
