/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:03:08 by cabdli            #+#    #+#             */
/*   Updated: 2024/06/03 15:45:44 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	map_missing(char **tab)
{
	return (!tab[0]);
}

int	empty_line(char **tab)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = NULL;
	while (tab[++i])
	{
		if (!ft_strncmp(tab[i], "\n", 2))
			return (1);
		tmp = skip_whitespace(tab[i]);
		if (!*tmp)
			return (1);
	}
	return (0);
}

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_wrong_char(char c)
{
	return (c != '0' && c != '1' && !is_player(c) && !ft_isspace(c));
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

int	check_line_ud(char **tab)
{
	char	**rev_tab;

	tab = &tab[0];
	tab = skip_whitespace_line(tab);
	rev_tab = rev_skip_whitespace_line(tab);
	if (**tab != '1')
		return (1);
	if (**rev_tab != '1')
		return (1);
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

int	check_line_rl(char *tab)
{
	char	*rev_tab;

	tab = skip_whitespace(tab);
	rev_tab = rev_skip_whitespace(tab);
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

int	check_borders(char **tab)
{
	if (check_borders_right_left(tab))
		return (1);
	if (check_borders_up_down(tab))
		return (1);
	return (0);
}


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
	if (check_borders(tab))
		return (print_err(MAP_BORDERS), 1);
	if (check_around_spaces(tab))
		return (print_err(SPACE_WALLS), 1);
	return (0);
}
