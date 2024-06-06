/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:28:27 by juandrie          #+#    #+#             */
/*   Updated: 2024/06/06 13:38:04 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	**init_tab(t_list *list)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_calloc((list_size(list)) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	while (list)
	{
		tab[i++] = list->line;
		list = list->next;
	}
	return (tab);
}

void	fill_colors(t_list *list, char **tab)
{
	int	i;

	i = 0;
	while (list)
	{
		if (!ft_strncmp(list->line, "F", 1) || \
		!ft_strncmp(list->line, "C", 1))
			tab[i++] = list->line;
		list = list->next;
	}
}

void	fill_textures(t_list *list, char **tab)
{
	int	i;

	i = 0;
	while (list)
	{
		if (!ft_strncmp(list->line, "NO", 2) || \
		!ft_strncmp(list->line, "SO", 2) || !ft_strncmp(list->line, "WE", 2) \
		|| !ft_strncmp(list->line, "EA", 2))
			tab[i++] = list->line;
		list = list->next;
	}
}

char	**init_text_color_tabs(t_list *list, int nb, char c)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_calloc((nb + 1), sizeof(char *));
	if (!tab)
		return (NULL);
	if (c == 'C')
		fill_colors(list, tab);
	else
		fill_textures(list, tab);
	return (tab);
}

void	get_nb_text_color(t_list *text_color_list, int *tc)
{
	while (text_color_list)
	{
		if (!ft_strncmp(text_color_list->line, "F", 1) || \
		!ft_strncmp(text_color_list->line, "C", 1))
			tc[1]++;
		else
			tc[0]++;
		text_color_list = text_color_list->next;
	}
}

int	init_tabs(t_map *map)
{
	int	tc[2];

	ft_bzero(tc, sizeof(tc));
	get_nb_text_color(map->text_color_list, tc);
	map->text_tab = init_text_color_tabs(map->text_color_list, tc[0], 'T');
	map->color_tab = init_text_color_tabs(map->text_color_list, tc[1], 'C');
	map->map_tab = init_tab(map->map_list);
	if (!map->text_tab || !map->color_tab || !map->map_tab)
		return (1);
	return (0);
}
