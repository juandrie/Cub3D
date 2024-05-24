/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:53:09 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/24 13:23:06 by juandrie         ###   ########.fr       */
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

static int	add_node_bottom(t_list **list, char *line, t_list **tmp)
{
	if (!(*list))
	{
		(*list) = new_node(line);
		if (!(*list))
			return (1);
		*tmp = *list;
	}
	else
	{
		(*tmp)->next = new_node(line);
		if (!((*tmp)->next))
			return (1);
		*tmp = (*tmp)->next;
	}
	return (0);
}

static int	fill_list(t_list **list, char *line, int elemt)
{
	static t_list	*tmp_map;
	static t_list	*tmp_color;
	static t_list	*tmp_text;

	if (elemt == 0)
		return (add_node_bottom(list, line, &tmp_text));
	else if (elemt == 1)
		return (add_node_bottom(list, line, &tmp_color));
	else
		return (add_node_bottom(list, line, &tmp_map));
	return (1);
}

static int	process_line(t_map *map, char *line)
{
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) || \
	!ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		return (fill_list(&(map->text_list), line, 0));
	if (!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
		return (fill_list(&(map->color_list), line, 1));
	if (line[0] == ' ' || line[0] == '	' || line[0] == '0' || \
	line[0] == '1' || line[0] == 'N' || line[0] == 'S' || \
	line[0] == 'E' || line[0] == 'W')
		return (fill_list(&(map->map_list), line, 2));
	return (0);
}
void calculate_map_dimensions(t_map *map)
{
    t_list	*current;
    int		max_width;
    int		height;
	int		line_length;

	current = map->map_list;
	max_width = 0;
	height = 0;
    while (current)
	{
        line_length = ft_strlen(current->line);
        if (line_length > max_width)
		{
            max_width = line_length;
        }
        height++;
        current = current->next;
    }
    map->height = height;
    map->width = max_width;
}

int	init_lists(t_map *map, char *filename)
{
	char	*line;
	int		fd;

	line = NULL;
	if (open_fd(&fd, filename))
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		ft_replace_nl(line);
		if (process_line(map, line))
			return (free(line), close(fd), 1);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		return (perror(""), 1);
	calculate_map_dimensions(map); 
	extract_texture_paths(map);
	return (0);
}
