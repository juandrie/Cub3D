/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:43:43 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/16 18:50:44 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_press(int keycode, t_data *data)
{
    data->window->key_pressed = keycode;
    read_keys(data);
    return 0;
}

int key_release(int keycode, t_data *data)
{
    (void)keycode;
    data->window->key_pressed = 0;
    return 0;
}

void hooks(t_data *data)
{
    mlx_hook(data->window->win_ptr, KeyPress, KeyPressMask, key_press, data);
    mlx_hook(data->window->win_ptr, KeyRelease, KeyReleaseMask, key_release, data);
    mlx_loop_hook(data->window->mlx_ptr, loop_hook, data);
    mlx_loop(data->window->mlx_ptr); 
}

