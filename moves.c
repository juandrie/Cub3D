/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:28:43 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/16 17:23:04 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_key_press(t_data *data)
{
    int last_key = data->window->key_pressed;
    data->window->key_pressed = 0;
    return (last_key);
}

void read_keys(t_data *data)
{
    int key = get_key_press(data);
    double newX = data->player->pos.x + data->player->dir.x * data->window->moveSpeed;
    double newY = data->player->pos.y + data->player->dir.y * data->window->moveSpeed;

    if (key == W)
    {
        if (data->map->map[(int)newX][(int)data->player->pos.y] == 0)
            data->player->pos.x = newX;
        if (data->map->map[(int)data->player->pos.x][(int)newY] == 0)
            data->player->pos.y = newY;
    }
    if (key == S)
    {
        newX = data->player->pos.x - data->player->dir.x * data->window->moveSpeed;
        newY = data->player->pos.y - data->player->dir.y * data->window->moveSpeed;
        if (data->map->map[(int)newX][(int)data->player->pos.y] == 0)
            data->player->pos.x = newX;
        if (data->map->map[(int)data->player->pos.x][(int)newY] == 0)
            data->player->pos.y = newY;
    }
    if (key == D)
    {
        double oldDirX = data->player->dir.x;
        data->player->dir.x = data->player->dir.x * cos(- data->window->rotSpeed) - data->player->dir.y * sin(-data->window->rotSpeed);
        data->player->dir.y = oldDirX * sin(-data->window->rotSpeed) + data->player->dir.y * cos(-data->window->rotSpeed);
    }
    if (key == A)
    {
        double oldDirX = data->player->dir.x;
        data->player->dir.x = data->player->dir.x * cos(data->window->rotSpeed) - data->player->dir.y * sin(data->window->rotSpeed);
        data->player->dir.y = oldDirX * sin(data->window->rotSpeed) + data->player->dir.y * cos(data->window->rotSpeed);
    }
    if (key == ESC)
    {
        data->window->running = 0;
    }
    mlx_clear_window(data->window->mlx_ptr, data->window->win_ptr);
    perform_ray_casting(data);
}



void update_timing_and_movement(t_data *data)
{
    static double oldTime = 0; // Maintenir le temps de l'ancienne frame
    double time = get_ticks(); // Obtenir le nouveau temps
    double frameTime = (time - oldTime) / 1000.0; // Temps écoulé depuis la dernière frame en secondes
    oldTime = time; // Mettre à jour oldTime pour la prochaine frame

    //print_fps(1.0 / frameTime); // Afficher le FPS

    data->window->moveSpeed = frameTime * 5.0; // Vitesse de déplacement
    data->window->rotSpeed = frameTime * 3.0; // Vitesse de rotation
}