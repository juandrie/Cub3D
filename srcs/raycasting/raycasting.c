/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:29:32 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/30 18:13:19 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_textured_wall_slice(t_data *data)
{
	int		y;
	int		pixel_index;
	int		color;
	double	step;

	y = data->map->drawstart;
	step = 1.0 * data->texture[data->texture->texture_num].height \
	/ data->map->lineheight;
	data->map->text_pos = (data->map->drawstart - HEIGHT / 2 \
	+ data->map->lineheight / 2) * step;
	while (y < data->map->drawend)
	{
		data->map->texture.y = (int)data->map->text_pos & \
		(data->texture[data->texture->texture_num].height - 1);
		data->map->text_pos += step;
		color = get_texture_color(&data->texture[data->texture->texture_num], \
		data->map->texture.x, data->map->texture.y);
		if (data->ray->side == 1)
			color = (color >> 1) & 8355711;
		pixel_index = (y * data->window->size_line) \
		+ (data->vector->x * (data->window->bpp / 8));
		*(int *)(data->window->img_data + pixel_index) = color;
		y++;
	}
}

void	draw(t_data *data)
{
	data->texture->texture_num = calculate_texture_num(data);
	data->map->wall_x = calculate_wall_x(data);
	data->map->texture.x = calculate_texture_x(data);
	draw_textured_wall_slice(data);
}

void	draw_wall_slice(t_data *data)
{
	int		mapx;
	int		mapy;

	mapx = (int)data->ray->map.x;
	mapy = (int)data->ray->map.y;
	if (data->ray->side == 0)
	{
		data->ray->perpwalldist = (data->ray->map.x - data->player->pos.x + \
		(1 - data->ray->step.x) / 2) / data->ray->ray_dir.x;
	}
	else
	{
		data->ray->perpwalldist = (data->ray->map.y - data->player->pos.y + \
		(1 - data->ray->step.y) / 2) / data->ray->ray_dir.y;
	}
	data->ray->perpwalldist = fabs(data->ray->perpwalldist);
	data->map->lineheight = (int)(HEIGHT / data->ray->perpwalldist);
	data->map->drawstart = -data->map->lineheight / 2 + HEIGHT / 2;
	if (data->map->drawstart < 0)
		data->map->drawstart = 0;
	data->map->drawend = data->map->lineheight / 2 + HEIGHT / 2;
	if (data->map->drawend >= HEIGHT)
		data->map->drawend = HEIGHT - 1;
}

/*
Fonction qui calcule la direction du rayon pour chaque colonne de pixels sur l'ecran.
Elle permet de déterminer la direction dans laquelle le rayon doit progresser 
depuis la position du joueur pour vérifier les intersections avec des obstacles ou des murs dans l'environnement. 
*/
void	calculate_ray_direction(t_data *data)
{
	double	camera_x;

	camera_x = (2 * (data->vector->x / (double) WIDTH)) - 1;
	data->ray->ray_dir.x = data->player->dir.x + \
	data->player->plane.x * camera_x;
	data->ray->ray_dir.y = data->player->dir.y + \
	data->player->plane.y * camera_x;
}

/* Fonction qui sert a calculer les distances que chaque rayon doit parcourir sur l'axe x et y, 
pour atteindre le prochain cote vertical ou horizontal du quadrillage de la map. */
void	calculate_delta_distances(t_data *data)
{
	if (data->ray->ray_dir.x == 0)
		data->ray->delta_dist.x = 1e30;
	else
		data->ray->delta_dist.x = fabs(1 / data->ray->ray_dir.x);
	if (data->ray->ray_dir.y == 0)
		data->ray->delta_dist.y = 1e30;
	else
		data->ray->delta_dist.y = fabs(1 / data->ray->ray_dir.y);
}

void	perform_dda(t_data *data)
{
	int	hit;
	int	mapx;
	int	mapy;

	hit = 0;
	mapx = (int)data->ray->map.x;
	mapy = (int)data->ray->map.y;
	while (!hit)
	{
		if (data->ray->side_dist.x < data->ray->side_dist.y)
		{
			data->ray->side_dist.x += data->ray->delta_dist.x;
			data->ray->map.x += data->ray->step.x;
			data->ray->side = 0;
		}
		else
		{
			data->ray->side_dist.y += data->ray->delta_dist.y;
			data->ray->map.y += data->ray->step.y;
			data->ray->side = 1;
		}
		mapx = (int)data->ray->map.x;
		mapy = (int)data->ray->map.y;
		if (mapx >= 0 && mapx < data->map->width && mapy >= 0 && mapy < data->map->height)
		{
			if (data->map->map_tab[mapy][mapx] == '1') 
				hit = 1;
		}
	}
}


void initialize_step_and_side_distance(t_data *data)
{
    if (data->ray->ray_dir.x < 0)
    {
        data->ray->step.x = -1;
        data->ray->side_dist.x = (data->player->pos.x - data->ray->map.x) * data->ray->delta_dist.x;
    }
    else
    {
        data->ray->step.x = 1;
        data->ray->side_dist.x = (data->ray->map.x + 1.0 - data->player->pos.x) * data->ray->delta_dist.x;
    }

    if (data->ray->ray_dir.y < 0)
    {
        data->ray->step.y = -1;
        data->ray->side_dist.y = (data->player->pos.y - data->ray->map.y) * data->ray->delta_dist.y;
    }
    else
    {
        data->ray->step.y = 1;
        data->ray->side_dist.y = (data->ray->map.y + 1.0 - data->player->pos.y) * data->ray->delta_dist.y;
    }
}

int create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}
void draw_floor(t_data *data)
{
    int	x;
	int	y;
    int	color;

	y = HEIGHT / 2;
	color = create_trgb(0, data->map->floor_color[0], data->map->floor_color[1], data->map->floor_color[2]);
    while (y < HEIGHT)
    {
        x = 0;
		while (x < WIDTH)
        {
            int pixel_index = (y * data->window->size_line) + (x * (data->window->bpp / 8));
            *(int *)(data->window->img_data + pixel_index) = color;
			x++;
        }
		y++;
    }
}
void draw_ceiling(t_data *data)
{
	int	x;
	int	y;
    int	color;

	y = 0;
	color = create_trgb(0, data->map->ceiling_color[0], data->map->ceiling_color[1], data->map->ceiling_color[2]);
    while (y < HEIGHT / 2)
    {
        x = 0;
		while (x < WIDTH)
        {
            int pixel_index = (y * data->window->size_line) + (x * (data->window->bpp / 8));
            *(int *)(data->window->img_data + pixel_index) = color;
			x++;
        }
		y++;
    }
}
void	perform_ray_casting(t_data *data)
{
	draw_floor(data);
	draw_ceiling(data);
	data->vector->x = 0;
	while (data->vector->x < WIDTH)
	{
		data->ray->map.x = (int)data->player->pos.x;
		data->ray->map.y = (int)data->player->pos.y;
		calculate_ray_direction(data);
		calculate_delta_distances(data);
		initialize_step_and_side_distance(data);
		perform_dda(data);
		draw_wall_slice(data);
		draw(data);
		data->vector->x++;
	}
}

