/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:44:52 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/10 20:27:53 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

double	get_ticks(void)
{
	return ((double)clock() / CLOCKS_PER_SEC);
}

void	update_timing_and_movement(t_data *data)
{
	static double	oldtime = 0;
	double			time;
	double			frametime;

	time = get_ticks();
	if (oldtime == 0)
	{
		oldtime = time;
		return ;
	}
	frametime = (time - oldtime);
	oldtime = time;
	data->window->movespeed = frametime * MOVE_SPEED;
	data->window->rotspeed = frametime * ROTATE_SPEED;
}
