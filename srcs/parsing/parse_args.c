/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:50:22 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/07 16:48:50 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_correct_extension(char *filename, char *str)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (1);
	if (!ft_strncmp(&filename[len - 4], str, 4))
		return (1);
	return (0);
}

int	check_args(int argc, char **argv, char **envp)
{
	if (!envp[0])
		return (ft_putstr_fd("Error:\nNo env\n", STDERR_FILENO), 1);
	if (argc != 2)
		return (ft_putstr_fd("Error:\nEnter ./cub3d NAME.cub\n", \
		STDERR_FILENO), 1);
	if (!is_correct_extension(argv[1], ".cub"))
		return (ft_putstr_fd("Error:\nThe file is not a .cub file\n", \
		STDERR_FILENO), 1);
	return (0);
}
