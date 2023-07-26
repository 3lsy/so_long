/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 23:43:26 by echavez-          #+#    #+#             */
/*   Updated: 2023/07/26 18:51:18 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_space(t_terrain *tmp, char c)
{
	int		size;
	t_sl	*s;

	s = ft_sl();
	tmp->status = (c == 'C');
	tmp->type = c;
	if (c == 'P' || c == '0')
	{
		tmp->type = '0';
		tmp->img = mlx_xpm_file_to_image(s->g.mlx, FREE, &size, &size);
	}
	else if (c == '1')
		tmp->img = mlx_xpm_file_to_image(s->g.mlx, WALL, &size, &size);
	else if (c == 'C')
		tmp->img = mlx_xpm_file_to_image(s->g.mlx, COLLECT, &size, &size);
	else
		tmp->img = mlx_xpm_file_to_image(s->g.mlx, EXIT, &size, &size);
	if (!tmp->img)
		exit_error("minilibx img failed\n");
	tmp->img->width = SPRITE;
	tmp->img->height = SPRITE;
}

void	set_player(int j, int i)
{
	int		size;
	t_sl	*s;

	s = ft_sl();
	s->p.dw = mlx_xpm_file_to_image(s->g.mlx, D_PLAYER, &size, &size);
	s->p.x = j;
	s->p.y = i;
	s->p.dw->width = SPRITE;
	s->p.dw->height = SPRITE;
}

void	load_line(char *line, int i)
{
	int			j;
	t_terrain	tmp;

	j = 0;
	while (line && j < ft_sl()->map_width)
	{
		tmp.x = j;
		tmp.y = i;
		set_space(&tmp, line[j]);
		if (line[j] == 'P')
			set_player(j, i);
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
