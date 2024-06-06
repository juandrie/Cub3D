/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:37:27 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/06 14:14:13 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_textures(t_texture **texture)
{
	int	i;

	i = -1;
	if (!*texture)
		return ;
	// if ((*texture)->img_ptr)
	// 	free((*texture)->img_ptr);
	free(*texture);
	*texture = NULL;
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
