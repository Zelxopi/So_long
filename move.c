/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:18:07 by mtrembla          #+#    #+#             */
/*   Updated: 2022/07/11 13:37:11 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keyhook(int keycode, t_struct *truc)
{
	if (keycode == 124)
	ft_right(truc);
	if (keycode == 123)
	ft_left(truc);
	if (keycode == 126)
	ft_up(truc);
	if (keycode == 125)
	ft_down(truc);
	return(0);
}

void	ft_right(t_struct *truc)
{
	t_image	*img;
	t_position	*pos;
	t_parsing	*map;

	img = &truc->img;
	pos = &truc->pos;
	map = &truc->map;
	//printf("%c\n", ft_collectibles(pos->playery, pos->playerx + 1, map));
	if(ft_collectibles(pos->playery, pos->playerx + 1, map) != '1')
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->grass, pos->playerx*PIXEL, pos->playery*PIXEL);
		if(ft_collectibles(pos->playery, pos->playerx, map) == 'E')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit, pos->playerx*PIXEL, pos->playery*PIXEL);
		pos->playerx++;
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->dino, pos->playerx*PIXEL, pos->playery*PIXEL);
		if(ft_collectibles(pos->playery, pos->playerx, map) == 'E' && map->collectible == 0)
		exit(0);
	}
}

void	ft_left(t_struct *truc)
{
	t_image	*img;
	t_position	*pos;
	t_parsing	*map;

	img = &truc->img;
	pos = &truc->pos;
	map = &truc->map;
	//printf("%c\n", ft_collectibles(pos->playery, pos->playerx - 1, map));
	if(ft_collectibles(pos->playery, pos->playerx - 1, map) != '1')
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->grass, pos->playerx*PIXEL, pos->playery*PIXEL);
		if(ft_collectibles(pos->playery, pos->playerx, map) == 'E')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit, pos->playerx*PIXEL, pos->playery*PIXEL);
		pos->playerx--;
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->dino, pos->playerx*PIXEL, pos->playery*PIXEL);
		if(ft_collectibles(pos->playery, pos->playerx, map) == 'E' && map->collectible == 0)
		exit(0);
	}
}

void	ft_up(t_struct *truc)
{
	t_image	*img;
	t_position	*pos;
	t_parsing	*map;

	img = &truc->img;
	pos = &truc->pos;
	map = &truc->map;
	//printf("%c\n", ft_collectibles(pos->playery - 1, pos->playerx, map));
	if(ft_collectibles(pos->playery - 1, pos->playerx, map) != '1')
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->grass, pos->playerx*PIXEL, pos->playery*PIXEL);
		if(ft_collectibles(pos->playery, pos->playerx, map) == 'E')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit, pos->playerx*PIXEL, pos->playery*PIXEL);
		pos->playery--;
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->dino, pos->playerx*PIXEL, pos->playery*PIXEL);
		if(ft_collectibles(pos->playery, pos->playerx, map) == 'E' && map->collectible == 0)
		exit(0);
	}
}

void	ft_down(t_struct *truc)
{
	t_image	*img;
	t_position	*pos;
	t_parsing	*map;

	img = &truc->img;
	pos = &truc->pos;
	map = &truc->map;
	//printf("%c\n", ft_collectibles(pos->playery + 1, pos->playerx, map));
	if(ft_collectibles(pos->playery + 1, pos->playerx, map) != '1')
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->grass, pos->playerx*PIXEL, pos->playery*PIXEL);
		if(ft_collectibles(pos->playery, pos->playerx, map) == 'E')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit, pos->playerx*PIXEL, pos->playery*PIXEL);
		pos->playery++;
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->dino, pos->playerx*PIXEL, pos->playery*PIXEL);
		if(ft_collectibles(pos->playery, pos->playerx, map) == 'E' && map->collectible == 0)
		exit(0);
	}
}