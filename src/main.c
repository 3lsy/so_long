/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:20:33 by echavez-          #+#    #+#             */
/*   Updated: 2023/07/26 18:13:41 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	usage(void)
{
	ft_putendl("Usage: ./so_long <map.ber>");
	ft_putendl("  map.ber: A map which contains:");
	ft_putendl("    0 : [valid path]  Empty space");
	ft_putendl("    1 : [100% closed] Wall");
	ft_putendl("    C : [1 minimum]   Collectible");
	ft_putendl("    E : [unique]      Exit");
	ft_putendl("    P : [unique]      Player (starting pos)");
	exit(1);
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 2 && valid_name(av[1]))
	{
		verify_map();
		init_graphics();
		load_map();
        load_player();
		game();
	}
	else
		usage();
	return (0);
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
		.map_height = 0,
		.map_width = 0,
		.map = NULL,
		.p = {
			.up = NULL, .dw = NULL,
			.lf = NULL, .rg = NULL,
			.x = -1, .y = -1
			},
		.e = {.img = {NULL, NULL}, .type = 'E', .status = 0, .x = -1, .y = -1},
		.g = {.mlx = NULL, .win = NULL, .local_endian = -1},
	};

	return (&x);
}

static __attribute__((destructor)) void	sl_destructor(void)
{
	t_sl	*s;
	int	i;
	int	j;

	s = ft_sl();
	if (s->map != NULL)
	{
		i = 0;
		while (i < s->map_height)
		{
			j = 0;
			while (j < s->map_width)
			{
				if (s->map[i][j].img[0])
					mlx_destroy_image(s->g.mlx, s->map[i][j].img[0]);
                if (s->map[i][j].img[1])
					mlx_destroy_image(s->g.mlx, s->map[i][j].img[1]);
				j++;
			}
			free(s->map[i]);
			i++;
		}
		free(s->map);
		s->map = NULL;
	}
	if (s->g.win)
	{
		mlx_clear_window(s->g.mlx, s->g.win);
		mlx_destroy_window(s->g.mlx, s->g.win);
	}
	if (s->g.mlx)
	{
		mlx_destroy_display(s->g.mlx);
		free(s->g.mlx);
	}
}
