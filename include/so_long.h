/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:49:58 by echavez-          #+#    #+#             */
/*   Updated: 2023/07/11 14:02:38 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <errno.h>
# include <string.h>
# include <mlx.h>

# define WALL "./media/bluetorch.xpm"
# define FREE_SPACE "./media/wall1.xpm"
# define COLLECTIBLE "./media/wall1.xpm"
# define EXIT "./media/wall1.xpm"
# define PLAYER "./media/wall1.xpm"

# define E_CLOSE 131072
# define SPRITE 36

/*
**	Terrain types:
**       0 - Empty Space
**           Active: N/A Inactive: N/A
**
**       1 - Wall
**           Active: N/A Inactive: N/A
**
**       C - Empty Space with collectible
**           Active: C   Inactive: 0
**
**       E - Empty Space with exit door
**           Active: E   Inactive: 0
**	Status:
**	     1 - Active
**       0 - Inactive
*/

typedef struct s_terrain {
	char		type;
	int			x;
	int			y;
	t_bool		status;
}	t_terrain;

typedef struct s_player {
	int			x;
	int			y;
}	t_player;

typedef struct s_img
{
	void		*img;
	int			bpp;
	int			bpl;
	int			endian;
	char		*data;
	int			width;
	int			height;
}	t_img;

/*
**  win := windows
*/
typedef struct s_graphics {
	void		*mlx;
	void		*win;
	t_img		**img;
	int			local_endian;
}	t_graphics;

/*
**	collects := Collectibles counter
**  g := graphics
*/

typedef struct s_sl {
	char		*filename;
	int			fd;

	int			collects;
	int			map_height;
	int			map_width;

	t_terrain	**map;
	t_player	p;
	t_terrain	e;
	t_terrain	*c;

	t_graphics	g;
}	t_sl;

/*
**	Main
*/

void	exit_error(char *e);
t_sl	*ft_sl(void);

/*
**	Analyzer
*/

int		valid_name(char *filename);
void	read_map(void);
void	verify_map(void);
void	verify_wall(char *line, int size, int fd, int row);
void	verify_line(char *line, int fd);
void	exit_error_gnl(char *e);

/*
**  Load
*/

void	load_map(void);

/*
**	Graphics
*/

void	init_graphics(void);
void		ft_plotrt(void);

#endif
