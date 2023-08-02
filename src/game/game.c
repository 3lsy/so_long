/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:40:15 by echavez-          #+#    #+#             */
/*   Updated: 2023/08/02 20:57:52 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_win(__attribute__((unused)) void *p)
{
	exit(EXIT_SUCCESS);
	return (1);
}

int	key_win(int key, __attribute__((unused)) void *p)
{
	if (key == 0xFF1B)
		exit_win(NULL);
	else if (key == 65361)
		left();
	else if (key == 65363)
		right();
	else if (key == 65362)
		up();
	else if (key == 65364)
		down();
	else
		printf("%d\n", key);
	return (0);
}

int	key_esc(int key, __attribute__((unused)) void *p)
{
	if (key == 0xFF1B)
		exit_win(NULL);
	return (0);
}

void	game(void)
{
	t_sl	*s;

	s = ft_sl();
	ft_plot_map();
	mlx_hook(s->g.win, 33, E_CLOSE, exit_win, 0);
	mlx_key_hook(s->g.win, key_win, s->g.mlx);
	mlx_set_font(s->g.mlx, s->g.win, "10x20");
	mlx_string_put(s->g.mlx, s->g.win, 21,
		s->map_height * SPRITE - 15, 0xFFFFFF, "Moves:");
	mlx_string_put(s->g.mlx, s->g.win, SPRITE * 2 + 10,
		s->map_height * SPRITE - 15, 0xFFFFFF, "0");
	draw_player('d');
	mlx_loop(ft_sl()->g.mlx);
}
