/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:28:22 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/21 17:44:08 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	add_line_to_map(t_data *data, char *line)
{
	char	**temp;
	int		i;

	temp = malloc(sizeof(char *) * (data->map->height + 2));
	if (!temp)
		return (0);
	i = 0;
	while (i < data->map->height)
	{
		temp[i] = data->map->map[i];
		i++;
	}
	temp[i++] = ft_strdup(line);
	temp[i] = NULL;
	free(data->map->map);
	data->map->map = temp;
	data->map->height++;
	if (ft_strlen(line) > data->map->width)
        data->map->width = ft_strlen(line);
	return (1);
}

int	parse_texture(char *line, char **texture)
{
	*texture = ft_strdup(ft_strchr(line, ' ') + 1);
	if (*texture != NULL)
		return (1);
	return (0);
}

int	parse_color(char *line, int color[3])
{
	char	**rgb;
	int		i;

	rgb = ft_split(ft_strchr(line, ' ') + 1, ',');
	if (!rgb)
		return (0);
	i = 0;
	while (i < 3)
	{
		color[i] = ft_atoi(rgb[i]);
		free(rgb[i]);
		i++;
	}
	free(rgb);
	return (1);
}

int	process_line(t_data *data, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (parse_texture(line, &data->map->north_texture));
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (parse_texture(line, &data->map->south_texture));
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (parse_texture(line, &data->map->west_texture));
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (parse_texture(line, &data->map->east_texture));
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (parse_texture(line, &data->map->west_texture));
	if (ft_strncmp(line, "F ", 2) == 0)
		return (parse_color(line, data->map->floor_color));
	if (ft_strncmp(line, "C ", 2) == 0)
		return (parse_color(line, data->map->ceiling_color));
	if (line[0] >= '0' && line[0] <= '9')
		return (add_line_to_map(data, line));
	return (1);
}

int	read_map(t_data *data)
{
	char	*line;

	data->map->fd = open(data->map->filepath, O_RDONLY);
	if (data->map->fd < 0)
		return (0);
	while ((line = get_next_line(data->map->fd)))
	{
		if (!process_line(data, line))
		{
			close(data->map->fd);
			free(line);
			return (0);
		}
		free(line);
	}
	close(data->map->fd);
	return (1);
}
