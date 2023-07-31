/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:10:17 by echavez-          #+#    #+#             */
/*   Updated: 2023/07/11 18:24:59 by echavez-         ###   ########.fr       */
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
		exit_error("minilbx init failed\n");
	s->g.win = mlx_new_window(s->g.mlx, s->map_width * SPRITE,
			s->map_height * SPRITE, "so_long");
	if (!s->g.win)
		exit_error("minilibx window failed\n");
}
