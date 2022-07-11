/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:50:19 by mtrembla          #+#    #+#             */
/*   Updated: 2022/07/11 17:10:14 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	map->mapcpy[i] = NULL;
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

int	ft_parsing(char *k, t_parsing *map)
{
	map->mapfile = k;
	if (ft_mapname(map) == 1 && ft_map_is_square(map) == 1
		&& ft_peandc(map) == 1 && ft_topandbottom(map) == 1
		&& ft_firstandlast(map) == 1)
		return (1);
	else
		exit(0);
}
