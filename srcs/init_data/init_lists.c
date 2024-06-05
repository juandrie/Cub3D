/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:53:09 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/05 15:28:03 by juandrie         ###   ########.fr       */
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

// static int	process_line(t_map *map, char *line)
// {
// 	char	*tmp;

// 	tmp = skip_whitespace(line);
// 	if (ft_replace_nl(map, tmp))
// 		return (0);
// 	if (!ft_strncmp(tmp, "NO", 2) || !ft_strncmp(tmp, "SO", 2) || \
// 	!ft_strncmp(tmp, "WE", 2) || !ft_strncmp(tmp, "EA", 2))
// 		return (add_node_bottom(&(map->text_list), tmp));
// 	else if (!ft_strncmp(tmp, "F", 1) || !ft_strncmp(tmp, "C", 1))
// 		return (add_node_bottom(&(map->color_list), tmp));
// 	else
// 		return (add_node_bottom(&(map->map_list), line));
// 	return (0);
// }


static int process_line(t_map *map, char *line)
{
    char *tmp;

	tmp = skip_whitespace(line);
	if (ft_replace_nl(map, tmp))
		return (0);
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
	line = get_next_line(fd);
	if (!line)
		return (print_err(EMPTY), 1);
	while (line)
	{
		if (process_line(map, line))
			return (free(line), close(fd), 1);
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		return (perror("Error"), 1);
	return (0);
}
