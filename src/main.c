/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:20:33 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/23 15:36:59 by echavez-         ###   ########.fr       */
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
	if (ac == 2 && valid_name(av[1]))
		printf("%s\n", av[1]);//////
	else
		usage();
	return (0);
}

void	exit_error(void)
{
	exit(ft_perror("Error\n", EXIT_FAILURE));
}

t_ps	*ft_sl(void)
{
	static t_sl	x;

	return (&x);
}

static __attribute__((constructor)) void	ps_constructor(void)
{
	ft_ps()->a.head = 0;
	ft_ps()->a.tail = 0;
	ft_ps()->a.size = 0;
	ft_ps()->a.stack = NULL;
	ft_ps()->b.head = 0;
	ft_ps()->b.tail = 0;
	ft_ps()->b.size = 0;
	ft_ps()->b.stack = NULL;
	ft_ps()->op_stack = NULL;
	ft_ps()->sorted = NULL;
	ft_ps()->vargs = NULL;
	ft_ps()->va_allocated = 0;
	ft_ps()->n_numbers = 0;
	ft_ps()->info.n_partitions = 0;
	ft_ps()->info.middle = 0;
	ft_ps()->info.offset = 0;
	ft_ps()->info.inset = 0;
	ft_ps()->info.outset = 0;
}

static __attribute__((destructor)) void	ps_destructor(void)
{
	free(ft_ps()->sorted);
	ft_deldoubly(&ft_ps()->a.stack);
	ft_deldoubly(&ft_ps()->b.stack);
	ft_deldoubly(&ft_ps()->op_stack);
	if (ft_ps()->va_allocated)
		ft_free_split(&ft_ps()->vargs);
}
