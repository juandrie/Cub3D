/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:38:57 by cabdli            #+#    #+#             */
/*   Updated: 2024/06/04 17:50:53 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	free_data(t_data **data)
{
	if (!(*data))
		return ;
	free_window(&(*data)->window);
	free_text_path(&(*data)->text_path);
	if ((*data)->texture)
		free((*data)->texture);
	if ((*data)->player)
		free((*data)->player);
	if ((*data)->ray)
		free((*data)->ray);
	if ((*data)->vector)
		free((*data)->vector);
	free_map(&(*data)->map);
	free(*data);
	*data = NULL;
}
