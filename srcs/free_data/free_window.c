/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:46:07 by cabdli            #+#    #+#             */
/*   Updated: 2024/06/03 11:50:32 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_window(t_window **window)
{
	if (!(*window))
		return ;
	if ((*window)->mlx_ptr)
		free((*window)->mlx_ptr);
	if ((*window)->win_ptr)
	{
		mlx_destroy_window((*window)->mlx_ptr, (*window)->win_ptr);
		free((*window)->mlx_ptr);
	}
	if ((*window)->img_ptr)
	{
		mlx_destroy_image((*window)->mlx_ptr, (*window)->img_ptr);
		free((*window)->img_ptr);
	}
	if ((*window)->img_data)
		free((*window)->img_data);
	free((*window));
	*window = NULL;
}

