/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:14:06 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/11 12:42:32 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_key_press(t_data *data)
{
	int	last_key;

	last_key = data->window->key_pressed;
	data->window->key_pressed = 0;
	return (last_key);
}

void	read_keys(t_data *data)
{
	int	key;

	key = get_key_press(data);
	if (key == W)
		move_forward(data);
	if (key == S)
		move_back(data);
	if (key == D)
		move_side(data, MOVE_SPEED);
	if (key == A)
		move_side(data, -MOVE_SPEED);
	if (key == RIGHT)
		rotate_camera(data, ROTATE_SPEED);
	if (key == LEFT)
		rotate_camera(data, -ROTATE_SPEED);
	if (key == ESC)
		close_window(data);
}
