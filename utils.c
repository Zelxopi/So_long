/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:50:49 by mtrembla          #+#    #+#             */
/*   Updated: 2022/07/08 17:18:28 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_I_DO_DECLARE(t_parsing *map, t_image *img)
{
	map->personnage = 0;
	map->sortie = 0;
	map->collectible = 0;
	img->y = -1;
	img->mlx = mlx_init();

	img->dino = mlx_xpm_file_to_image(img->mlx, "sprites/dino2.xpm", &img->width, &img->height);
	img->grass = mlx_xpm_file_to_image(img->mlx, "sprites/grass.xpm", &img->width, &img->height);
	img->chicken = mlx_xpm_file_to_image(img->mlx, "sprites/chicken.xpm", &img->width, &img->height);
	img->wall = mlx_xpm_file_to_image(img->mlx, "sprites/plant.xpm", &img->width, &img->height);
	img->exit = mlx_xpm_file_to_image(img->mlx, "sprites/fire.xpm", &img->width, &img->height);
}

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}
