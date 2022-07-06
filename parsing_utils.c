/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:32:18 by mtrembla          #+#    #+#             */
/*   Updated: 2022/07/06 10:02:59 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>

int	ft_map_is_square(parsing *map)
{
	int		fd;
	int		line;
	size_t	len;

	line = 0;
	fd = open(map->mapfile, O_RDONLY);
	while (ft_gnl(fd))
		line++;
	map->map_height = line;
	close(fd);
	fd = open(map->mapfile, O_RDONLY);
	len = ft_strlen(ft_gnl(fd));
	map->map_len = len;
	while (--line)
	{
		if (ft_strlen(ft_gnl(fd)) != len)
			ft_error("Dimensions de la map sont invalides");
	}
	close(fd);
	return (1);
}

int	ft_peandc(parsing *map)
{
	char	*str;
	int		fd;
	int		heightcpy;
	int		personnage = 0;
	int		sortie = 0;
	int		collectible = 0;

	heightcpy = map->map_height;
	fd = open(map->mapfile, O_RDONLY);
	while (heightcpy--)
	{
		str = ((char *)ft_gnl(fd));
		while (*str)
		{
			if (*str == 'P')
				personnage++;
			if (*str == 'E')
				sortie++;
			if (*str == 'C')
				collectible++;
			str++;
		}
	}
	close(fd);
	if (personnage != 1 || sortie < 1 || collectible < 1)
		ft_error("Erreur au niveau du nombre de P, E ou C");
	return (1);
}

int	ft_topandbottom(parsing *map)
{
	int		fd;
	char	*str;
	int		heightcpy;

	heightcpy = map->map_height;
	fd = open(map->mapfile, O_RDONLY);
	str = ((char *)ft_gnl(fd));
	while (*str)
	{
		if (*str != '1')
			ft_error("Check tes murs du haut");
		str++;
	}
	while (--heightcpy > 1)
		ft_gnl(fd);
	str = ((char *)ft_gnl(fd));
	while (*str)
	{
		if (*str != '1')
			ft_error("Check tes murs du bas");
		str++;
	}
	close(fd);
	return (1);
}

int	ft_firstandlast(parsing *map)
{
	int		fd;
	char	*str;
	int		heightcpy;

	heightcpy = map->map_height;
	fd = open(map->mapfile, O_RDONLY);
	ft_gnl(fd);
	while (heightcpy > 2)
	{	
		str = ((char *)ft_gnl(fd));
		if (*str != '1')
			ft_error("yo tes murs");
		while (*str)
			str++;
		str--;
		if (*str != '1')
			ft_error("yo tes murs");
		heightcpy--;
	}
	close(fd);
	return (1);
}

int	ft_mapname(parsing *map)
{
	char	*str;
	char	*ber;
	int		fd;

	fd = open(map->mapfile, O_RDONLY);
	if (fd == -1)
		ft_error("mauvais nom de map");
	ber = ".ber";
	str = ft_strrchr(map->mapfile, '.');
	if (ft_strncmp(str, ber, 7) != 0)
		ft_error("Ça a pas l'air d'un '.ber' ton affaire");
	return (1);
}