/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lists_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:57:43 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/27 14:27:31 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	open_fd(int *fd, char *filename)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		return (perror("Error"), 1);
	return (0);
}

int	ft_replace_nl(t_map *map, char *line)
{
	int	len;

	len = (int)ft_strlen(line);
	if (len == 1 && !map->map_list)
		return (1);
	if (len > 1 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (0);
}

int	list_size(t_list *list)
{
	int	size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}
