/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:27:11 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/03 16:36:01 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_err(t_error error)
{
	if (error == EMPTY)
		ft_putstr_fd("Error\nEmpty map\n", STDERR_FILENO);
	else if (error == MISS_DUP_C)
		ft_putstr_fd("Error\nMissing or duplicated color definitions\n", \
		STDERR_FILENO);
	else if (error == INVAL_RGB)
		ft_putstr_fd("Error\nIvalid RGB values for at least one color\n", \
		STDERR_FILENO);
	else if (error == EMPTY_L)
		ft_putstr_fd("Error\nThe map contains an empty line\n", STDERR_FILENO);
	else if (error == WRONG_C)
		ft_putstr_fd("Error\nThe map contains a wrong char\n", STDERR_FILENO);
	else if (error == NO_PLAYER)
		ft_putstr_fd("Error\nNo player in the map\n", STDERR_FILENO);
	else if (error == MUCH_PLAYERS)
		ft_putstr_fd("Error\nToo much players in the map\n", STDERR_FILENO);
	else if (error == TEXTURE_SIZE)
		ft_putstr_fd("Error\nInvalid number of textures\n", STDERR_FILENO);
	else if (error == TEXTURE_INVAL)
		ft_putstr_fd("Error\nInvalid texture definition\n", STDERR_FILENO);
	else if (error == TEXTURE_DUPLICATED)
		ft_putstr_fd("Error\nDuplicated texture definition\n", STDERR_FILENO);
	else if (error == TEXTURE_PATH)
		ft_putstr_fd("Error\nInvalid texture path\n", STDERR_FILENO);
	else if (error == MAP_BORDERS)
		ft_putstr_fd("Error\nNo borders in the map\n", STDERR_FILENO);
	else if (error == SPACE_WALLS)
		ft_putstr_fd("Error\nSpace not surrounded by walls\n", STDERR_FILENO);
}
