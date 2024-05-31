/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:27:11 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/31 14:48:14 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	print_err(t_error error)
{
	if (error == EMPTY)
		ft_putstr_fd("Error\nEmpty map\n", STDERR_FILENO);
	if (error == TEXTURE_SIZE)
		ft_putstr_fd("Error\nInvalid number of textures\n", STDERR_FILENO);
	if (error == TEXTURE_INVAL)
		ft_putstr_fd("Error\nInvalid texture definition\n", STDERR_FILENO);
	if (error == TEXTURE_DUPLICATED)
		ft_putstr_fd("Error\nDuplicated texture definition\n", STDERR_FILENO);
	if (error == TEXTURE_FORMAT)
		ft_putstr_fd("Error\nInvalid texture format\n", STDERR_FILENO);
	if (error == TEXTURE_PATH)
		ft_putstr_fd("Error\nInvalid texture path\n", STDERR_FILENO);
	if (error == MAP_BORDERS)
		ft_putstr_fd("Error\nNo borders in the map\n", STDERR_FILENO);
}
