/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:07:01 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/10 17:07:36 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_line(char **line)
{
	free(*line);
	*line = NULL;
}

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
			free_line(&(tmp->line));
		free(tmp);
	}
	*list = NULL;
}

void	free_lists(t_map *map)
{
	free_list(&(map->map_list));
	free_list(&(map->text_color_list));
}
