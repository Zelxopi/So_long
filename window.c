/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 11:10:51 by mtrembla          #+#    #+#             */
/*   Updated: 2022/07/10 10:58:19 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_print(t_parsing *map, t_image *img)
{
	int		heightcpy;

	heightcpy = map->map_height;
	map->fd = open(map->mapfile, O_RDONLY);
	while (heightcpy--)
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
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->dino, img->x*PIXEL, img->y*PIXEL);
			if(*map->str == 'C')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->chicken, img->x*PIXEL, img->y*PIXEL);
			if(*map->str++ == 'E')
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->exit, img->x*PIXEL, img->y*PIXEL);
			img->x++;
		}
	}
	close(map->fd);
}

int	ft_tell_me_whats_there(int line, int col, t_parsing *map)
{
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
	t_image	*img;
	t_parsing	*map;

	(void)argc;
	map = malloc(sizeof(t_parsing));
	img = malloc(sizeof(t_image));
	ft_I_DO_DECLARE(map, img);
	ft_parsing(argv[1], map);
	img->mlx_win = mlx_new_window(img->mlx, map->map_len*PIXEL, map->map_height*PIXEL, "so_long");
	ft_map_print(map, img);
	printf("%c\n", ft_tell_me_whats_there(2, 9, map));
	
	mlx_loop(img->mlx);
}