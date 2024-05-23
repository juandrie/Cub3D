/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:50:22 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/23 12:56:48 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int is_cub(char *filename)
{
	int	len;

	// if (!filename)
	// 	return (1);
	len = ft_strlen(filename);
	if (len < 4)
		return (1);
	if (ft_strncmp(&filename[len - 4], ".cub", 4) == 0)
		return (1);
	return (0);
}

int check_args(int argc, char **argv, char **envp)
{
	if (!envp[0])
		return (ft_putstr_fd("Error: no env\n", STDERR_FILENO), 1);
	if (argc != 2)
		return (ft_putstr_fd("Error: enter ./cub3d NAME.cub\n", \
		STDERR_FILENO), 1);
	if (!is_cub(argv[1]))
		return (ft_putstr_fd("Error: the file is not a .cub file\n", \
		STDERR_FILENO), 1);
	return (0);
}