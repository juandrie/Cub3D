/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:19:13 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/10 17:28:31 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	map_missing(char **tab)
{
	return (!tab[0]);
}

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_wrong_char(char c)
{
	return (c != '0' && c != '1' && !is_player(c) && !ft_isspace(c));
}

int	is_space_or_one(char c)
{
	if (ft_isspace(c) || c == '1')
		return (0);
	return (1);
}
