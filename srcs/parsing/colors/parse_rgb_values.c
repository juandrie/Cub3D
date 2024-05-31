/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:39:24 by cabdli            #+#    #+#             */
/*   Updated: 2024/05/29 17:40:03 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	check_comma_nbs(char *tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (!is_comma(tab[i]) && !is_nb(tab[i]))
			return (1);
	}
	return (0);
}

int	check_nb_of_nbs(char *tab)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (!is_nb(tab[0]))
		return (1);
	while (tab[i])
	{
		while (tab[i] && !is_comma(tab[i]))
			i++;
		if (is_nb(tab[i - 1]))
			nb++;
		if (tab[i])
			i++;
	}
	if (nb != 3)
		return (1);
	return (0);
}

int	check_nb_of_commas(char *tab)
{
	int	i;
	int	comma;

	i = -1;
	comma = 0;
	while (tab[++i])
	{
		if (is_comma(tab[i]))
			comma++;
	}
	if (comma != 2)
		return (1);
	return (0);
}

int	check_nbs_range(char *tab)
{
	int		i;
	int		nbs[3];
	char	**split;

	i = -1;
	ft_bzero(nbs, sizeof(nbs));
	split = ft_split(tab, ',');
	if (!split)
		return (perror("Error"), 1);
	while (split[++i])
		nbs[i] = ft_atoi(split[i]);
	while (i-- > 0)
	{
		if (nbs[i] < 0 || nbs[i] > 255)
			return (free_full_tab(split), 1);
	}
	free_full_tab(split);
	return (0);
}
