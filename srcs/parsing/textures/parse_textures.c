/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:22:26 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/05 13:16:03 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

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

int	check_directions(char **tab)
{
	if (check_correct_directions(tab))
		return (print_err(TEXTURE_INVAL), 1);
	if (check_every_directions(tab))
		return (print_err(TEXTURE_DUPLICATED), 1);
	return (0);
}

int	check_texture_format(char **tab)
{
	char	*line;
	int		i;
	int		fd;

	i = -1;
	fd = 0;
	while (tab[++i])
	{
		line = get_text_path(tab[i]);
		fd = open(line, O_RDONLY);
		if (fd == -1)
			return (1);
		close(fd);
	}
	return (0);
}

int	parse_textures(char **tab)
{
	if (check_nb_textures(tab))
		return (print_err(TEXTURE_SIZE), 1);
	if (check_directions(tab))
		return (1);
	if (check_texture_format(tab))
		return (print_err(TEXTURE_PATH), 1);
	return (0);
}
