/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:22:26 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/30 18:38:20 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/cub3d.h"

int	check_directions(char **tab)
{
	if (check_correct_directions(tab))
		return (print_err(TEXTURE_MISSING), 1);
	if (check_every_directions(tab))
		return (print_err(TEXTURE_DUPLICATED), 1);
	return (0);
}

int	parse_textures(char **tab)
{
	if (nb_textures(tab))
		return (print_err(TEXTURE_SIZE), 1);
	if (check_directions(tab))
		return (1);
	if (is_valid_texture_format(tab))
		return (print_err(TEXTURE_PATH), 1);
	return (0);
}
