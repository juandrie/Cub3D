/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:43:43 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/10 17:56:09 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_press(int keycode, t_data *data)
{
	data->window->key_pressed = keycode;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	(void)keycode;
	data->window->key_pressed = 0;
	return (0);
}

int	close_window(t_data *data)
{
	free_data(&data, 0);
	exit(0);
	return (0);
}

int	loop_hook(t_data *data)
{
	read_keys(data);
	update_timing_and_movement(data);
	perform_ray_casting(data);
	mlx_put_image_to_window(data->window->mlx_ptr, data->window->win_ptr, \
	data->window->img_ptr, 0, 0);
	return (0);
}

void	hooks(t_data *data)
{
	mlx_hook(data->window->win_ptr, X_CROSS, 0L, close_window, data);
	mlx_hook(data->window->win_ptr, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->window->win_ptr, KeyRelease, KeyReleaseMask, \
	key_release, data);
	mlx_loop_hook(data->window->mlx_ptr, loop_hook, data);
	mlx_loop(data->window->mlx_ptr);
}
/*
17 : id de l'evenement (fermeture de la fenetre et de l'application
avec liberation des ressources)
OL: masque d'evenement, utilisé pour filtrer les événements.
Dans ce cas, 0L (zero long) signifie qu'il n'y a pas de masque
spécifique à appliquer, donc l'événement est accepté sans
conditions supplémentaires.
*/
