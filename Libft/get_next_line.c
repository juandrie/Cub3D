/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:47:51 by cabdli            #+#    #+#             */
/*   Updated: 2024/06/11 11:48:41 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* if (!save), faut-il free(buff) avant de return null ?*/

static char	*ft_read_save(int fd, char *save)
{
	char	*buff;
	char	*tmp;
	int		read_bytes;

	read_bytes = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while ((!ft_strchr(save, '\n')) && (read_bytes != 0))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buff), free(save), NULL);
		buff[read_bytes] = '\0';
		tmp = save;
		save = ft_strjoin(save, buff);
		free(tmp);
		if (!save)
			return (free(buff), NULL);
	}
	free(buff);
	return (save);
}

static char	*ft_get_line(char *save)
{
	int		i;
	char	*str;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

static char	*ft_save(char *save)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i] || !save[i + 1])
		return (free(save), NULL);
	str = malloc((ft_strlen(save) - i) * sizeof(char));
	if (!str)
		return (free(save), NULL);
	while (save[++i])
		str[j++] = save[i];
	str[j] = '\0';
	free(save);
	return (str);
}

char	*get_next_line(int fd, t_map *map)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX - 1)
		return (NULL);
	save = ft_read_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	if (!line)
		return (free(save), NULL);
	save = ft_save(save);
	map->save = save;
	return (line);
}
