/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:46:07 by cabdli            #+#    #+#             */
/*   Updated: 2024/06/03 17:09:25 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_window(t_window **window)
{
	if (!(*window))
		return ;
	if ((*window)->win_ptr)
		mlx_destroy_window((*window)->mlx_ptr, (*window)->win_ptr);
	if ((*window)->img_ptr)
		mlx_destroy_image((*window)->mlx_ptr, (*window)->img_ptr);
	if ((*window)->mlx_ptr)
	{
		mlx_destroy_display((*window)->mlx_ptr);
		free((*window)->mlx_ptr);
	}
	free((*window));
	*window = NULL;
}

