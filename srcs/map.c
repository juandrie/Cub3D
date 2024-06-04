/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:28:22 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/04 14:22:46 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"

/

// int	process_line(t_data *data, char *line)
// {
// 	if (ft_strncmp(line, "NO ", 3) == 0)
// 		return (parse_texture(line, &data->map->north_texture));
// 	if (ft_strncmp(line, "SO ", 3) == 0)
// 		return (parse_texture(line, &data->map->south_texture));
// 	if (ft_strncmp(line, "WE ", 3) == 0)
// 		return (parse_texture(line, &data->map->west_texture));
// 	if (ft_strncmp(line, "EA ", 3) == 0)
// 		return (parse_texture(line, &data->map->east_texture));
// 	if (ft_strncmp(line, "WE ", 3) == 0)
// 		return (parse_texture(line, &data->map->west_texture));
// 
// 	if (line[0] == '0' || line[0] == '1' || line[0] == 'N' || line[0] == 'S' || line[0] == 'E' || line[0] == 'W')
// 		return (add_line_to_map(data, line));
// 	return (1);
// }

// int	read_map(t_data *data)
// {
// 	char	*line;

// 	data->map->fd = open(data->map->filename, O_RDONLY);
// 	if (data->map->fd < 0)
// 		return (0);
// 	data->player_initialized = 0;
// 	while ((line = get_next_line(data->map->fd)))
// 	{
// 		if (!process_line(data, line))
// 		{
// 			close(data->map->fd);
// 			free(line);
// 			return (0);
// 		}
// 		free(line);
// 	}
// 	close(data->map->fd);
// 	if (!init_player_position(data))//(!data->player_initialized)
// 	{
//         printf("Error: No player start position found.\n");
//         return (0);
//     }
// 	return (1);
// }
