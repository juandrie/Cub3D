/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:47:41 by cabdli            #+#    #+#             */
/*   Updated: 2024/05/20 13:37:43 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_map	*new_node(char *str)
{
	t_map	*new;

	new = ft_calloc(1, sizeof(t_map));
	if (!new)
		return (perror(""), NULL);
	new->line = str;
	return (new);
}

static int	add_node_bottom(t_map **map, char *str)
{
	static t_map	*tmp;

	if (!(*map))
	{
		(*map) = new_node(str);
		if (!(*map))
			return (0);
		tmp = *map;
	}
	else
	{
		tmp->next = new_node(str);
		if (!(tmp->next))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_map	*init_map_list(char *filename)
{
	t_map		*map;
	char		*line;
	int			fd;

	map = NULL;
	line = NULL;
	if (open_fd(&fd, filename))
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		replace_nl(line);
		if (!add_node_bottom(&map, line))
			return (free_map_list(&map, line), close(fd), NULL);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		return (perror(""), NULL);
	return (map);
}
