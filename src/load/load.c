/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 23:43:26 by echavez-          #+#    #+#             */
/*   Updated: 2023/07/01 00:28:36 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_line(char *line, int i)
{
	int	j;

	j = 0;
	while (line && j < ft_sl()->map_width)
	{
		if (line[j] == '0' || line[j] == 'P')
			ft_sl()->map[i][j] = (t_terrain){.type = '0', .status = 0,
				.x = j, .y = i};
		else if (line[j] == '1')
			ft_sl()->map[i][j] = (t_terrain){.type = '1', .status = 0,
				.x = j, .y = i};
		else if (line[j] == 'C')
			ft_sl()->map[i][j] = (t_terrain){.type = 'C', .status = 1,
				.x = j, .y = i};
		else
			ft_sl()->map[i][j] = (t_terrain){.type = 'E', .status = 0,
				.x = j, .y = i};
		j++;
	}
	ft_sl()->map[i][j] = (t_terrain){'\0', 0, 0, 0};
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
		ft_putendl(line);/////////
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
