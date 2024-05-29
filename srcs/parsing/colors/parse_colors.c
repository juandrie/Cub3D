/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:00:07 by cabdli            #+#    #+#             */
/*   Updated: 2024/05/29 17:42:02 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_nb_colors(char **tab)
{
	int	size;

	size = tab_size(tab);
	if (size != 2)
		return (1);
	return (0);
}

static int	check_ceiling_floor(char **tab)
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

static int	rgb_values(char *tab)
{
	tab = skip_whitespace(tab);
	if (check_comma_nbs(tab))
		return (1);
	if (check_nb_of_commas(tab))
		return (1);
	if (check_nb_of_nbs(tab))
		return (1);
	if (check_nbs_range(tab))
		return (1);
	return (0);
}

static int	check_rgb_values(char **tab)
{
	int		i;
	char	*tmp;

	i = -1;
	while (tab[++i])
	{
		tmp = tab[i] + 1;
		if (rgb_values(tmp))
			return (1);
	}
	return (0);
}

int	parse_colors(char **tab)
{
	if (check_nb_colors(tab))
		return (print_err(MISS_DUP_C), 1);
	if (check_ceiling_floor(tab))
		return (print_err(MISS_DUP_C), 1);
	if (check_rgb_values(tab))
		return (print_err(INVAL_RGB), 1);
	return (0);
}
