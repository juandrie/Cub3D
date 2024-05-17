/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:44:52 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/17 18:14:09 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_ticks(void)
{
	return ((double)clock() / CLOCKS_PER_SEC);
}

void	print_fps(double frameTime)
{
	double	fps;

	fps = 1.0 / frameTime;
	printf("FPS: %.2f\n", fps);
}

void	update_timing_and_movement(t_data *data)
{
	static double	oldtime;
	double			time;
	double			frametime;

	oldtime = 0; // Maintenir le temps de l'ancienne frame
	time = get_ticks(); // Obtenir le nouveau temps
	frametime = (time - oldtime); //Temps écoulé depuis la dernière frame en secondes
	oldtime = time; // Mettre à jour oldTime pour la prochaine frame
	//print_fps(1.0 / frameTime); // Afficher le FPS
	data->window->movespeed = frametime * 20.0; // Vitesse de déplacement
	data->window->rotspeed = frametime * 5.0; // Vitesse de rotation
}