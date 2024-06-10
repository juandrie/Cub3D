/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:03:08 by cabdli            #+#    #+#             */
/*   Updated: 2024/06/10 17:25:48 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

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
