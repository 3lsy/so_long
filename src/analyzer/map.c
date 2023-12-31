/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 00:08:56 by echavez-          #+#    #+#             */
/*   Updated: 2023/08/02 23:24:44 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verify_wall(char *line, int size, int fd, int row)
{
	int	err;

	err = 0;
	if (row)
	{
		while (line && size > 0)
		{
			size--;
			if (line[size] != '1')
				err = 1;
		}
	}
	else if (line[0] != '1' || line[size - 1] != '1')
		err = 1;
	if (err)
	{
		close(fd);
		exit_error_gnl("Missing wall on map border!", line);
	}
}

static void	verify_dimensions(char *line, int size, int fd)
{
	if (line && size != (int)ft_strlen(line))
	{
		close(fd);
		exit_error_gnl("Inconsistent map dimensions!", line);
	}
}

/*
** Accepted elements:
**	set player P
**	set exit   E
*/

static void	set_element(char *line, int x, int y, int fd)
{
	int	*slx;
	int	*sly;

	if (line[x] != 'E' && line[x] != 'P')
		exit_error_gnl("Set element error!", line);
	slx = &(ft_sl()->p.x);
	sly = &(ft_sl()->p.y);
	if (line[x] == 'E')
	{
		slx = &(ft_sl()->e.x);
		sly = &(ft_sl()->e.y);
	}
	if (*slx != -1)
	{
		close(fd);
		if (line[x] == 'P')
			exit_error_gnl("There's more than one P!", line);
		exit_error_gnl("There's more than one E!", line);
	}
	*slx = x;
	*sly = y;
}

void	verify_item(char *line, int x, int y, int fd)
{
	if (line[x] == 'C')
		ft_sl()->collects++;
	else if (line[x] == 'P' || line[x] == 'E')
		set_element(line, x, y, fd);
	else if (line[x] != '0' && line[x] != '1')
	{
		close(fd);
		exit_error_gnl("Unrecognized character in map!", line);
	}
}

void	verify_line(char *line, int fd)
{
	int	i;

	i = 0;
	if (ft_sl()->map_width == 0)
		ft_sl()->map_width = ft_strlen(line);
	verify_dimensions(line, ft_sl()->map_width, fd);
	while (i < ft_sl()->map_width)
	{
		verify_item(line, i, ft_sl()->map_height - 1, fd);
		i++;
	}
}
