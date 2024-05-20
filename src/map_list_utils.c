/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:12:24 by cabdli            #+#    #+#             */
/*   Updated: 2024/05/20 13:48:51 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	open_fd(int *fd, char *filename)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
		return (perror(""), 1);
	return (0);
}

void	ft_replace_nl(char *line)
{
	int	len;

	len = (int)ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
}

void	free_map_list(t_map **list, char *str)
{
	t_map	*tmp;

	tmp = NULL;
	if (!(*list))
		return ;
	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp->line);
		free(tmp);
	}
	if (str)
		free(str);
	*list = NULL;
}

int	list_size(t_map *list)
{
	int	size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}