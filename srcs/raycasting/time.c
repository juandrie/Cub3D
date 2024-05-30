/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:44:52 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/30 18:17:19 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	get_ticks(void)
{
	return ((double)clock() / CLOCKS_PER_SEC);
}

void	update_timing_and_movement(t_data *data)
{
	static double	oldtime;
	double			time;
	double			frametime;

	oldtime = 0;
	time = get_ticks(); // Obtenir le nouveau temps
	frametime = (time - oldtime); //Temps écoulé depuis la dernière frame en secondes
	oldtime = time; // Mettre à jour oldTime pour la prochaine frame
	data->window->movespeed = frametime * MOVE_SPEED;
	data->window->rotspeed = frametime * ROTATE_SPEED;
}