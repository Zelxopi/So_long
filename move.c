/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:18:07 by mtrembla          #+#    #+#             */
/*   Updated: 2022/07/11 17:07:58 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keyhook(int keycode, t_struct *truc)
{
	t_image		*img;
	t_parsing	*map;

	img = &truc->img;
	map = &truc->map;
	if (keycode == 2)
		ft_right(map, img);
	if (keycode == 0)
		ft_left(map, img);
	if (keycode == 13)
		ft_up(map, img);
	if (keycode == 1)
		ft_down(map, img);
	if (keycode == 53)
		ft_bankruptcy(truc);
	return (0);
}

void	ft_right(t_parsing *map, t_image *img)
{
	if (ft_collectibles(map->playery, map->playerx + 1, map) != '1')
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->grass,
			map->playerx * PIXEL, map->playery * PIXEL);
		printf("%d\n", ++img->move_count);
		if (ft_collectibles(map->playery, map->playerx, map) == 'E')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit,
				map->playerx * PIXEL, map->playery * PIXEL);
		map->playerx++;
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->dino,
			map->playerx * PIXEL, map->playery * PIXEL);
		if (ft_collectibles(map->playery, map->playerx, map) == 'E'
			&& map->collectible == 0)
			exit(0);
	}
}

void	ft_left(t_parsing *map, t_image *img)
{
	if (ft_collectibles(map->playery, map->playerx - 1, map) != '1')
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->grass,
			map->playerx * PIXEL, map->playery * PIXEL);
		printf("%d\n", ++img->move_count);
		if (ft_collectibles(map->playery, map->playerx, map) == 'E')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit,
				map->playerx * PIXEL, map->playery * PIXEL);
		map->playerx--;
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->dino,
			map->playerx * PIXEL, map->playery * PIXEL);
		if (ft_collectibles(map->playery, map->playerx, map) == 'E'
			&& map->collectible == 0)
			exit(0);
	}
}

void	ft_up(t_parsing *map, t_image *img)
{
	if (ft_collectibles(map->playery - 1, map->playerx, map) != '1')
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->grass,
			map->playerx * PIXEL, map->playery * PIXEL);
		printf("%d\n", ++img->move_count);
		if (ft_collectibles(map->playery, map->playerx, map) == 'E')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit,
				map->playerx * PIXEL, map->playery * PIXEL);
		map->playery--;
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->dino,
			map->playerx * PIXEL, map->playery * PIXEL);
		if (ft_collectibles(map->playery, map->playerx, map) == 'E'
			&& map->collectible == 0)
			exit(0);
	}
}

void	ft_down(t_parsing *map, t_image *img)
{
	if (ft_collectibles(map->playery + 1, map->playerx, map) != '1')
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->grass,
			map->playerx * PIXEL, map->playery * PIXEL);
		printf("%d\n", ++img->move_count);
		if (ft_collectibles(map->playery, map->playerx, map) == 'E')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit,
				map->playerx * PIXEL, map->playery * PIXEL);
		map->playery++;
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->dino,
			map->playerx * PIXEL, map->playery * PIXEL);
		if (ft_collectibles(map->playery, map->playerx, map) == 'E'
			&& map->collectible == 0)
			exit(0);
	}
}
