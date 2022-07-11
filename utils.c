/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:50:49 by mtrembla          #+#    #+#             */
/*   Updated: 2022/07/11 17:10:08 by mtrembla         ###   ########.fr       */
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
}

void	ft_mlx_declare(t_image *img)
{
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

int	ft_bankruptcy(t_struct *truc)
{
	int			i;
	t_parsing	*map;
	t_image		*img;

	i = 0;
	img = &truc->img;
	map = &truc->map;
	while (map->mapcpy[i])
		free(map->mapcpy[i++]);
	free(map->mapcpy);
	mlx_destroy_image(img->mlx, img->wall);
	mlx_destroy_image(img->mlx, img->grass);
	mlx_destroy_image(img->mlx, img->exit);
	mlx_destroy_image(img->mlx, img->chicken);
	mlx_destroy_image(img->mlx, img->dino);
	exit(0);
}

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}
