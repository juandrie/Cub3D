/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:26:51 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/31 14:35:53 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	check_nb_textures(char **tab)
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
