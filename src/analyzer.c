/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:17:31 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/23 15:35:22 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_name(char *filename)
{
	const char	ext[4] = ".ber";
	int			size;
	int			i;

	i = 4;
	size = ft_strlen(filename);
	while (size > 0 && i > 0)
	{
		if (filename[--size] != ext[--i])
		{
			ft_putendl("Error: Not a valid filename");
			return (0);
		}
	}
	if (i != 0)
	{
		ft_putendl("Error: Not a valid filename");
		return (0);
	}
	return (1);
}
