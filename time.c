/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:44:52 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/14 17:45:16 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double get_ticks()
{
    return (double)clock() / CLOCKS_PER_SEC * 1000;
}

void print_fps(double frameTime)
{
    double fps = 1.0 / frameTime;
    printf("FPS: %.2f\n", fps);
}