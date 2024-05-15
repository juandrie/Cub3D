/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:28:43 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/15 19:11:53 by juandrie         ###   ########.fr       */
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
    printf("Address of player in read_keys: %p, pos: (%f, %f)\n", (void *)data->player, data->player->pos.x, data->player->pos.y);

    printf("Attempting to move from (%.2f, %.2f) to (%.2f, %.2f)\n", data->player->pos.x, data->player->pos.y, newX, newY);
    if (key == W)
    {
        printf("Attempting to move forward from (%f, %f) to (%f, %f)\n", data->player->pos.x, data->player->pos.y, newX, newY);
        if (worldMap[(int)newX][(int)data->player->pos.y] != 1)
            data->player->pos.x = newX;
        if (worldMap[(int)data->player->pos.x][(int)newY] != 1)
            data->player->pos.y = newY;
        printf("New position: (%f, %f)\n", data->player->pos.x, data->player->pos.y);
    }
    
    if (key == S)
    {
        newX = data->player->pos.x - data->player->dir.x * data->window->moveSpeed;
        newY = data->player->pos.y - data->player->dir.y * data->window->moveSpeed;
        printf("Attempting to move backward from (%f, %f) to (%f, %f)\n", data->player->pos.x, data->player->pos.y, newX, newY);
        if (worldMap[(int)newX][(int)data->player->pos.y] != 1)
            data->player->pos.x = newX;
        if (worldMap[(int)data->player->pos.x][(int)newY] != 1)
            data->player->pos.y = newY;
        printf("New position: (%f, %f)\n", data->player->pos.x, data->player->pos.y);
    }
    
    if (key == D)
    {
        printf("Attempting to turn right from direction (%f, %f)\n", data->player->dir.x, data->player->dir.y);
        double oldDirX = data->player->dir.x;
        data->player->dir.x = data->player->dir.x * cos(- data->window->rotSpeed) - data->player->dir.y * sin(-data->window->rotSpeed);
        data->player->dir.y = oldDirX * sin(-data->window->rotSpeed) + data->player->dir.y * cos(-data->window->rotSpeed);
        printf("New direction: (%f, %f)\n", data->player->dir.x, data->player->dir.y);
    }
    
    if (key == A)
    {
        printf("Attempting to turn left from direction (%f, %f)\n", data->player->dir.x, data->player->dir.y);
        double oldDirX = data->player->dir.x;
        data->player->dir.x = data->player->dir.x * cos(data->window->rotSpeed) - data->player->dir.y * sin(data->window->rotSpeed);
        data->player->dir.y = oldDirX * sin(data->window->rotSpeed) + data->player->dir.y * cos(data->window->rotSpeed);
        printf("New direction: (%f, %f)\n", data->player->dir.x, data->player->dir.y);
    }
    printf("New position: (%.2f, %.2f)\n", data->player->pos.x, data->player->pos.y);
    if (key == ESC)
        data->window->running = 0;
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

    printf("FPS: %.2f, MoveSpeed: %.5f, RotSpeed: %.5f\n", 1.0 / frameTime, data->window->moveSpeed, data->window->rotSpeed);
    printf("Direction: (%.5f, %.5f)\n", data->player->dir.x, data->player->dir.y);
}