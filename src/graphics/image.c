/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:41:28 by echavez-          #+#    #+#             */
/*   Updated: 2023/07/11 18:16:12 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			mlx_put_image_to_window(s->g.mlx, s->g.win, s->map[i][j].img,
									j * SPRITE, i * SPRITE);
			j++;
		}
		i++;
	}
	mlx_loop(ft_sl()->g.mlx);
}
