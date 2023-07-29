/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:41:28 by echavez-          #+#    #+#             */
/*   Updated: 2023/07/26 18:48:06 by echavez-         ###   ########.fr       */
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
          usleep(3000);//
          mlx_put_image_to_window(s->g.mlx, s->g.win, s->map[i][j].img[s->map[i][j].status],
                                  j * SPRITE, i * SPRITE);
          j++;
		}
		i++;
	}
	
}
