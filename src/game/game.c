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

int	max_win(__attribute__((unused)) void *p)
{
	t_sl	*s;
	char	*nb;

	s = ft_sl();
	ft_plot_map();
	nb = ft_itoa(s->movements);
	if (!nb)
		exit_error(strerror(errno));
	draw_element(s->map_height - 1, 2);
	mlx_string_put(s->g.mlx, s->g.win, SPRITE * 2 + 10,
		s->map_height * SPRITE - 15, 0xFFFFFF, nb);
	free(nb);
	mlx_string_put(s->g.mlx, s->g.win, 21,
		s->map_height * SPRITE - 15, 0xFFFFFF, "Moves:");
	draw_player('d');
	return (1);
}

int	exit_win(__attribute__((unused)) void *p)
{
	exit(EXIT_SUCCESS);
	return (1);
}

int	key_win(int key, __attribute__((unused)) void *p)
{
	if (key == 0xFF1B)
		exit_win(NULL);
	else if (key == L_ARROW || key == A)
		left();
	else if (key == R_ARROW || key == D)
		right();
	else if (key == U_ARROW || key == W)
		up();
	else if (key == D_ARROW || key == S)
		down();
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
	s->g.win = mlx_new_window(s->g.mlx, s->map_width * SPRITE,
			s->map_height * SPRITE, "so_long");
	if (!s->g.win)
		exit_error("minilibx window failed");
	ft_plot_map();
	mlx_hook(s->g.win, 33, E_CLOSE, exit_win, 0);
	mlx_hook(s->g.win, 19, E_MAXIM, max_win, 0);
	mlx_key_hook(s->g.win, key_win, s->g.mlx);
	mlx_set_font(s->g.mlx, s->g.win, "10x20");
	mlx_string_put(s->g.mlx, s->g.win, 21,
		s->map_height * SPRITE - 15, 0xFFFFFF, "Moves:");
	mlx_string_put(s->g.mlx, s->g.win, SPRITE * 2 + 10,
		s->map_height * SPRITE - 15, 0xFFFFFF, "0");
	draw_player('d');
	mlx_loop(ft_sl()->g.mlx);
}
