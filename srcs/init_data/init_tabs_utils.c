/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tabs_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:10:38 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/10 17:11:08 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_nb_text_color(t_list *text_color_list, int *tc)
{
	while (text_color_list)
	{
		if (!ft_strncmp(text_color_list->line, "F", 1) || \
		!ft_strncmp(text_color_list->line, "C", 1))
			tc[1]++;
		else
			tc[0]++;
		text_color_list = text_color_list->next;
	}
}
