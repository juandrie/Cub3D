/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:50:34 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/10 17:14:11 by juandrie         ###   ########.fr       */
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
	if (!window->mlx_ptr)
		return (NULL);
	window->win_ptr = mlx_new_window(window->mlx_ptr, WIDTH, HEIGHT, "Cub3D");
	if (!window->win_ptr)
		return (NULL);
	window->img_ptr = mlx_new_image(window->mlx_ptr, WIDTH, HEIGHT);
	if (!window->img_ptr)
		return (NULL);
	window->img_data = mlx_get_data_addr(window->img_ptr, &window->bpp, \
	&window->size_line, &window->endian);
	if (!window->img_data)
		return (NULL);
	return (window);
}
