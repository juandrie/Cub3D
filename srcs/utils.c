/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:46:21 by cabdli            #+#    #+#             */
/*   Updated: 2024/05/31 18:17:53 by cabdli           ###   ########.fr       */
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

char	**skip_whitespace_line(char **str)
{
	while (*str && (**str == ' ' || **str == '\t' || **str == '\r' \
	|| **str == '\v' || **str == '\f'))
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

char	**rev_skip_whitespace_line(char **str)
{
	int	len;

	len = tab_size(str);
	str = &str[len - 1];
	while (len > 0 && (**str == ' ' || **str == '\t' || **str == '\r' \
	|| **str == '\v' || **str == '\f'))
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
