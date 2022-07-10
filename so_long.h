/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:29:46 by mtrembla          #+#    #+#             */
/*   Updated: 2022/07/10 10:42:52 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minilibx/mlx.h"
#include <fcntl.h>
#include <stdio.h>

#define PIXEL 70

typedef struct 	s_parsing
{
	int	map_height;
	char *mapfile;
	int map_len;
	int personnage;
	int	sortie;
	int collectible;
	char	*str;
	int		fd;
}	t_parsing;

typedef struct	s_image 
{
	void	*dino;
	void	*chicken;
	void	*grass;
	void	*wall;
	void	*exit;
	int		width;
	int		height;
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
}	t_image;


void	ft_error(char *str);
int		ft_map_is_square(t_parsing *map);
int		ft_peandc(t_parsing *map);
int		ft_topandbottom(t_parsing *map);
int		ft_firstandlast(t_parsing *map);
int		ft_mapname(t_parsing *map);
void	ft_I_DO_DECLARE(t_parsing *map, t_image *img);
int		ft_parsing(char *k, t_parsing *map);
void	ft_map_print(t_parsing *map, t_image *img);
int 	ft_tell_me_whats_there(int x, int y, t_parsing *map);