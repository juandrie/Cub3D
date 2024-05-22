/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:02:50 by juandrie          #+#    #+#             */
/*   Updated: 2024/05/22 19:06:17 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


int	loop_hook(t_data *data)
{
	if (!data->window->running)
	{
		mlx_destroy_window(data->window->mlx_ptr, data->window->win_ptr);
		exit(0);
	}
	read_keys(data);
	update_timing_and_movement(data);
	perform_ray_casting(data);
	mlx_put_image_to_window(data->window->mlx_ptr, data->window->win_ptr, data->window->img_ptr, 0, 0);
	return (0);
}

static int	is_cub(char *filename)
{
	int	len;

	// if (!filename)
	// 	return (1);
	len = ft_strlen(filename);
	if (len < 4)
		return (1);
	if (ft_strncmp(&filename[len - 4], ".cub", 4))
		return (1);
	return (0);
}

static int	check_args(int argc, char **argv, char **envp)
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

// int	main(int argc, char **argv)
// {
// 	t_data		*data;

// 	if (argc != 2)
// 	{
// 		printf("Error: %s <map_file.cub>\n", argv[0]);
// 		return (0);
// 	}
// 	data = init_data();
// 	if (!data)
// 		return (0);
// 	data->map->filename = ft_strdup(argv[1]);
// 	read_map(data);
// 	hooks(data);
// 	mlx_destroy_window(data->window->mlx_ptr, data->window->win_ptr);
// 	return (0);
// }

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	data = NULL;
	if (check_args(argc, argv, envp))
		return (1);
	data = init_data(argv[1]);
	if (!data)
		return (1);
	// if (parse_map())
	// 	return (1);
	// start_the_game(data);
	return (0);
}

//create the free_data function
// modifier GNL (enlever la partie parsing de so_long)
// test for an empty map
// check the correct error message
//tester funcheck a la fin de l'initialisation
//ajouter perror a init data

//adapter free_data

/*
prot2ger ces fonctions ? :
window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, 640, 480, "Cub3D");
	window->img_ptr = mlx_new_image(window->mlx_ptr, window->width, window->height);
    window->img_data = mlx_get_data_addr(window->img_ptr, &window->bpp, &window->size_line, &window->endian);

A NE PAS OUBLIER DANS LE PARSING :
// int	parse_texture(char *line, char **texture)
// {
// 	*texture = ft_strdup(ft_strchr(line, ' ') + 1);
// 	if (*texture != NULL)
// 		return (1);
// 	return (0);
// }

// int	parse_color(char *line, int color[3])
// {
// 	char	**rgb;
// 	int		i;

// 	rgb = ft_split(ft_strchr(line, ' ') + 1, ',');
// 	if (!rgb)
// 		return (0);
// 	i = 0;
// 	while (i < 3)
// 	{
// 		color[i] = ft_atoi(rgb[i]);
// 		free(rgb[i]);
// 		i++;
// 	}
// 	free(rgb);
// 	return (1);
// }

// 	if (!init_player_position(data))//(!data->player_initialized)
// 	{
//         printf("Error: No player start position found.\n");
//         return (0);
//     }


- Ajouter free_lists dans lequel on fera appel
a free_list (3 fois, pr chq list), et on passe le ptr de
la liste pour le mettre a NULL et eviter le dble free

- Caracteres incorrectes en dehores de map, texture et couleurs a prendre en compte ?

- revoir toute l'initialisation en pensant bien a gerer les erreurs de mallocs, es frees ect

- void init_texture(t_texture *texture, void *mlx_ptr, char *filepath)
{
	texture->img_ptr = mlx_xpm_file_to_image(mlx_ptr, filepath, &texture->width, &texture->height);
    if (!texture->img_ptr)
    {
        printf("Error loading texture from %s\n", filepath);
        exit(1);
    }
    texture->addr = mlx_get_data_addr(texture->img_ptr, &texture->bpp, &texture->size_line, &texture->endian);
}
t_data	*init_data(void)
{
	int	i;
	
	i = -1;
	data->texture = ft_calloc(4, sizeof(t_texture));
	if (!data->texture)
		return (free(data), free(data->player), free(data->window), free(data->map), NULL);
	init_texture(&data->texture[0], data->window->mlx_ptr, "path_to_north_texture.xpm");
	init_texture(&data->texture[1], data->window->mlx_ptr, "path_to_south_texture.xpm");
	init_texture(&data->texture[2], data->window->mlx_ptr, "path_to_west_texture.xpm");
	init_texture(&data->texture[3], data->window->mlx_ptr, "path_to_east_texture.xpm");
	// data->keycode = 0;
	return (data);
}
*/
