/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:45:10 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/20 18:06:43 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_texture_color(t_texture *texture, int x, int y)
{
    char *pixel;
    int color;

    pixel = texture->addr + (y * texture->size_line + x * (texture->bpp / 8));
    color = *(int *)pixel;
    return (color);
}


int calculate_texture_num(t_data *data)
{
    char    map_value;
    int     x;
    int     y;
    int     texture_num;

    x = (int)data->ray->map.x;
    y = (int)data->ray->map.y;
    if (x >= 0 && x < data->map->width && y >= 0 && y < data->map->height)
    {
        map_value = data->map->map[y][x];
        if (map_value == '1')
            texture_num = 0;
        else if (map_value == 'N' || map_value == 'S' || map_value == 'E' || map_value == 'W')
            texture_num = 1;
        else
            texture_num = -1;
        return (texture_num);
    }
    return (-1);
}

double calculate_wall_x(t_data *data)
{
    if (data->ray->side == 0)
        data->map->wall_x = data->player->pos.y + data->ray->perpwalldist * data->ray->ray_dir.y;
    else
        data->map->wall_x = data->player->pos.x + data->ray->perpwalldist * data->ray->ray_dir.x;
    return (data->map->wall_x - floor(data->map->wall_x));
}
int calculate_texture_x(t_data *data)
{
    data->map->texture.x = (int)(data->map->wall_x * (double)(data->texture->width));
    if (data->ray->side == 0 && data->ray->ray_dir.x > 0)
        data->map->texture.x = data->texture->width - data->map->texture.x - 1;
    if (data->ray->side == 1 && data->ray->ray_dir.y < 0)
        data->map->texture.x = data->texture->width - data->map->texture.x - 1;
    return (data->map->texture.x);
}

