/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:47:41 by cabdli            #+#    #+#             */
/*   Updated: 2024/05/14 15:54:20 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_map	*init_map_list(char *filename)
{
	int			fd;
	static int	len;
	t_map		*map;
	static char	*line;

	map = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (perror(""), NULL);
	line = get_next_line(fd);
	while (line)
	{
		// if (!ft_strncmp(line, "wrong_char", 10))
		// 	return (free_map_in_list(map, NULL), close(fd), *m = 1, NULL);
		len = (int)ft_strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (!add_node_bottom(&map, line))
			return (free_map_in_list(map, line), close(fd), NULL);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		return (perror(""), NULL);
	return (map);
}
