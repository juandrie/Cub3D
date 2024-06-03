/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:46:21 by cabdli            #+#    #+#             */
/*   Updated: 2024/06/03 17:35:57 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*skip_whitespace(char *str)
{
	while (*str && (*str == ' ' || *str == '\t' || *str == '\r' \
	|| *str == '\v' || *str == '\f'))
		str++;
	return (str);
}

char	*rev_skip_whitespace(char *str)
{
	int	len;

	len = ft_strlen(str);
	str = &str[len - 1];
	while (len > 0 && (*str == ' ' || *str == '\t' || *str == '\r' \
	|| *str == '\v' || *str == '\f'))
		str--;
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

char	*get_text_path(char *str)
{
	char	*path;

	path = str + 2;
	path = skip_whitespace(path);
	return (path);
}

int	find_map_width(char **tab)
{
	int	i;
	int	len;
	int	longer;

	i = -1;
	len = 0;
	longer = 0;
	while (tab[++i])
	{
		len = ft_strlen(tab[i]);
		if (len > longer)
			longer = len;
	}
	return (longer);
}

// int find_player_line(char **tab)
// {
// 	int	i;

// 	i = -1;
// 	while (tab[++i])
// 	{
// 		if (check_player(tab[i]))
// 			return (i);
// 	}
// 	return (1);
// }

// int find_player_column(char *tab)
// {
// 	int	col;

// 	col = 0;
// 	while (tab[col] && !is_player(tab[col]))
// 		col++;
// 	return (col);
// }
