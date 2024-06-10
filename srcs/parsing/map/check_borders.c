/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:22:51 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/10 17:24:12 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	check_line_rl(char *tab)
{
	char	*rev_tab;

	tab = skip_whitespace(tab);
	rev_tab = rev_skip_whitespace_borders(tab);
	if (*tab != '1' || *rev_tab != '1')
		return (1);
	return (0);
}

int	check_borders_right_left(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (check_line_rl(tab[i]))
			return (1);
	}
	return (0);
}

int	check_borders_up_down(char **tab)
{
	int	i;
	int	last;

	i = -1;
	last = tab_size(tab) - 1;
	while (tab[0][++i])
	{
		if (is_space_or_one(tab[0][i]))
			return (1);
	}
	i = -1;
	while (tab[last][++i])
	{
		if (is_space_or_one(tab[last][i]))
			return (1);
	}
	return (0);
}

int	check_borders(char **tab)
{
	if (check_borders_right_left(tab))
		return (1);
	if (check_borders_up_down(tab))
		return (1);
	return (0);
}
