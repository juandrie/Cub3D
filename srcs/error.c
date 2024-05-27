/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:27:11 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/27 18:50:04 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    print_err(t_error error)
{
    if (error == EMPTY)
        ft_putstr_fd("Error\nEmpty map\n", STDERR_FILENO);
    if (error == TEXTURE_S)
        ft_putstr_fd("Error\nInvalid number of textures\n", STDERR_FILENO);
}
