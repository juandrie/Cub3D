/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:22:26 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/28 18:55:12 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*skip_whitespace(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\r' || *str == '\v')
		str++;
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


int	nb_textures(char **tab)
{
	int	size;

	size = tab_size(tab);
	if (size != 4)
		return (1);
	return (0);
}

int is_valid_path_start(const char *path)
{
	if (ft_strncmp(path, "./textures/", 11) == 0 )
		return (0);
	return (1); 
}
int is_valid_texture_format(char *line, const char *direction)
{
    char	*path_start;
	char	*new_line;
	
	if (ft_strncmp(line, direction, 2) != 0 || line[2] != ' ')
		return (1);
    path_start = line + 3;
	new_line = skip_whitespace(path_start);
	if ((is_valid_path_start(new_line) == 0) && (ft_strnstr(new_line, "./", 2) == path_start))
		return (0);
    return (1);
}
int	direction_found(int *found)
{
	int	i;

	i = 0;
    while (i < 4)
    {
        if (!found[i])
            return (print_err(TEXTURE_MISSING), 1);
		i++;
    }
	return(0);
}
int check_for_duplicates(int *found)
{
    int	i;

	i = 0;
	while (i < 4) 
	{
        if (found[i] > 1)
			return (1);
		i++;
    }
    return (0);
}

int parse_textures(char **tab)
{
    int			i;
	int			j;
	char		*line;
    const char	*directions[] = {"NO", "SO", "WE", "EA"};
    int 		found[4] = {0, 0, 0, 0};

	if (nb_textures(tab))
		return (print_err(TEXTURE_SIZE), 1);
	i = 0;
    while (i < 4)
    {
        line = skip_whitespace(tab[i]);
		j = 0;
		while (j < 4)
		{
            if (ft_strncmp(line, directions[j], 2) == 0 && line[2] == ' ')
			{
                if (is_valid_texture_format(line, directions[j]))
                    return (print_err(TEXTURE_FORMAT), 1);
                found[j]++;
                break;
			}
			j++;
        }
		i++;
    }
	if (check_for_duplicates(found))
    	return (print_err(TEXTURE_DUPLICATE), 1);
	if (direction_found(found))
		return (1);
    return (0);
}
