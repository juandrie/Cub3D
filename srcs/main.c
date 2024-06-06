/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:02:50 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/06 17:17:04 by cabdli           ###   ########.fr       */
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
	print_data(data);
	if (parsing(data->map))
		return (free_data(&data), 1);
	if (init_data(&data, argv[1], 1))
		return (1);
	start_the_game(data);
	free_data(&data);
	printf("SUCCESS !\n\n");
	return (0);
}

//ajouter in int a init_data pour le lancer en deux parties
// creer un dossier .build avec sous dossiers pour les .o
// parser l'ordre de la map ?
/*

*/
