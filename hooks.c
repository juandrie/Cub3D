/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:43:43 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/15 19:13:41 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_press(int keycode, t_data *data)
{
    printf("Address in key_press: %p\n", (void *)&data->player);
    data->window->key_pressed = keycode;
    read_keys(data);
    return 0;
}

int key_release(int keycode, t_data *data)
{
    data->window->key_pressed = 0;
    return 0;
}

void init_key_hooks(t_data *data)
{
    mlx_hook(data->window->win_ptr, KeyPress, KeyPressMask, key_press, data->window);
    mlx_hook(data->window->win_ptr, KeyRelease, KeyReleaseMask, key_release, data->window);
}

