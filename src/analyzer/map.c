/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 00:08:56 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/27 23:17:41 by echavez-         ###   ########.fr       */
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
		free(line);
		ft_get_next_line(-503);
		close(fd);
		exit_error("Missing wall on map border\n");
	}
}

void	verify_dimensions(char *line, int size, int fd)
{
	if (line && size != (int)ft_strlen(line))
	{
		ft_putendl(line);
		close(fd);
		free(line);
		exit_error("Inconsistent map dimensions\n");
	}
}

void	set_player(char *line, int x, int y, int fd)
{
	if (ft_sl()->p.x != -1)
	{
		ft_putendl(line);
		close(fd);
		free(line);
		exit_error("There's more than one P\n");
	}
	ft_sl()->p.x = x;
	ft_sl()->p.y = y;
}

void	set_exit(char *line, int x, int y, int fd)
{
	if (ft_sl()->e.x != -1)
	{
		ft_putendl(line);
		close(fd);
		free(line);
		exit_error("There's more than one E\n");
	}
	ft_sl()->e.x = x;
	ft_sl()->e.y = y;
}

void	verify_item(char *line, int x, int y, int fd)
{
	if (line[x] == 'C')
		ft_sl()->collects++;
	else if (line[x] == 'P')
		set_player(line, x, y, fd);
	else if (line[x] == 'E')
		set_exit(line, x, y, fd);
	else if (line[x] != '0' && line[x] != '1')
	{
		ft_putendl(line);
		close(fd);
		free(line);
		exit_error("Unrecognized character in map\n");
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
		verify_item(line, i, ft_sl()->map_height, fd);
		i++;
	}
}

void	verify_map(void)
{
	char	*line;
	int		fd;

	fd = open(ft_sl()->filename, O_RDONLY);
	if (fd < 0)
		exit_error(strerror(errno));
	line = ft_get_next_line(fd);
	while (line)
	{
		ft_sl()->map_height++;
		verify_wall(line, ft_strlen(line), fd, ft_sl()->map_width == 0);
		verify_line(line, fd);
		ft_putendl(line);/////////
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
