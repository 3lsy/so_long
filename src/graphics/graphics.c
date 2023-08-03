/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:41:28 by echavez-          #+#    #+#             */
/*   Updated: 2023/08/02 23:28:05 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_graphics(void)
{
	t_sl	*s;
	int		a;

	s = ft_sl();
	a = 0x11223344;
	if (((unsigned char *)&a)[0] == 0x11)
		s->g.local_endian = 1;
	else
		s->g.local_endian = 0;
	s->g.mlx = mlx_init();
	if (!s->g.mlx)
		exit_error("minilbx init failed");
}

void	draw_player(char c)
{
	t_sl	*s;
	t_img	*img;

	img = NULL;
	s = ft_sl();
	if (c == 'u')
		img = s->p.up;
	else if (c == 'd')
		img = s->p.dw;
	else if (c == 'l')
		img = s->p.lf;
	else if (c == 'r')
		img = s->p.rg;
	draw_img(s->p.x * SPRITE, s->p.y * SPRITE, img);
}

void	draw_img(int x, int y, t_img *img)
{
	t_sl	*s;

	s = ft_sl();
	mlx_put_image_to_window(s->g.mlx, s->g.win, img, x, y);
}

void	draw_element(int i, int j)
{
	t_sl	*s;

	s = ft_sl();
	mlx_put_image_to_window(s->g.mlx, s->g.win,
		s->map[i][j].img[s->map[i][j].status], j * SPRITE, i * SPRITE);
}

void	ft_plot_map(void)
{
	t_sl	*s;
	int		i;
	int		j;

	s = ft_sl();
	i = 0;
	while (s->map && i < s->map_height)
	{
		j = 0;
		while (j < s->map_width)
		{
			draw_element(i, j);
			j++;
		}
		i++;
	}
}
