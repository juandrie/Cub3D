/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:02:50 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/14 16:55:55 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	data = NULL;
	if (check_args(argc, argv, envp))
		return (1);
	if (init_data(&data, argv[1], 0))
		return (1);
	if (parsing(data->map))
		return (free_data(&data, 1), 1);
	if (init_data(&data, argv[1], 1))
		return (1);
	start_the_game(data);
	free_data(&data, 0);
	return (0);
}
