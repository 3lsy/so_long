/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:40:15 by echavez-          #+#    #+#             */
/*   Updated: 2023/07/31 22:21:14 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
void	destroy_player(void)
{
	t_sl	*s;

	s = ft_sl();
	if (s->p.img)
		mlx_destroy_image(s->g.mlx, s->p.img);
	s->p.img = NULL;
}
*/

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

void	interact(void)
{
	t_sl  *s;

	s = ft_sl();
	s->movements++;
	printf("Movements: {%d}\n", s->movements);
	printf("Arrived at {%c}\n", s->map[s->p.y][s->p.x].type);
	if (s->collected == s->collects && s->map[s->p.y][s->p.x].type == 'E')
	{
		printf("SUCCESS ! YOU WON\n");//
	}
	else if (s->map[s->p.y][s->p.x].type == 'C')
	{
		s->collected++;
		s->map[s->p.y][s->p.x].status = 0;
		printf("Collected a collectible\n");
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
		interact();
		if (s->map[s->p.y][s->p.x].type != 'E')
			s->map[s->p.y][s->p.x].type = 'P';
		draw_player('u');
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
		interact();
		if (s->map[s->p.y][s->p.x].type != 'E')
			s->map[s->p.y][s->p.x].type = 'P';
		draw_player('d');
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
		interact();
		if (s->map[s->p.y][s->p.x].type != 'E')
			s->map[s->p.y][s->p.x].type = 'P';
		draw_player('l');
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
		interact();
		if (s->map[s->p.y][s->p.x].type != 'E')
			s->map[s->p.y][s->p.x].type = 'P';
		draw_player('r');
	}
}
