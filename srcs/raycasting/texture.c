/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:45:10 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/24 11:58:26 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


int get_texture_color(t_texture *texture, int x, int y)
{
    char    *pixel;
    int     color;

    pixel = texture->addr + (y * texture->size_line + x * (texture->bpp / 8));
    color = *(int *)pixel;
    return (color);
}


int calculate_texture_num(t_data *data)
{
    if (data->ray->side == 0)
    {
        if (data->ray->ray_dir.x > 0)
            return (2); // Sud (rayon venant de l'ouest)
        else
            return (0); // Nord (rayon venant de l'est)
    }
    else
    {
        if (data->ray->ray_dir.y > 0)
            return (3); // Est (rayon venant du nord)
        else
            return (1); // Ouest (rayon venant du sud)
    }
}


double calculate_wall_x(t_data *data)
{
    if (data->ray->side == 0)
        data->map->wall_x = data->player->pos.y + data->ray->perpwalldist * data->ray->ray_dir.y;
    else
        data->map->wall_x = data->player->pos.x + data->ray->perpwalldist * data->ray->ray_dir.x;
    data->map->wall_x -= floor(data->map->wall_x);
    return (data->map->wall_x);
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

