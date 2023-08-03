/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:20:33 by echavez-          #+#    #+#             */
/*   Updated: 2023/08/02 23:06:38 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 2 && valid_name(av[1]))
	{
		verify_map();
		init_graphics();
		load_map();
		valid_path(ft_sl()->p.x, ft_sl()->p.y);
		if (ft_sl()->found != ft_sl()->collects + 1)
			exit_error("Invalid path!\n");
		load_player();
		game();
		return (0);
	}
	ft_putendl("Usage: ./so_long <map.ber>");
	ft_putendl("  map.ber: A map which contains:");
	ft_putendl("    0 : [valid path]  Empty space");
	ft_putendl("    1 : [100% closed] Wall");
	ft_putendl("    C : [1 minimum]   Collectible");
	ft_putendl("    E : [unique]      Exit");
	ft_putendl("    P : [unique]      Player (starting pos)");
	return (1);
}

void	exit_error(char *e)
{
	ft_perror("Error\n", EXIT_FAILURE);
	exit(ft_perror(e, EXIT_FAILURE));
}

t_sl	*ft_sl(void)
{
	static t_sl	x = {
		.filename = NULL,
		.fd = 0,
		.collects = 0,
		.collected = 0,
		.found = 0,
		.movements = 0,
		.map_height = 0,
		.map_width = 0,
		.map = NULL,
		.p = {
		.up = NULL, .dw = NULL,
		.lf = NULL, .rg = NULL,
		.x = -1, .y = -1
	},
		.e = {
		.img = {NULL, NULL},
		.type = 'E', .status = 0,
		.visited = 0, .x = -1, .y = -1
	},
		.g = {.mlx = NULL, .win = NULL, .local_endian = -1},
	};

	return (&x);
}

static __attribute__((destructor)) void	sl_destruct0r(void)
{
	t_sl	*s;
	int		i;
	int		j;

	s = ft_sl();
	i = 0;
	while (s->map != NULL && i < s->map_height)
	{
		j = 0;
		while (j < s->map_width)
		{
			free(s->map[i][j].img[0]->image);
			free(s->map[i][j].img[0]);
			if (s->map[i][j].img[1])
			{
				free(s->map[i][j].img[1]->image);
				free(s->map[i][j].img[1]);
			}
			j++;
		}
		free(s->map[i++]);
	}
	if (s->map)
		free(s->map);
	s->map = NULL;
}

static __attribute__((destructor)) void	sl_d3structor(void)
{
	t_sl	*s;

	s = ft_sl();
	if (s->g.win)
	{
		mlx_clear_window(s->g.mlx, s->g.win);
		mlx_destroy_window(s->g.mlx, s->g.win);
	}
	if (s->g.mlx)
	{
		if (s->p.up)
			mlx_destroy_image(s->g.mlx, s->p.up);
		if (s->p.dw)
			mlx_destroy_image(s->g.mlx, s->p.dw);
		if (s->p.lf)
			mlx_destroy_image(s->g.mlx, s->p.lf);
		if (s->p.rg)
			mlx_destroy_image(s->g.mlx, s->p.rg);
		mlx_destroy_display(s->g.mlx);
		free(s->g.mlx);
	}
}
