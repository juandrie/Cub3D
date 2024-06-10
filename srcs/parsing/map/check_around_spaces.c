/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_around_spaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:21:47 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/10 17:22:17 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	invalid_block_around(char **tab, int i, int j)
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	check;

	up = i - 1;
	down = i + 1;
	left = j - 1;
	right = j + 1;
	check = 0;
	if (up >= 0)
		check += is_space_or_one(tab[up][j]);
	if (tab[down])
		check += is_space_or_one(tab[down][j]);
	if (left >= 0)
		check += is_space_or_one(tab[i][left]);
	if (tab[i][right])
		check += is_space_or_one(tab[i][right]);
	return (check);
}

int	check_around_spaces(char **tab)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (ft_isspace(tab[i][j]))
			{
				if (invalid_block_around(tab, i, j))
					return (1);
			}
		}
	}
	return (0);
}
