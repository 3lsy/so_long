/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:20:33 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/27 23:16:28 by echavez-         ###   ########.fr       */
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

int main(int ac, char **av)
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
	static t_sl	x;

	return (&x);
}

static __attribute__((constructor)) void	sl_constructor(void)
{
	ft_sl()->filename = NULL;
	ft_sl()->fd = 0;
	ft_sl()->map = NULL;
	ft_sl()->map_height = 0;
	ft_sl()->map_width = 0;
	ft_sl()->collects = 0;
	ft_sl()->p.x = -1;
	ft_sl()->p.y = -1;
	ft_sl()->e.type = 'E';
	ft_sl()->e.status = 0;
	ft_sl()->e.x = -1;
	ft_sl()->e.y = -1;
	ft_sl()->c = NULL;
}

static __attribute__((destructor)) void	sl_destructor(void)
{
	if (ft_sl()->map != NULL)
		ft_free_split(&ft_sl()->map);
}
