/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:22:26 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/27 19:07:01 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*skip_whitespace(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\r' || *str == '\v')
		str++;
	return (str);
}

int	tab_size(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}


int	nb_textures(char **tab)
{
	int	size;

	size = tab_size(tab);
	if (size != 4)
		return (1);
	return (0);
}
int parse_textures(char **tab)
{
	int			i;
	char		*line;
	const char	*directions[] = {"NO","SO", "WE", "EA"};

	i = 0;
	if (nb_textures(tab))
		return (print_err(TEXTURE_S), 1);
	while (i < 4)
	{
		line = skip_whitespace(tab[i]);
		if (ft_strncmp(line, directions[i], 2) != 0)
			return (print_err(TEXTURE_D), 1);
		i++;
	}
	return (0);
}