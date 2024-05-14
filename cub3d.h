/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:14:50 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/14 12:33:29 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "minilibx-linux/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void draw_vertical_line(void *mlx_ptr, void *win_ptr, int x, int drawStart, int drawEnd, int color);
void perform_ray_casting(void *mlx_ptr, void *win_ptr, double posX, double posY, double dirX, double dirY, double planeX, double planeY, int width, int height);
int determine_color(int wallType, int side);


#endif 