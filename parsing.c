/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 13:32:18 by mtrembla          #+#    #+#             */
/*   Updated: 2022/07/04 09:52:38 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int fd;
	int line;
	int lineret;
	int len;

	line = 0;
	fd = open(argv[1], O_RDONLY);
	while(ft_gnl(fd))
		line++;
	lineret = line;
	close(fd);
	fd = open(argv[1], O_RDONLY);
	len = ft_strlen(ft_gnl(fd));
	while(--line)
	{
		if (ft_strlen(ft_gnl(fd)) != len)
		return(write(1, "map invalid", 11));
	}
	printf("%d, %d", lineret, len);
	return(1);
}

//ligne et col dans même fonction avec open/close du fd. utiliser struct pour prendre argv[1] dans main
/*int	main(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	//printf("%d\n", ft_ligne(fd));
	printf("%d\n", ft_col(fd));
}*/