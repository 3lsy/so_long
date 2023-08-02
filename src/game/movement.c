/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:40:15 by echavez-          #+#    #+#             */
/*   Updated: 2023/08/02 20:57:52 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	interact(char c)
{
	t_sl	*s;
	char	*nb;

	s = ft_sl();
	s->movements++;
	nb = ft_itoa(s->movements);
	if (!nb)
		exit_error(strerror(errno));
	draw_element(s->map_height - 1, 2);
	mlx_string_put(s->g.mlx, s->g.win, SPRITE * 2 + 10,
				   s->map_height * SPRITE - 15, 0xFFFFFF, nb);
	free(nb);
	if (s->map[s->p.y][s->p.x].type == 'C')
	{
		s->collected++;
		s->map[s->p.y][s->p.x].status = 0;
		printf("Collected a collectible\n");//
	}
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
			mlx_set_font(s->g.mlx, s->g.win, "rk24");
			mlx_string_put(s->g.mlx, s->g.win, SPRITE,
						   35, 0xFFFFFF, "YOU WON !");
			mlx_key_hook(s->g.win, key_esc, s->g.mlx);
			mlx_hook(s->g.win, 33, E_CLOSE, exit_win, 0);
		}
	}
}

void	up(void)
{
	t_sl  *s;

	s = ft_sl();
	if (s->p.y - 1 >= 0 && s->map[s->p.y - 1][s->p.x].type != '1')
	{
		draw_element(s->p.y, s->p.x);
		if (s->map[s->p.y][s->p.x].type != 'E')
			s->map[s->p.y][s->p.x].type = '0';
		s->p.y--;
		interact('u');
	}
}

void	down(void)
{
	t_sl  *s;

	s = ft_sl();
	if (s->p.y + 1 < s->map_height && s->map[s->p.y + 1][s->p.x].type != '1')
	{
		draw_element(s->p.y, s->p.x);
		if (s->map[s->p.y][s->p.x].type != 'E')
			s->map[s->p.y][s->p.x].type = '0';
		s->p.y++;
		interact('d');
	}
}

void	left(void)
{
	t_sl  *s;

	s = ft_sl();
	if (s->p.x - 1 >= 0 && s->map[s->p.y][s->p.x - 1].type != '1')
	{
		draw_element(s->p.y, s->p.x);
		if (s->map[s->p.y][s->p.x].type != 'E')
			s->map[s->p.y][s->p.x].type = '0';
		s->p.x--;
		interact('l');
	}
}

void	right(void)
{
	t_sl  *s;

	s = ft_sl();
	if (s->p.x + 1 < s->map_width && s->map[s->p.y][s->p.x + 1].type != '1')
	{
		draw_element(s->p.y, s->p.x);
		if (s->map[s->p.y][s->p.x].type != 'E')
			s->map[s->p.y][s->p.x].type = '0';
		s->p.x++;
		interact('r');
	}
}
