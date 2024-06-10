/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:02:50 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/10 18:07:22 by juandrie         ###   ########.fr       */
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
		return (free_data(&data, 1), 1);
	printf("\n\n");
	print_tab(data->map->map_tab);
	if (init_data(&data, argv[1], 1))
		return (1);
	start_the_game(data);
	free_data(&data, 0);
	printf("SUCCESS !\n\n");
	return (0);
}

/*
- regler soucis makefile libft : si modif de la libft le makefile doit recompiler
ce qui a ete modifie
- fluidite rotation (mate elo)
- repartition definitions dans cub3d.h
- agrandir fenetre jeu
- refactorisation raycasting a la norme
- refaire un coup de norme (pb init_list ?)
- changer textures
*/
