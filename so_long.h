/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:29:46 by mtrembla          #+#    #+#             */
/*   Updated: 2022/07/06 10:40:01 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct 	parsing
{
	int	map_height;
	char *mapfile;
	int map_len;
	int personnage;
	int	sortie;
	int collectible;
}	parsing;

void	ft_error(char *str);
int		ft_map_is_square(parsing *map);
int		ft_peandc(parsing *map);
int		ft_topandbottom(parsing *map);
int		ft_firstandlast(parsing *map);
int		ft_mapname(parsing *map);
void	ft_I_DO_DECLARE(parsing *map);
int		ft_parsing(parsing *map);