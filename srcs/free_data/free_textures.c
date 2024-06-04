/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:37:27 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/04 19:21:37 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


void	free_textures(t_texture **texture)
{
	int	i;

	i = -1;
	if (!texture)
		return ;
	while (texture[++i])
		free(texture[i]);
}

void	free_text_path(char ***texture)
{
	int	i;

	i = -1;
	if (!*texture)
		return ;
	// while (*texture[++i])
	// 	free(*texture[i]);
	free(*texture);
	*texture = NULL;
}
