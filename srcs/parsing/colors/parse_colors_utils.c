/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:38:06 by cabdli            #+#    #+#             */
/*   Updated: 2024/06/10 17:59:41 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	is_comma(char c)
{
	return (c == ',');
}

int	is_nb(char c)
{
	return (c >= '0' && c <= '9');
}

char	*remove_spaces(char *str)
{
	char	*out;
	char	*dst;

	out = str;
	dst = str;
	while (*str != '\0')
	{
		if (*str != ' ' && *str != '\t' && *str != '\r' \
		&& *str != '\v' && *str != '\f')
			*dst++ = *str;
		str++;
	}
	*dst = '\0';
	return (out);
}
