/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:22:26 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/29 17:47:02 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	nb_textures(char **tab)
{
	int	size;

	size = tab_size(tab);
	if (size != 4)
		return (1);
	return (0);
}

int	is_xpm_file(const char *path)
{
	const char	*extension;

	extension = ft_strrchr(path, '.');
	if (extension != NULL && ft_strcmp(extension, ".xpm") == 0)
		return (0);
	return (1);
}

int	is_valid_path_start(const char *path)
{
	if ((ft_strncmp(path, "./", 2) == 0) || (ft_strncmp(path, "/", 1) == 0))
		return (0);
	return (1);
}

int	is_valid_texture_format(char **tab)
{
	char	*line;
	char	*new_line;
	int		i;

	i = 0;

	while (tab[i])
	{
		line = tab[i];
		if (!ft_strncmp(line, "NO ", 3) || !ft_strncmp(line, "SO ", 3) ||
        !ft_strncmp(line, "WE ", 3) || !ft_strncmp(line, "EA ", 3)) 
		{
			new_line = skip_whitespace(line + 3);
		}
		if ((is_valid_path_start(new_line) != 0) || is_xpm_file(new_line) != 0)
			return (1);
		i++;
	}
	return (0);
}

int check_correct_directions(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (ft_strncmp(tab[i], "NO", 2) && ft_strncmp(tab[i], "SO", 2) && \
		ft_strncmp(tab[i], "WE", 2) && ft_strncmp(tab[i], "EA", 2))
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
		return (1);
	if (check_every_directions(tab))
		return (1);
	return (0);	
}

int parse_textures(char **tab)
{
	int	i;

	i = 0;
	if (nb_textures(tab))
		return (print_err(TEXTURE_SIZE), 1);
	if (check_directions(tab))
		return (print_err(TEXTURE_MIS_DUP), 1);
	if (is_valid_texture_format(tab))
		return(print_err(TEXTURE_PATH), 1);
	return (0);
}
