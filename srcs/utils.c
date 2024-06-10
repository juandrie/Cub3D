/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:46:21 by cabdli            #+#    #+#             */
/*   Updated: 2024/06/10 17:59:33 by juandrie         ###   ########.fr       */
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

char	*rev_skip_whitespace_borders(char *str)
{
	int	len;

	len = ft_strlen(str);
	str = &str[len - 1];
	while (len > 0 && (*str == ' ' || *str == '\t' || *str == '\r' \
	|| *str == '\v' || *str == '\f'))
	{
		str--;
		len--;
	}
	return (str);
}

char	*rev_skip_whitespace_path(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (len > 0 && (str[len - 1] == ' ' || \
	str[len - 1] == '\t' || str[len - 1] == '\r' || \
	str[len - 1] == '\v' || str[len - 1] == '\f'))
	{
		len--;
	}
	str[len] = '\0';
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
	path = rev_skip_whitespace_path(path);
	return (path);
}
