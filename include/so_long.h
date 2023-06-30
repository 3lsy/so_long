/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:49:58 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/29 23:04:23 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SO_LONG_H
# define	SO_LONG_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <errno.h>
# include <string.h>

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

typedef	struct	s_terrain {
	char		type;
	int			x;
	int			y;
	t_bool		status;
}	t_terrain;

typedef struct s_player {
	int			x;
	int			y;
}	t_player;

/*
**	collects := Collectibles counter
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

#endif
