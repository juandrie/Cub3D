/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:12:07 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/31 12:44:51 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*skip_whitespace(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\r' || *str == '\v')
		str++;
	return (str);
}

int	is_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\r' || \
	c == '\n' || c == '\v' || c == '\f');
}

int	is_space_or_one(char c)
{
	if (is_space(c) || c == '1')
		return (0);
	return (1);
}

int	tab_size(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}
