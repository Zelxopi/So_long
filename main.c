/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:10:51 by mtrembla          #+#    #+#             */
/*   Updated: 2022/07/11 16:47:23 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_print(t_parsing *map, t_image *img)
{
	map->heightcpy = map->map_height;
	map->fd = open(map->mapfile, O_RDONLY);
	while (map->heightcpy--)
	{
		img->x = 0;
		img->y++;
		map->str = ((char *)ft_gnl(map->fd));
		while (*map->str)
		{
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->grass,
				img->x * PIXEL, img->y * PIXEL);
			if (*map->str == '1')
				ft_paint(img, 1);
			if (*map->str == 'P')
				ft_dinopos(img, map, img->x, img->y);
			if (*map->str == 'C')
				ft_paint(img, 3);
			if (*map->str++ == 'E')
				ft_paint(img, 5);
			img->x++;
		}
	}
	close (map->fd);
}

void	ft_paint(t_image *img, int a)
{
	if (a == 1)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->wall,
			img->x * PIXEL, img->y * PIXEL);
	if (a == 3)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->chicken,
			img->x * PIXEL, img->y * PIXEL);
	if (a == 5)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit,
			img->x * PIXEL, img->y * PIXEL);
}

void	ft_dinopos(t_image *img, t_parsing *map, int x, int y)
{
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->dino, x * PIXEL, y * PIXEL);
	map->playerx = x;
	map->playery = y;
}

int	main(int argc, char **argv)
{
	t_struct	truc;
	t_parsing	*map;
	t_image		*img;

	(void)argc;
	map = &truc.map;
	img = &truc.img;
	if (!argv[1])
	ft_error("Manque nom de carte");
	ft_i_do_declare(map, img);
	ft_parsing(argv[1], map);
	ft_mlx_declare(img);
	img->mlx_win = mlx_new_window (img->mlx, map->map_len * PIXEL,
			map->map_height * PIXEL, "so_long");
	ft_map_print(map, img);
	ft_mapcpy(map);
	mlx_key_hook(img->mlx_win, ft_keyhook, &truc);
	mlx_hook(img->mlx_win, 17, 0, ft_bankruptcy, &truc);
	mlx_loop(img->mlx);
}
