/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:53:09 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/07 18:25:04 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_list	*new_node(char *str)
{
	t_list	*new;

	new = ft_calloc(1, sizeof(t_map));
	if (!new)
		return (perror("Error"), NULL);
	new->line = ft_strdup(str);
	if (!new->line)
		return (perror("Error"), NULL);
	return (new);
}

static int	add_node_bottom(t_list **list, char *line)
{
	static t_list	*tmp;

	if (!(*list))
	{
		(*list) = new_node(line);
		if (!(*list))
			return (1);
		tmp = *list;
	}
	else
	{
		tmp->next = new_node(line);
		if (!(tmp->next))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_map_position(char *line)
{
	static int	map;
	static int	text;
	static int	colors;

	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) || \
		!ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
			text = 1;
	else if (!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
		colors = 1;
	else
		map = 1;
	if (map && (!text || !colors))
	{
		ft_putstr_fd("Error:\nMap not in third position or Map alone\n", STDERR_FILENO);
		return (1);
	}
	return (0);
}

static int	process_line(t_map *map, char *line)
{
	char	*tmp;

	tmp = NULL;
	if (ft_replace_nl(map, line))
		return (0);
	tmp = skip_whitespace(line);
	if (check_map_position(line))
		return (1);
	if (!ft_strncmp(tmp, "NO", 2) || !ft_strncmp(tmp, "SO", 2) || \
		!ft_strncmp(tmp, "WE", 2) || !ft_strncmp(tmp, "EA", 2) || \
		!ft_strncmp(tmp, "F", 1) || !ft_strncmp(tmp, "C", 1))
		return (add_node_bottom(&(map->text_color_list), tmp));
	else
		return (add_node_bottom(&(map->map_list), line));
	return (0);
}

int	init_lists(t_map *map, char *filename)
{
	char	*line;
	int		fd;

	line = NULL;
	if (open_fd(&fd, filename))
		return (1);
	line = get_next_line(fd, map);
	if (!line)
		return (close(fd), print_err(EMPTY), 1);
	while (line)
	{
		if (process_line(map, line))
			return (free(map->save), free(line), close(fd), 1);
		free(line);
		line = get_next_line(fd, map);
	}
	if (close(fd) == -1)
		return (perror("Error"), 1);
	return (0);
}
 