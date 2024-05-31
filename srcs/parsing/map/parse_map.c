/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:03:08 by cabdli            #+#    #+#             */
/*   Updated: 2024/05/31 18:51:41 by cabdli           ###   ########.fr       */
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

int	is_wrong_char(char c)
{
	return (c != '0' && c != '1' && c != 'N' \
	&& c != 'S' && c != 'E' && c != 'W' && c != ' ');
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

// int	check_line_border(char *tab)
// {
// 	int	i;

// 	i = -1;
// 	while (tab[++i])
// 	{
// 		if (!is_space_or_one(tab[i]))
// 			return (1);
// 	}
// }

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

int	find_longer_line(char **tab)
{
	int	i;
	int	len;
	int	line;
	int	longer;

	i = -1;
	len = 0;
	line = 0;
	longer = 0;
	while (tab[++i])
	{
		len = ft_strlen(tab[i]);
		if (len > longer)
			line = i;
	}
	return (i);
}

int	check_borders_up_down(char **tab)
{
	int	i;
	int	longer;

	i = -1;
	longer = find_longer_line(tab);
	printf("line = %d\n", longer);
	printf("CHECK TAB : %s\n\n\n", tab[longer]);
	tab = &tab[longer];
	printf("CHECK TAB : %s\n\n\n", *tab);
	while (*tab)
	{
		if (check_line_ud(tab))
			return (1);
		*tab = *(tab + 1);
	}
	return (0);
}

int	check_line_rl(char *tab)
{
	char	*rev_tab;

	tab = skip_whitespace(tab);
	rev_tab = rev_skip_whitespace(tab);
	if (*tab != '1')
		return (1);
	if (*rev_tab != '1')
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
	// while (i < map->width)
	// {
	// 	if (is_space_or_one(map->map_tab[0][i]) || \
	// 	is_space_or_one(map->map_tab[map->height - 1]))
	// 		return (1);
	// 	i++;
	// }
	// i = 0;
	// while (i < map->height)
	// {
	// 	if (is_space_or_one(map->map_tab[0][i]) || \
	// 	is_space_or_one(map->map_tab[map->width - 2]))
	// 		return (1);
	// 	i++;
	// }
	return (0);
}

int find_player_line(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (check_player(tab[i]))
			return (i);
	}
	return (1);
}

int find_player_column(char *tab)
{
	int	col;

	col = 0;
	while (tab[col] && !is_player(tab[col]))
		col++;
	return (col);
}

int	player_left_right(char *tab, int player)
{
	if (player && (tab[player - 1] == '0' || tab[player - 1] == '1'))
		return (0);	
	if (tab[player] && (tab[player + 1] == '0' || tab[player + 1] == '1'))
		return (0);
	return (1);
}

int	player_up_down(char **tab, int line, int column)
{
	if (line && (tab[line - 1][column] == '0' \
	|| tab[line - 1][column] == '1'))
		return (0);	
	if (tab[line] && (tab[line + 1][column] == '0' \
	|| tab[line + 1][column] == '1'))
		return (0);
	return (1);
}

int	player_on_edge(char **tab)
{
	int		line;
	int		column;

	line = find_player_line(tab);
	column = find_player_column(tab[line]);
	if (player_left_right(tab[line], column))
		return (1);
	if (player_up_down(tab, line, column))
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
	if (player_on_edge(tab))
		return (print_err(PLAYER_SURR), 1);
	if (check_borders(tab))
		return (print_err(MAP_BORDERS), 1);
	return (0);
}
