/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 13:29:32 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/14 14:53:26 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int worldMap[24][24]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

/*
Fonction pour dessiner les murs dans la vue 3D
x : la position horizontale de la ligne sur l'écran.
drawStart, drawEnd : déterminent où la ligne commence et se termine sur l'axe vertical.
color : la couleur de la ligne, influencée par si le mur est sur le côté "nord-sud" ou "est-ouest".
*/
void draw_vertical_line(void *mlx_ptr, void *win_ptr, int x, int drawStart, int drawEnd, int color)
{
	int	y;

	y = drawStart;
	while (y < drawEnd)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
		y++;
	}
}
//Fonction qui permet de creer un effet de lumiere, rendant les murs lateraux plus sombres pour donner une 
//impression de profondeur.

int	determine_color(int wallType, int side)
{
	int	color;

	if (wallType == 1)
		color = 0xFF0000;
	else
		color = 0xFFFFFF;
	if (side == 1)
		color /= 2;
	return (color);
}

//Fonction qui calcule le rayon pour un pixel.
//Elle permet de déterminer la direction dans laquelle le rayon doit progresser 
//depuis la position du joueur pour vérifier les intersections avec des obstacles ou des murs dans l'environnement. 
void	calculate_ray_direction(int x, int width, double dir_x, double plane_x, double dir_y, double plane_y, double *raydir_x, double *raydir_y)
{
	double	camera_x;

	camera_x = 2 * x / (double)width - 1; // Position x dans l'espace caméra
	*raydir_x = dir_x + plane_x * camera_x;
	*raydir_y = dir_y + plane_y * camera_x;
}

void	calculate_delta_distances(double raydir_x, double raydir_y, double *deltadist_x, double *deltadist_y)
{
	if (raydir_x == 0)
		*deltadist_x = 1e30;
	else
		*deltadist_x = fabs(1 / raydir_x);
	if (raydir_y == 0)
		*deltadist_y = 1e30;
	else
		*deltadist_y = fabs(1 / raydir_y);
}

void perform_dda(int *mapX, int *mapY, double *sideDistX, double *sideDistY, double deltaDistX, double deltaDistY, int stepX, int stepY, int *side)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (*sideDistX < *sideDistY)
		{
			*sideDistX += deltaDistX;
			*mapX += stepX;
			*side = 0;
		}
		else
		{
			*sideDistY += deltaDistY;
			*mapY += stepY;
			*side = 1;
		}
		if (worldMap[*mapX][*mapY] > 0)
			hit = 1;
	}
}

void draw_wall_slice(int x, int height, double posX, double posY, double rayDirX, double rayDirY, int mapX, int mapY, int side, int step_x, int step_y, void *mlx_ptr, void *win_ptr)
{
    double	perpWallDist;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color;
	
	if (side == 0)
        perpWallDist = (mapX - posX + (1 - step_x) / 2) / rayDirX;
    else
        perpWallDist = (mapY - posY + (1 - step_y) / 2) / rayDirY;
    lineHeight = (int)(height / perpWallDist);
    drawStart = -lineHeight / 2 + height / 2;
    drawEnd = lineHeight / 2 + height / 2;
    color = determine_color(worldMap[mapX][mapY], side);
    draw_vertical_line(mlx_ptr, win_ptr, x, drawStart, drawEnd, color);
}

void perform_ray_casting(void *mlx_ptr, void *win_ptr, double posX, double posY, double dirX, double dirY, double planeX, double planeY, int width, int height)
{
    int		x;
	int		mapX;
	int		mapY;
	int		step_x;
	int		step_y;
	int		side;
	double	rayDirX;
	double	rayDirY;
	double	deltaDistX;
	double	deltaDistY; 
	double	sideDistX;
	double	sideDistY;
	
	x = 0;
	while (x < width)
    {
        mapX = (int)posX;
		mapY = (int)posY;

        calculate_ray_direction(x, width, dirX, planeX, dirY, planeY, &rayDirX, &rayDirY);
        calculate_delta_distances(rayDirX, rayDirY, &deltaDistX, &deltaDistY);
        if (rayDirX < 0)
		{
            step_x = -1;
            sideDistX = (posX - mapX) * deltaDistX;
        }
		else
		{
            step_x = 1;
            sideDistX = (mapX + 1.0 - posX) * deltaDistX;
        }
        if (rayDirY < 0)
		{
            step_y = -1;
            sideDistY = (posY - mapY) * deltaDistY;
        }
		else 
		{
            step_y = 1;
            sideDistY = (mapY + 1.0 - posY) * deltaDistY;
        }
        perform_dda(&mapX, &mapY, &sideDistX, &sideDistY, deltaDistX, deltaDistY, step_x, step_y, &side);
        draw_wall_slice(x, height, posX, posY, rayDirX, rayDirY, mapX, mapY, side, step_x, step_y, mlx_ptr, win_ptr);
		x++;
    }
}

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	double	posX = 22;
	double	posY = 12; // Position de départ x et y
	double	dirX = -1;
	double	dirY = 0; // Vecteur direction initial
	double	planeX = 0;
	double	planeY = 0.66; // Plan de la caméra pour le raycasting 2D
	int		width = 640;
	int		height = 480;

	// Initialiser la connexion au système graphique
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, width, height, "Cub3D");
	while (1)
	{
		mlx_clear_window(mlx_ptr, win_ptr);
		perform_ray_casting(mlx_ptr, win_ptr, posX, posY, dirX, dirY, planeX, planeY, width, height);
		mlx_loop(mlx_ptr);
	}
	// Libération des ressources et fermeture de MinilibX
	mlx_destroy_window(mlx_ptr, win_ptr);
	return (0);
}
