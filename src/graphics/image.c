/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:41:28 by echavez-          #+#    #+#             */
/*   Updated: 2023/08/02 20:58:28 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
