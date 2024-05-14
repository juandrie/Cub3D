/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:34:28 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/13 19:00:14 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void *init_mlx(int width, int height, char *title)
{
    void *mlx_ptr = mlx_init();
    if (!mlx_ptr)
    {
        printf("Error: MinilibX initialization failed.\n");
        exit(1);
    }
    void *win_ptr = mlx_new_window(mlx_ptr, width, height, title);
    if (!win_ptr) {
        printf("Error: Failed to create window.\n");
        exit(1);
    }
    return (win_ptr);
}
