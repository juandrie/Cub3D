/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabdli <cabdli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:34:16 by cabdli            #+#    #+#             */
/*   Updated: 2024/05/20 13:20:42 by cabdli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_map
{
	char			*line;
	struct s_map	*next;
}t_map;

typedef struct s_data
{
	t_map	*map_list;
	char	**map_tab;
}t_data;

/* init_data.c */
t_data	*init_data(char *filename);

/* init_map_list.c */
t_map	*init_map_list(char *filename);

/* init_map_list_utils.c */
int		open_fd(int *fd, char *filename);
void	replace_nl(char *line);
void	free_map_list(t_map *list, char *str);

/* parse_map.c */
int		parse_map(void);

#endif