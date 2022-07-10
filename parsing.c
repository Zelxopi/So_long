/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 09:50:19 by mtrembla          #+#    #+#             */
/*   Updated: 2022/07/07 14:06:10 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

int	ft_parsing(char *k, t_parsing *map)
{
	map->mapfile = k;
	if (ft_mapname(map) == 1 && ft_map_is_square(map) == 1
		&& ft_peandc(map) == 1 && ft_topandbottom(map) == 1
		&& ft_firstandlast(map) == 1)
		return (1);
	else
		return (-1);
}

/*int	main(int argc, char **argv)
{
	parsing		*map;

	(void)argc;
	map = malloc(sizeof(parsing));
	map->mapfile = argv[1];
	printf("%d\n", ft_parsing(map));
}*/
