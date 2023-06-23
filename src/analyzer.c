/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:17:31 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/24 00:26:50 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			ft_putendl("Error: Not a valid filename");
			return (0);
		}
	}
	if (i != 0)
	{
		ft_putendl("Error: Not a valid filename");
		return (0);
	}
	ft_sl()->filename = filename;
	return (1);
}

void	verify_wall(char *line, int size, int fd)
{
	while (line && size > 0)
	{
		size--;
		if (line[size] != '1')
		{
			free(line);
			close(fd);
			exit_error("Missing wall on map border\n");
		}
	}
}

// count if AT LEAST 1 C collectible
void	verify_map(void)
{
	char	*line;
	int		fd;
	int		size;
	//int		exit;// count if ONLY 1 E
	//int		playerpos;// count if ONLY 1 P

	fd = open(ft_sl()->filename, O_RDONLY);
	if (fd < 0)
		exit_error(strerror(errno));
	line = ft_get_next_line(fd);
	size = ft_strlen(line);
	verify_wall(line, size, fd);
	while (line)
	{
		ft_putendl(line);/////////
		if (line[0] != '1' || line[size - 1] != '1')
		{
			close(fd);
			free(line);
			exit_error("Missing wall on map border\n");
		}
		free(line);
		line = ft_get_next_line(fd);
		if (line && size != (int)ft_strlen(line))
		{
			ft_putendl(line);
			close(fd);
			free(line);
			exit_error("Inconsistent map dimensions\n");
		}
	}
	verify_wall(line, size, fd);
	if (line)
		free(line);
	close(fd);
}

/*
void	read_map(void)
{
	char	*line;
	int		fd;

	fd = open(ft_sl()->filename, O_RDONLY);
	if (fd < 0)
		exit_error(strerror(errno));
	line = ft_get_next_line(fd);
	while (line)
	{
		ft_putendl(line);
		free(line);
		line = ft_get_next_line(fd);
	}
	if (line)
		free(line);
}
*/
