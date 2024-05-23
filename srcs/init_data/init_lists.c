/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:53:09 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/23 13:04:27 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_list	*new_node(char *str)
{
	t_list	*new;

	new = ft_calloc(1, sizeof(t_map));
	if (!new)
		return (perror(""), NULL);
	new->line = str;
	return (new);
}

static int	add_node_bottom(t_list **map, char *str)
{
	static t_list	*tmp;

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

int	process_line(t_map *map, char *line)
{
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) || \
    !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		return (add_node_bottom(&(map->text_list), line));
	if (!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
		return (add_node_bottom(&(map->color_list), line));
	if (line[0] == '0' || line[0] == '1' || line[0] == 'N' || \
    line[0] == 'S' || line[0] == 'E' || line[0] == 'W')
		return (add_node_bottom(&(map->map_list), line));
	return (1);
}

int init_lists(t_map *map, char *filename)
{
	char		    *line;
	int			    fd;

	line = NULL;
	if (open_fd(&fd, filename))
		return (0);
	line = get_next_line(fd);
	printf("%s\n", line);
	while (line)
	{
		ft_replace_nl(line);
        if (!process_line(map, line))
			return (free_map_lists(map), close(fd), 0);
		line = get_next_line(fd);
		printf("%s\n", line);
	}
	if (close(fd) == -1)
		return (perror(""), 0);
	return (1);
}
