/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:00:07 by cabdli            #+#    #+#             */
/*   Updated: 2024/05/27 18:17:33 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	tab_size(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

int	nb_colors(char **tab)
{
	int	size;

	size = tab_size(tab);
	if (size != 2)
		return (1);
	printf("size = %d\n", size);
	return (0);
}

int	parse_colors(char **tab)
{
	if (nb_colors(tab))
		return (print_err(COLOR_S), 1);
	
	return (0);
}
