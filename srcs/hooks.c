/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:43:43 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/03 11:50:05 by juandrie         ###   ########.fr       */
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
	mlx_destroy_window(data->window->mlx_ptr, data->window->win_ptr);
	exit(0);
	return (0);
}

void	hooks(t_data *data)
{
	mlx_hook(data->window->win_ptr, 17, 0L, close_window, data);
	// 17 : id de l'evenement (fermeture de la fenetre et de l'application avec liberation des ressources) OL: masque d'evenement, utilisé pour filtrer les événements. Dans ce cas, 0L (zero long) signifie qu'il n'y a pas de masque spécifique à appliquer, donc l'événement est accepté sans conditions supplémentaires.
	mlx_hook(data->window->win_ptr, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->window->win_ptr, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_loop_hook(data->window->mlx_ptr, loop_hook, data);
	mlx_loop(data->window->mlx_ptr);
}

