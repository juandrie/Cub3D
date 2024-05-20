/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:29:32 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/20 18:03:32 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Fonction pour dessiner les murs dans la vue 3D
x : la position horizontale de la ligne sur l'écran.
drawStart, drawEnd : déterminent où la ligne commence et se termine sur l'axe vertical.
color : la couleur de la ligne, influencée par si le mur est sur le côté "nord-sud" ou "est-ouest".
*/
// void	draw_vertical_line(t_data *data, int drawStart, int drawEnd, int color)
// {
// 	int	y;

// 	y = drawStart;
// 	while (y < drawEnd)
// 	{
// 		mlx_pixel_put(data->window->mlx_ptr, data->window->win_ptr, data->vector->x, y, color);
// 		y++;
// 	}
// }
void draw_textured_wall_slice(t_data *data)
{
    int y = data->map->drawstart;
	while (y < data->map->drawend)
    {
        data->map->texture.y = (int)data->map->text_pos & (data->texture[data->texture->texture_num].height - 1);
        data->map->text_pos += data->ray->delta_dist.y;
        int color = get_texture_color(&data->texture[data->texture->texture_num], data->map->texture.x, data->map->texture.y);
        if (data->ray->side == 1)
			color = (color >> 1) & 8355711; // Make y sides darker
        mlx_pixel_put(data->window->mlx_ptr, data->window->win_ptr, data->vector->x, y, color);
		y++;
    }
}

void draw(t_data *data)
{
    int TestNum = calculate_texture_num(data);
    data->map->wall_x = calculate_wall_x(data);
    data->map->texture.x = calculate_texture_x(data);

    // Comment augmenter la coordonnée de texture par pixel d'écran
    double step = 1.0 * data->texture[TestNum].height / data->map->lineheight;
    data->map->text_pos = (data->map->drawstart - data->window->height / 2 + data->map->lineheight / 2) * step;

    draw_textured_wall_slice(data);
}

void	draw_wall_slice(t_data *data)
{
	// int		color;
	int		mapx;
	int		mapy;

	mapx = (int)data->ray->map.x;
	mapy = (int)data->ray->map.y;
	if (mapx < 0 || mapx >= data->map->width || mapy < 0 || mapy >= data->map->height)
	{
		printf("Error: out of bounds (mapx=%d, mapy=%d).\n", mapx, mapy);
		exit(0);
	}
	if (data->ray->side == 0)
		data->ray->perpwalldist = (data->ray->map.x - data->player->pos.x + (1 - data->ray->step.x) / 2) / data->ray->ray_dir.x;
	else
		data->ray->perpwalldist = (data->ray->map.y - data->player->pos.y + (1 - data->ray->step.y) / 2) / data->ray->ray_dir.y;
	data->ray->perpwalldist = fabs(data->ray->perpwalldist); 
	data->map->lineheight = (int)(data->window->height / data->ray->perpwalldist);
	data->map->drawstart = -data->map->lineheight / 2 + data->window->height / 2;
	data->map->drawend = data->map->lineheight / 2 + data->window->height / 2;

	if (data->map->drawend >= data->window->height)
		data->map->drawend = data->window->height - 1;
	
	// color = determine_color(data->map->map[mapx][mapy] - '0', data);
	// draw_vertical_line(data, drawstart, drawend, color);
}
/*
Fonction qui permet de creer un effet de lumiere, rendant les murs lateraux plus sombres pour donner une 
impression de profondeur.
*/
int	determine_color(char wallChar, t_data *data)
{
	int	color;
	int	walltype;

	walltype = wallChar - '0';
	if (walltype == 1)
		color = 0xFF0000;
	else
		color = 0xFFFFFF;
	if (data->ray->side == 1)
		color /= 2;
	return (color);
}

/*
Fonction qui calcule la direction du rayon pour chaque colonne de pixels sur l'ecran.
Elle permet de déterminer la direction dans laquelle le rayon doit progresser 
depuis la position du joueur pour vérifier les intersections avec des obstacles ou des murs dans l'environnement. 
*/
void	calculate_ray_direction(t_data *data)
{
	double	camera_x;

	camera_x = (2 * (data->vector->x / (double)data->window->width)) - 1; // Position x dans l'espace caméra
	data->ray->ray_dir.x = data->player->dir.x + data->player->plane.x * camera_x;
	data->ray->ray_dir.y = data->player->dir.y + data->player->plane.y * camera_x;
}

/* Fonction qui sert a calculer les distances que chaque rayon doit parcourir sur l'axe x et y, 
pour atteindre le prochain cote vertical ou horizontal du quadrillage de la map. */
void	calculate_delta_distances(t_data *data)
{
	if (data->ray->ray_dir.x == 0) // cad le rayon ne se deplace pas a l'horizontal
		data->ray->delta_dist.x = 1e30; // valeur utilisee car consideree comme infinie, le rayon ne rencontrera donc jamais un cote vertical
	else
		data->ray->delta_dist.x = fabs(1 / data->ray->ray_dir.x); // la fonction fabs calcule la valeur absolue d'un nombre a virgule flottante cad sans tenir compte du signe positif ou negatif
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
	while (!hit)
	{
		mapx = (int)data->ray->map.x;
		mapy = (int)data->ray->map.y;
		if (mapx < 0 || mapx >= data->map->width || mapy < 0 || mapy >= data->map->height)
		{
			printf("Error: ray went out of bounds (mapx=%d, mapy=%d).\n", mapx, mapy);
			return;
		}
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
			if (data->map->map[mapx][mapy] == '1') 
				hit = 1;
		}
		else
		{
			printf("Error: ray went out of bounds (mapx=%d, mapy=%d).\n", mapx, mapy);
			return ;
		}
	}
}


void	perform_ray_casting(t_data *data)
{
	data->vector->x = 0;
	while (data->vector->x < data->window->width)
	{
		data->ray->map.x = (int)data->player->pos.x;
		data->ray->map.y = (int)data->player->pos.y;
		calculate_ray_direction(data);
		calculate_delta_distances(data);
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
		perform_dda(data);
		draw_wall_slice(data);
		draw(data);
		data->vector->x++;
	}
}

