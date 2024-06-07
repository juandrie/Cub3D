/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:14:53 by cabdli            #+#    #+#             */
/*   Updated: 2024/06/07 15:48:22 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_list(t_list **list)
{
	t_list	*tmp;

	tmp = NULL;
	if (!(*list))
		return ;
	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		if (tmp->line)
			free(tmp->line);
		free(tmp);
	}
	*list = NULL;
}

void	free_lists(t_map *map)
{
	free_list(&(map->map_list));
	free_list(&(map->text_color_list));
}

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
	if(!tab)
		return ;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_tabs(t_map *map)
{
	free_tab(&map->color_tab);
	free_tab(&map->text_tab);
	free_full_tab(map->map_tab);
}

void	free_map(t_map **map)
{
	if (!(*map))
		return ;
	free_lists(*map);
	free_tabs((*map));
	free(*map);
	*map = NULL;
}
