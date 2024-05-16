/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:28:22 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/16 18:56:25 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int add_line_to_map(t_data *data, char *line)
{
    char **temp;
    int i;

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
    return (1);
}

int read_map(t_data *data)
{
    char    *line;
    
    data->map->fd = open(data->map->filepath, O_RDONLY);
    if (data->map->fd < 0)
        return (0);
    while ((line = get_next_line(data->map->fd)))
    {
        if (!data->map->width)
            data->map->width = ft_strlen(line);
        if(!add_line_to_map(data, line))
        {
            close(data->map->fd);
            free(line);
            return (0);
        }
        free(line);
    }
    close(data->map->fd);
    return(1);
}