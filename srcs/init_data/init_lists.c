/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:53:09 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/24 18:20:17 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static t_list	*new_node(char *str)
{
	t_list	*new;

	new = ft_calloc(1, sizeof(t_map));
	if (!new)
		return (perror("Error"), NULL);
	new->line = str;
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

// static int	fill_list(t_list **list, char *line, int elemt)
// {
// 	static t_list	*tmp_map;
// 	static t_list	*tmp_color;
// 	static t_list	*tmp_text;

// 	if (elemt == 0)
// 		return (add_node_bottom(list, line, &tmp_text));
// 	else if (elemt == 1)
// 		return (add_node_bottom(list, line, &tmp_color));
// 	else
// 		return (add_node_bottom(list, line, &tmp_map));
// 	return (1);
// }

/*
if (line[0] == ' ' || line[0] == '	' || line[0] == '0' || \
	line[0] == '1' || line[0] == 'N' || line[0] == 'S' || \
	line[0] == 'E' || line[0] == 'W')
*/

static int	process_line(t_map *map, char *line)
{
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) || \
	!ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		return (add_node_bottom(&(map->text_list), line));
	else if (!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
		return (add_node_bottom(&(map->color_list), line));
	// else if (!ft_strncmp(line, "\n", 2)|| !ft_strncmp(line, " ", 2) || \
	// !ft_strncmp(line, "\t", 2) || !ft_strncmp(line, "\r", 2) || \
	// !ft_strncmp(line, "\v", 2))
	// 	return (free(line), 0);
	else
		return (add_node_bottom(&(map->map_list), line));
	return (0);
}

int	init_lists(t_map *map, char *filename)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	line = NULL;
	if (open_fd(&fd, filename))
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("LINE %d = %s$\n", ++i, line);
		if (!ft_replace_nl(map, line))
		{
			printf("LINE %d = %s$\n", i, line);
			printf("\n\n");
			if (process_line(map, line))
				return (free(line), close(fd), 1);
		}
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		return (perror("Error"), 1);
	// calculate_map_dimensions(map); 
	// extract_texture_paths(map);
	return (0);
}
