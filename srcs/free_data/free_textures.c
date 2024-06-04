/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:37:27 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/04 17:43:35 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_text_path(char ***texture)
{
	int	i;

	i = -1;
	if (!*texture)
		return ;
	while (*texture[++i])
		free(*texture[i]);
	free(*texture);
	*texture = NULL;
}
