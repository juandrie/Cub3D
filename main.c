/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:02:50 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/20 16:45:55 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop_hook(t_data *data)
{
	if (!data->window->running)
	{
		mlx_destroy_window(data->window->mlx_ptr, data->window->win_ptr);
		exit(0);
	}
	update_timing_and_movement(data);
	perform_ray_casting(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	if (argc != 2)
	{
		printf("Error: %s <map_file.cub>\n", argv[0]);
		return (0);
	}
	data = init_data();
	if (!data)
		return (0);
	data->map->filepath = ft_strdup(argv[1]);
	read_map(data);
	hooks(data);
	mlx_destroy_window(data->window->mlx_ptr, data->window->win_ptr);
	return (0);
}
