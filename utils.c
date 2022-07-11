/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:50:49 by mtrembla          #+#    #+#             */
/*   Updated: 2022/07/11 15:35:46 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_i_do_declare(t_parsing *map, t_image *img)
{
	map->personnage = 0;
	map->sortie = 0;
	map->collectible = 0;
	img->move_count = 0;
	img->y = -1;
	img->mlx = mlx_init();
	img->dino = mlx_xpm_file_to_image(img->mlx, "sprites/dino2.xpm",
			&img->width, &img->height);
	img->grass = mlx_xpm_file_to_image(img->mlx, "sprites/grass.xpm",
			&img->width, &img->height);
	img->chicken = mlx_xpm_file_to_image(img->mlx, "sprites/chicken.xpm",
			&img->width, &img->height);
	img->wall = mlx_xpm_file_to_image(img->mlx, "sprites/plant.xpm",
			&img->width, &img->height);
	img->exit = mlx_xpm_file_to_image(img->mlx, "sprites/fire.xpm",
			&img->width, &img->height);
}

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}

char	**ft_mapcpy(t_parsing *map)
{
	int	i;

	i = 0;
	map->fd = open(map->mapfile, O_RDONLY);
	map->mapcpy = malloc(sizeof(char *) * map->map_height +1);
	while (i < map->map_height)
	{
		map->mapcpy[i] = ft_strdup(((char *)ft_gnl(map->fd)));
		i++;
	}
	return (map->mapcpy);
}

int	ft_collectibles(int line, int col, t_parsing *map)
{
	map->str = map->mapcpy[line];
	while (col--)
	map->str++;
	if (*map->str == 'C')
	{
		map->collectible--;
		*map->str = '0';
		return ('C');
	}
	return (*map->str);
}
