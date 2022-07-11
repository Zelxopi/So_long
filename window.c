/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:10:51 by mtrembla          #+#    #+#             */
/*   Updated: 2022/07/11 13:13:04 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_print(t_struct *truc)
{
	t_image	*img;
	t_parsing *map;

	map = &truc->map;
	img = &truc->img;
	map->heightcpy = map->map_height;
	map->fd = open(map->mapfile, O_RDONLY);
	while (map->heightcpy--)
	{
		img->x = 0;
		img->y++;
		map->str = ((char*)ft_gnl(map->fd));
		while (*map->str)
		{
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->grass, img->x*PIXEL, img->y*PIXEL);
			if(*map->str == '1')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->wall, img->x*PIXEL, img->y*PIXEL);
			if(*map->str == 'P')
			ft_dinopos(truc, img->x, img->y);
			if(*map->str == 'C')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->chicken, img->x*PIXEL, img->y*PIXEL);
			if(*map->str++ == 'E')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit, img->x*PIXEL, img->y*PIXEL);
			img->x++;
		}
	}
	close(map->fd);
}
void	ft_dinopos(t_struct *truc, int x, int y)
{
	t_position	*pos;
	t_image		*img;

	pos = &truc->pos;
	img = &truc->img;
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->dino, x*PIXEL, y*PIXEL);
	pos->playerx = x;
	pos->playery = y;
	//printf("%d,%d\n", pos->playery, pos->playerx);
}

int	ft_tell_me_whats_there(int line, int col, t_parsing *map)
{
	line += 1;
	col +=1;
	map->fd = open(map->mapfile, O_RDONLY);
	while(line--)
		map->str = ((char*)ft_gnl(map->fd));
	while(--col)
		map->str++;
	close(map->fd);
	return(*map->str);
}

int	main(int argc, char **argv)
{
	t_struct	truc;
	t_parsing	*map;
	t_image		*img;
	//t_position	*pos;

	(void)argc;
	map = &truc.map;
	img = &truc.img;
//	pos = &truc.pos;
	ft_I_DO_DECLARE(map, img);
	ft_parsing(argv[1], &truc);
	img->mlx_win = mlx_new_window(img->mlx, map->map_len*PIXEL, map->map_height*PIXEL, "so_long");
	ft_map_print(&truc);
	ft_mapcpy(map);
	printf("la ligne: %s\n", map->mapcpy[3]);
	printf("%c\n", ft_collectibles(3, 8, map));
	printf("%c\n", ft_tell_me_whats_there(3, 8, map));
	//printf("%c\n", ft_tell_me_whats_there(pos->playery, pos->playerx, &truc));
	mlx_key_hook(img->mlx_win, ft_keyhook, &truc);
	mlx_loop(img->mlx);
}