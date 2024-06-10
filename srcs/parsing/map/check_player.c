/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:25:20 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/10 17:25:44 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	check_player(char *tab)
{
	int	i;
	int	player;

	i = -1;
	player = 0;
	while (tab[++i])
	{
		if (is_player(tab[i]))
			player++;
	}
	return (player);
}

int	no_player(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (check_player(tab[i]))
			return (0);
	}
	return (1);
}

int	too_much_players(char **tab)
{
	int	i;
	int	player;

	i = -1;
	player = 0;
	while (tab[++i])
	{
		player += check_player(tab[i]);
	}
	if (player != 1)
		return (1);
	return (0);
}
