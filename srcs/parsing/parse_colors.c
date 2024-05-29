/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:00:07 by cabdli            #+#    #+#             */
/*   Updated: 2024/05/28 16:02:40 by cabdli           ###   ########.fr       */
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

int	check_nb_colors(char **tab)
{
	int	size;

	size = tab_size(tab);
	if (size != 2)
		return (1);
	printf("size = %d\n", size);
	return (0);
}

int	check_ceiling_floor(char **tab)
{
	int	c;
	int	f;

	c = 0;
	f = 0;
	if (tab[0][0] != 'C' && tab[0][0] != 'F')
		return (1);
	if (tab[1][0] != 'C' && tab[1][0] != 'F')
		return (1);
	if (tab[0][0] == 'C' || tab[1][0] == 'C')
		c = 1;
	if (tab[0][0] == 'F' || tab[1][0] == 'F')
		f = 1;
	if (!c || !f)
		return (1);
	return (0);
}

int	is_comma(char c)
{
	return (c == ',');
}

int	rgb_values(char *tab)
{
	tab = skip_whitespace(tab);
	
}

int	check_rgb_values(char **tab)
{
	int	i;

	i = 1;
	if (rgb_values(tab[0]))
		return (1);
	if (rgb_values(tab[1]))
		return (1);
	return (0);
}

int	parse_colors(char **tab)
{
	if (check_nb_colors(tab))
		return (print_err(MISS_DUP), 1);
	if (check_ceiling_floor(tab))
		return (print_err(MISS_DUP), 1);
	if (check_rgb_values(tab))
		return (print_err(MISS_DUP), 1);
	return (0);
}
// there're 3 numbers spearated by ',' -> Invalid RGB values for one or more colors
// the range is in between 0 and 255 - > Invalid RGB values for one or more colors