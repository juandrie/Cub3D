/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:03:08 by cabdli            #+#    #+#             */
/*   Updated: 2024/05/30 15:01:40 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	map_missing(char **tab)
{
	return (!tab[0]);
}

int	empty_line(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (!ft_strncmp(tab[i], "\n", 2))
			return (1);
	}
	return (0);
}

int	is_wrong_char(char c)
{
	return (c != '0' && c != '1' && c != 'N' \
	&& c != 'S' && c != 'E' && c != 'W');
}

int	wrong_char(char **tab)
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
			if (is_wrong_char(tab[i][j]))
				return (1);
		}
	}
	return (0);
}

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

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

int	parse_map(char **tab)
{
	if (map_missing(tab))
		return (print_err(EMPTY), 1);
	if (empty_line(tab))
		return (print_err(EMPTY_L), 1);
	if (wrong_char(tab))
		return (print_err(WRONG_C), 1);
	if (no_player(tab))
		return (print_err(NO_PLAYER), 1);
	if (too_much_players(tab))
		return (print_err(MUCH_PLAYERS), 1);
	// if (player_on_edge(tab))
	// 	return (print_err(MUCH_PLAYERS), 1);
	return (0);
}
