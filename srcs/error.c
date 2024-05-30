/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:27:11 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/30 14:48:33 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_err(t_error error)
{
	if (error == EMPTY)
		ft_putstr_fd("Error\nEmpty map\n", STDERR_FILENO);
	if (error == MISS_DUP_C)
		ft_putstr_fd("Error\nMissing or duplicated color definitions\n", \
		STDERR_FILENO);
	if (error == INVAL_RGB)
		ft_putstr_fd("Error\nIvalid RGB values for at least one color\n", \
		STDERR_FILENO);
	if (error == EMPTY_L)
		ft_putstr_fd("Error\nThe map contains an empty line\n", STDERR_FILENO);
	if (error == WRONG_C)
		ft_putstr_fd("Error\nThe map contains a wrong char\n", STDERR_FILENO);
	if (error == NO_PLAYER)
		ft_putstr_fd("Error\nNo player in the map\n", STDERR_FILENO);
	if (error == MUCH_PLAYERS)
		ft_putstr_fd("Error\nToo much players in the map\n", STDERR_FILENO);
}
