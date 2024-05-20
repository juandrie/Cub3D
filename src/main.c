/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:33:06 by cabdli            #+#    #+#             */
/*   Updated: 2024/05/20 13:43:44 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_cub(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (ft_strncmp(&filename[len - 4], ".cub", 4))
		return (1);
	return (0);
}

static int	check_args(int ac, char **av, char **envp)
{
	if (!envp[0])
		return (ft_putstr_fd("Error: no env\n", STDERR_FILENO), 1);
	if (ac != 2)
		return (ft_putstr_fd("Error: enter ./cub3d NAME.cub\n", \
		STDERR_FILENO), 1);
	if (!is_cub(av[1]))
		return (ft_putstr_fd("Error: the file is not a .cub file\n", \
		STDERR_FILENO), 1);
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	data = NULL;
	if (check_args(ac, av, envp))
		return (1);
	data = init_data(av[1]);
	if (!data)
		return (1);
	if (parse_map())
		return (1);
	start_the_game(data);
	return (0);
}

//create the free_data function
// modifier GNL (enlever la partie parsing de so_long)
// test for an empty map
// check the correct error message