/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:29:46 by mtrembla          #+#    #+#             */
/*   Updated: 2022/07/11 16:54:32 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

# define PIXEL 70

typedef struct s_parsing
{
	int		map_height;
	char	*mapfile;
	int		map_len;
	int		personnage;
	int		sortie;
	int		collectible;
	char	*str;
	int		fd;
	int		heightcpy;
	char	**mapcpy;
	int		playerx;
	int		playery;
}	t_parsing;

typedef struct s_image
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
	int		move_count;
}	t_image;

typedef struct s_struct
{
	t_parsing	map;
	t_image		img;
}	t_struct;

void	ft_error(char *str);
int		ft_map_is_square(t_parsing *map);
int		ft_peandc(t_parsing *map);
int		ft_topandbottom(t_parsing *map);
int		ft_firstandlast(t_parsing *map);
int		ft_mapname(t_parsing *map);
void	ft_i_do_declare(t_parsing *map, t_image *img);
int		ft_parsing(char *k, t_parsing *map);
void	ft_map_print(t_parsing *map, t_image *img);
int		ft_keyhook(int keycode, t_struct *truc);
void	ft_dinopos(t_image *img, t_parsing *map, int x, int y);
void	ft_right(t_parsing *map, t_image *img);
void	ft_left(t_parsing *map, t_image *img);
void	ft_up(t_parsing *map, t_image *img);
void	ft_down(t_parsing *map, t_image *img);
char	**ft_mapcpy(t_parsing *map);
int		ft_collectibles(int line, int col, t_parsing *map);
void	ft_paint(t_image *img, int a);
int		ft_bankruptcy(t_struct *truc);
void	ft_mlx_declare(t_image *img);

#endif
