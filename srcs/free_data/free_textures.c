/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:37:27 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/07 15:21:53 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_textures(t_texture *texture, t_data *data)
{
	int	i;

	(void)data;
	i = -1;
	if (!texture)
		return ;
	while (++i < 4)
	{
		if ((texture[i]).img_ptr)
		{
			mlx_destroy_image(data->window->mlx_ptr, texture[i].img_ptr);
			texture[i].img_ptr = NULL;
		}
	}
	free(texture);
}

void	free_text_path(char ***texture)
{
	int	i;

	i = -1;
	if (!*texture)
		return ;
	free(*texture);
	*texture = NULL;
}
