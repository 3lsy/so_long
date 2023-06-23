/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:49:58 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/23 15:34:04 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SO_LONG_H
# define	SO_LONG_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

typedef struct s_sl {
	char		*filename;
	int			fd;
}	t_sl;

int	valid_name(char *filename);

#endif
