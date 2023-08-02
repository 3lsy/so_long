/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:49:58 by echavez-          #+#    #+#             */
/*   Updated: 2023/08/02 22:15:26 by echavez-         ###   ########.fr       */
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

/*
** Terrain
*/

# define FREE  "./media/space/floor.xpm"
# define COLLECT "./media/collect/collectible.xpm"
# define EXIT "./media/exit/floor_ladder.xpm"
# define EXIT_CLOSE "./media/exit/closed.xpm"

/*
** Wall
*/

# define WALL "./media/wall/wall.xpm"
# define R_WALL "./media/wall/right_wall.xpm"
# define L_WALL "./media/wall/left_wall.xpm"
# define TOP_R_CORNER "./media/wall/top_right_corner.xpm"
# define TOP_L_CORNER "./media/wall/top_left_corner.xpm"
# define TOWER "./media/wall/tower.xpm"

/*
** Player
*/

# define D_PLAYER "./media/player/front_v2.xpm"
# define U_PLAYER "./media/player/back_v2.xpm"
# define L_PLAYER "./media/player/left_v2.xpm"
# define R_PLAYER "./media/player/right_v2.xpm"

# define E_CLOSE 131072
# define SPRITE 42

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

typedef struct s_img
{
	void		*img;
	int			bpp;//
	int			bpl;//
	int			endian;//
	char		*data;//
	int			width;
	int			height;
}	t_img;

typedef struct s_terrain {
	t_img		*img[2];
	char		type;
	int			x;
	int			y;
	t_bool		status;
}	t_terrain;

typedef struct s_player {
	t_img		*up;
	t_img		*dw;
	t_img		*lf;
	t_img		*rg;
	int			x;
	int			y;
}	t_player;

/*
**  win := windows
*/

typedef struct s_graphics {
	void		*mlx;
	void		*win;
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
	int			collected;
	int			movements;
	int			map_height;
	int			map_width;

	t_terrain	**map;
	t_player	p;
	t_terrain	e;

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
void	exit_error_gnl(char *e, char *line);

/*
**  Load
*/

void	load_map(void);
void    load_player(void);
void	set_space(t_terrain *tmp, char c);

/*
**	Graphics
*/

void	init_graphics(void);
void	ft_plot_map(void);
void	draw_element(int i, int j);
void	draw_img(int x, int y, t_img *img);
void	draw_player(char c);

/*
**  Game
*/

void    game(void);
int		exit_win(__attribute__((unused)) void *p);
int		key_win(int key, __attribute__((unused)) void *p);
int		key_esc(int key, __attribute__((unused)) void *p);
void	player_interact(char c);
void	up(void);
void	left(void);
void	down(void);
void	right(void);

#endif
