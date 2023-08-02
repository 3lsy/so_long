/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 23:43:26 by echavez-          #+#    #+#             */
/*   Updated: 2023/08/02 22:00:25 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    load_player(void)
{
	int   size;
	t_sl  *s;

	s = ft_sl();
	s->p.up = mlx_xpm_file_to_image(s->g.mlx, U_PLAYER, &size, &size);
	if (!s->p.up)
		exit_error("minilibx img failed\n");
	s->p.dw = mlx_xpm_file_to_image(s->g.mlx, D_PLAYER, &size, &size);
	if (!s->p.dw)
		exit_error("minilibx img failed\n");
	s->p.lf = mlx_xpm_file_to_image(s->g.mlx, L_PLAYER, &size, &size);
	if (!s->p.lf)
		exit_error("minilibx img failed\n");
	s->p.rg = mlx_xpm_file_to_image(s->g.mlx, R_PLAYER, &size, &size);
	if (!s->p.rg)
		exit_error("minilibx img failed\n");
	s->p.up->width = SPRITE;
	s->p.up->height = SPRITE;
	s->p.dw->width = SPRITE;
	s->p.dw->height = SPRITE;
	s->p.lf->width = SPRITE;
	s->p.lf->height = SPRITE;
	s->p.rg->width = SPRITE;
	s->p.rg->height = SPRITE;
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
          {
            free(line);
			exit_error_gnl("Map couldn't be allocated");
          }
		load_line(line, i++);
		free(line);
		line = ft_get_next_line(fd);
	}
	ft_sl()->map[i] = NULL;
	if (line)
		free(line);
}
