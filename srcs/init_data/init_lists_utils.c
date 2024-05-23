/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lists_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:57:43 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/23 12:11:39 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

void	free_list(t_list **list, char *str)
{
	t_list	*tmp;

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
void	free_map_lists(t_map *map)
{
    if (!map)
		return;
	free_list(&(map->map_list), NULL);
    free_list(&(map->text_list), NULL);
    free_list(&(map->color_list), NULL);
	free(map->north_texture);
    free(map->south_texture);
    free(map->west_texture);
    free(map->east_texture);
}

void	free_tabs(t_map *map)
{
	int	i;
	if (!map)
		return;
	if (map->map_tab)
	{
        i = 0;
		while (map->map_tab[i] != NULL)
            free(map->map_tab[i++]);
        free(map->map_tab);
    }
    if (map->text_tab)
	{
        i = 0;
		while (map->text_tab[i] != NULL)
            free(map->text_tab[i++]);
			i++;
        free(map->text_tab);
    }
    if (map->color_tab)
	{
        i = 0;
		while (map->color_tab[i] != NULL)
            free(map->color_tab[i++]);
        free(map->color_tab);
    }
}

int	list_size(t_list *list)
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