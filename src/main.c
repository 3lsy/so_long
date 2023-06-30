/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:20:33 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/29 22:39:54 by echavez-         ###   ########.fr       */
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
		verify_map();
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
		.p = {.x = -1, .y = -1},
		.e = {.type = 'E', .status = 0, .x = -1, .y = -1},
		.c = NULL
	};

	return (&x);
}

static __attribute__((destructor)) void	sl_destructor(void)
{
	if (ft_sl()->map != NULL)
	{
		while (ft_sl()->map_height > 0)
			free(ft_sl()->map[--ft_sl()->map_height]);
		free(ft_sl()->map);
		ft_sl()->map = NULL;
	}
}
