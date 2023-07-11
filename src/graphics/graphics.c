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
		printf("izquierda\n");
	else if (key == 65363)
		printf("derecha\n");
	else if (key == 65362)
		printf("arriba\n");
	else if (key == 65364)
		printf("abajo\n");
	else
		printf("%d\n", key);
	return (0);
}

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
	mlx_hook(s->g.win, 33, E_CLOSE, exit_win, 0);
	mlx_key_hook(s->g.win, key_win, s->g.mlx);
}
