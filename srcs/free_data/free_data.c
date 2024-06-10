/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:38:57 by cabdli            #+#    #+#             */
/*   Updated: 2024/06/10 16:24:01 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_data(t_data **data, int tab)
{
	if (!(*data))
		return ;
	free_textures((*data)->texture, *data);
	free_text_path(&(*data)->text_path);
	free_window(&(*data)->window);
	if ((*data)->player)
		free((*data)->player);
	if ((*data)->ray)
		free((*data)->ray);
	if ((*data)->vector)
		free((*data)->vector);
	free_map(&(*data)->map, tab);
	free(*data);
	*data = NULL;
}
