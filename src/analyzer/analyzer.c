/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:17:31 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/27 00:24:47 by echavez-         ###   ########.fr       */
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
