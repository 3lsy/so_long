/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:59:55 by echavez-          #+#    #+#             */
/*   Updated: 2023/08/02 23:32:10 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_wall(t_terrain *tmp, int size, t_sl *s)
{
	char	*i;

	if (tmp->x == 0 && tmp->y == 0)
		i = TOP_L_CORNER;
	else if (tmp->x == s->map_width - 1 && tmp->y == 0)
		i = TOP_R_CORNER;
	else if (tmp->x == 0 && tmp->y != s->map_height - 1)
		i = L_WALL;
	else if (tmp->x == s->map_width - 1 && tmp->y != s->map_height - 1)
		i = R_WALL;
	else if (tmp->y == 0 || tmp->y == s->map_height - 1)
		i = WALL;
	else
		i = TOWER;
	tmp->img[0] = mlx_xpm_file_to_image(s->g.mlx, i, &size, &size);
}

void	set_pair(t_terrain *tmp, int size, char *img1, char *img2)
{
	t_sl	*s;

	s = ft_sl();
	tmp->img[0] = mlx_xpm_file_to_image(s->g.mlx, img1, &size, &size);
	tmp->img[1] = mlx_xpm_file_to_image(s->g.mlx, img2, &size, &size);
	if (!tmp->img[1])
		exit_error("minilibx img failed\n");
	tmp->img[1]->width = SPRITE;
	tmp->img[1]->height = SPRITE;
}

void	set_space(t_terrain *tmp, char c)
{
	int		size;
	t_sl	*s;

	s = ft_sl();
	size = 0;
	tmp->status = (c == 'C');
	tmp->type = c;
	tmp->img[1] = NULL;
	if (c == 'P' || c == '0')
	{
		tmp->type = '0';
		tmp->img[0] = mlx_xpm_file_to_image(s->g.mlx, FREE, &size, &size);
	}
	else if (c == '1')
		set_wall(tmp, size, s);
	else if (c == 'C')
		set_pair(tmp, size, FREE, COLLECT);
	else
		set_pair(tmp, size, EXIT_CLOSE, EXIT);
	if (!tmp->img[0])
		exit_error("minilibx img failed\n");
	tmp->img[0]->width = SPRITE;
	tmp->img[0]->height = SPRITE;
}
