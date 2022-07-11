/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:32:18 by mtrembla          #+#    #+#             */
/*   Updated: 2022/07/11 18:38:02 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_is_square(t_parsing *map)
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

int	ft_peandc(t_parsing *map)
{
	map->heightcpy = map->map_height;
	map->fd = open(map->mapfile, O_RDONLY);
	while (map->heightcpy--)
	{
		map->str = ((char *)ft_gnl(map->fd));
		while (*map->str++)
		{
			if (*map->str != '1' && *map->str != '0' && *map->str != 'P'
				&& *map->str != 'E' && *map->str != 'C' && *map->str != '\n'
				&& *map->str != '\0')
				ft_error("Caractère inconnu dans la carte");
			if (*map->str == 'P')
				map->personnage++;
			if (*map->str == 'E')
				map->sortie++;
			if (*map->str == 'C')
				map->collectible++;
		}
	}
	close(map->fd);
	if (map->personnage != 1 || map->sortie < 1 || map->collectible < 1)
		ft_error("Erreur au niveau du nombre de P(max1), E ou C(min1)");
	return (1);
}

int	ft_topandbottom(t_parsing *map)
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
			ft_error("Le haut de la carte doit être composé de wall(1)");
		str++;
	}
	while (--heightcpy > 1)
		ft_gnl(fd);
	str = ((char *)ft_gnl(fd));
	while (*str)
	{
		if (*str != '1')
			ft_error("Le bas de la carte doit être composé de wall(1)");
		str++;
	}
	close(fd);
	return (1);
}

int	ft_firstandlast(t_parsing *map)
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
			ft_error("le tour de la carte doit être composé de wall(1)");
		while (*str)
			str++;
		str--;
		if (*str != '1')
			ft_error("le tour de la carte doit être composé de wall(1)");
		heightcpy--;
	}
	close(fd);
	return (1);
}

int	ft_mapname(t_parsing *map)
{
	char	*str;
	char	*ber;
	int		fd;

	fd = open(map->mapfile, O_RDONLY);
	if (fd == -1)
		ft_error("Nom de carte inexistant");
	ber = ".ber";
	str = ft_strrchr(map->mapfile, '.');
	if (!str || ft_strncmp(str, ber, 7) != 0)
		ft_error("Doit être un fichier '.ber'");
	return (1);
}
