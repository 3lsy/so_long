/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:40:15 by echavez-          #+#    #+#             */
/*   Updated: 2023/08/02 20:57:52 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_collect(void)
{
	t_sl	*s;
	char	*nb;

	s = ft_sl();
	s->movements++;
	nb = ft_itoa(s->movements);
	if (!nb)
		exit_error(strerror(errno));
	ft_putstr_fd("Moves: ", 1);
	ft_putendl(nb);
	draw_element(s->map_height - 1, 2);
	mlx_string_put(s->g.mlx, s->g.win, SPRITE * 2 + 10,
		s->map_height * SPRITE - 15, 0xFFFFFF, nb);
	free(nb);
	if (s->map[s->p.y][s->p.x].type == 'C')
	{
		s->collected++;
		s->map[s->p.y][s->p.x].status = 0;
		ft_putendl_fd("Collected a coin! 💰", 1);
	}
}

void	player_interact(char c)
{
	t_sl	*s;

	s = ft_sl();
	player_collect();
	if (s->map[s->p.y][s->p.x].type != 'E')
		s->map[s->p.y][s->p.x].type = 'P';
	draw_player(c);
	if (s->collected == s->collects)
	{
		s->map[s->e.y][s->e.x].status = 1;
		draw_element(s->e.y, s->e.x);
		draw_player(c);
		if (s->map[s->p.y][s->p.x].type == 'E')
		{
			ft_putendl("You won ! 👑");
			mlx_set_font(s->g.mlx, s->g.win, "rk24");
			mlx_string_put(s->g.mlx, s->g.win, SPRITE,
				35, 0xFFFFFF, "YOU WON !");
			mlx_key_hook(s->g.win, key_esc, s->g.mlx);
			mlx_hook(s->g.win, 33, E_CLOSE, exit_win, 0);
		}
	}
}
