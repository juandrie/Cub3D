/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:26:51 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/30 18:37:40 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	nb_textures(char **tab)
{
	int	size;

	size = tab_size(tab);
	if (size != 4)
		return (1);
	return (0);
}

int	is_valid_path_start(const char *path)
{
	if ((ft_strncmp(path, "./", 2) == 0))
		return (0);
	return (1);
}

int	is_valid_texture_format(char **tab)
{
	char	*line;
	int		i;

	i = -1;
	while (tab[++i])
	{
		line = tab[i] + 2;
		line = skip_whitespace(line);
		if ((is_valid_path_start(line) != 0))
			return (1);
		if (!is_correct_extension(line, ".xpm"))
			return (1);
	}
	return (0);
}

int	check_correct_directions(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (ft_strncmp(tab[i], "NO ", 3) && ft_strncmp(tab[i], "SO ", 3) && \
		ft_strncmp(tab[i], "WE ", 3) && ft_strncmp(tab[i], "EA ", 3))
			return (1);
	}
	return (0);
}

int	check_every_directions(char **tab)
{
	int	i;
	int	dir[4];

	i = -1;
	ft_bzero(dir, sizeof(dir));
	while (tab[++i])
	{
		if (!ft_strncmp(tab[i], "NO", 2))
			dir[0] = 1;
		if (!ft_strncmp(tab[i], "SO", 2))
			dir[1] = 1;
		if (!ft_strncmp(tab[i], "WE", 2))
			dir[2] = 1;
		if (!ft_strncmp(tab[i], "EA", 2))
			dir[3] = 1;
	}
	if (!dir[0] || !dir[1] || !dir[2] || !dir[3])
		return (1);
	return (0);
}
