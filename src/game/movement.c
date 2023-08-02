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

void	up(void)
{
	t_sl	*s;

	s = ft_sl();
	if (s->p.y - 1 >= 0 && s->map[s->p.y - 1][s->p.x].type != '1')
	{
		draw_element(s->p.y, s->p.x);
		if (s->map[s->p.y][s->p.x].type != 'E')
			s->map[s->p.y][s->p.x].type = '0';
		s->p.y--;
		player_interact('u');
	}
}

void	down(void)
{
	t_sl	*s;

	s = ft_sl();
	if (s->p.y + 1 < s->map_height && s->map[s->p.y + 1][s->p.x].type != '1')
	{
		draw_element(s->p.y, s->p.x);
		if (s->map[s->p.y][s->p.x].type != 'E')
			s->map[s->p.y][s->p.x].type = '0';
		s->p.y++;
		player_interact('d');
	}
}

void	left(void)
{
	t_sl	*s;

	s = ft_sl();
	if (s->p.x - 1 >= 0 && s->map[s->p.y][s->p.x - 1].type != '1')
	{
		draw_element(s->p.y, s->p.x);
		if (s->map[s->p.y][s->p.x].type != 'E')
			s->map[s->p.y][s->p.x].type = '0';
		s->p.x--;
		player_interact('l');
	}
}

void	right(void)
{
	t_sl	*s;

	s = ft_sl();
	if (s->p.x + 1 < s->map_width && s->map[s->p.y][s->p.x + 1].type != '1')
	{
		draw_element(s->p.y, s->p.x);
		if (s->map[s->p.y][s->p.x].type != 'E')
			s->map[s->p.y][s->p.x].type = '0';
		s->p.x++;
		player_interact('r');
	}
}
