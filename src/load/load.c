/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 23:43:26 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/29 23:48:19 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	load_map(void)
{
	char	*line;
	int		fd;

	fd = open(ft_sl()->filename, O_RDONLY);
	if (fd < 0)
		exit_error(strerror(errno));
	line = ft_get_next_line(fd);
	while (line)
	{
		ft_putendl(line);
		free(line);
		line = ft_get_next_line(fd);
	}
	if (line)
		free(line);
}
