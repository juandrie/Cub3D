/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:50:34 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/23 12:03:03 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_window	*init_window(void)
{
	t_window	*window;

	window = ft_calloc(1, sizeof(t_window));
	if (!window)
		return (NULL);
	window->mlx_ptr = mlx_init();
	window->width = 640;
	window->height = 480;
	window->win_ptr = mlx_new_window(window->mlx_ptr, 640, 480, "Cub3D");
	if (!window->win_ptr)
	{
		free(window);
		return (NULL);
	}
	window->img_ptr = mlx_new_image(window->mlx_ptr, window->width, window->height);
	if (!window->img_ptr)
	{
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
		free(window);
		return (NULL);
	}
    window->img_data = mlx_get_data_addr(window->img_ptr, &window->bpp, &window->size_line, &window->endian);
	window->running = 1;
	return (window);
}
