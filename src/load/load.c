/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 23:43:26 by echavez-          #+#    #+#             */
/*   Updated: 2023/07/01 00:38:46 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_line(char *line, int i)
{
	int			j;
	t_terrain	tmp;

	j = 0;
	while (line && j < ft_sl()->map_width)
	{
		tmp.x = j;
		tmp.y = i;
		tmp.status = 0;
		if (line[j] == '0' || line[j] == 'P')
			tmp.type = '0';
		else if (line[j] == '1')
			tmp.type = '1';
		else if (line[j] == 'C')
		{
			tmp.type = 'C';
			tmp.status = 1;
		}
		else
			tmp.type = 'E';
		ft_sl()->map[i][j] = tmp;
		j++;
	}
	tmp.type = '\0';
	ft_sl()->map[i][j] = tmp;
}

void	load_map(void)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(ft_sl()->filename, O_RDONLY);
	if (fd < 0)
		exit_error(strerror(errno));
	ft_sl()->map = malloc(sizeof(t_terrain *) * (ft_sl()->map_height + 1));
	if (!ft_sl()->map)
		exit_error("Map couldn't be allocated");
	line = ft_get_next_line(fd);
	i = 0;
	while (line)
	{
		ft_putendl(line);
		ft_sl()->map[i] = malloc(sizeof(t_terrain) * (ft_sl()->map_width + 1));
		if (!ft_sl()->map[i])
			exit_error("Map couldn't be allocated");
		load_line(line, i++);
		free(line);
		line = ft_get_next_line(fd);
	}
	ft_sl()->map[i] = NULL;
	if (line)
		free(line);
}
