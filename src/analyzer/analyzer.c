/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:17:31 by echavez-          #+#    #+#             */
/*   Updated: 2023/08/04 12:46:27 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
**	After loading the map
*/

void	valid_path(int x, int y)
{
	t_sl	*s;

	s = ft_sl();
	if (0 <= x && x < s->map_width && 0 <= y && y < s->map_height)
	{
		if (s->map[y][x].type != '1' && !s->map[y][x].visited)
		{
			s->map[y][x].visited = 1;
			if (s->map[y][x].type == 'C' || s->map[y][x].type == 'E')
				s->found++;
			valid_path(x - 1, y);
			valid_path(x + 1, y);
			valid_path(x, y - 1);
			valid_path(x, y + 1);
		}
	}
}

int	valid_name(char *filename)
{
	const char	ext[4] = ".ber";
	int			size;
	int			i;

	i = 4;
	size = ft_strlen(filename);
	while (size > 0 && i > 0)
	{
		if (filename[--size] != ext[--i])
		{
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("Not a valid filename!", 2);
			return (0);
		}
	}
	if (i != 0)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Not a valid filename!", 2);
		return (0);
	}
	ft_sl()->filename = filename;
	return (1);
}

void	read_map(char *line, int fd)
{
	line = ft_get_next_line(fd);
	while (line)
	{
		ft_sl()->map_height++;
		verify_wall(line, ft_strlen(line), fd, ft_sl()->map_width == 0);
		verify_line(line, fd);
		free(line);
		line = ft_get_next_line(fd);
	}
	if (line)
	{
		verify_wall(line, ft_sl()->map_width, fd, 1);
		free(line);
	}
	close(fd);
}

void	verify_map(void)
{
	int		fd;

	fd = open(ft_sl()->filename, O_RDONLY);
	if (fd < 0)
		exit_error(strerror(errno));
	read_map(NULL, fd);
	if (!ft_sl()->map_height)
		exit_error("Empty map!");
	if (ft_sl()->p.x == -1)
		exit_error("There's no player!");
	if (ft_sl()->e.x == -1)
		exit_error("There's no exit!");
	if (!ft_sl()->collects)
		exit_error("There's no collectible");
}

void	exit_error_gnl(char *e, char *line)
{
	free(line);
	ft_get_next_line(-503);
	exit_error(e);
}
