/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:27:11 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/27 15:38:29 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    print_err(t_error error)
{
    if (error == EMPTY)
        ft_putstr_fd("Error\nEmpty map\n", STDERR_FILENO);
}
