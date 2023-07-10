/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:41:28 by echavez-          #+#    #+#             */
/*   Updated: 2023/07/10 23:35:16 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
static void	set_color_ptr(unsigned char *line, t_img *img, int color, int x)
{
	int				byte;
	int				dec;
	int				opp;
	unsigned char	*ucolor;

	ucolor = (unsigned char *)&color;
	dec = img->bpp / 8;
	opp = dec;
	byte = x * img->bpp / 8;
	while (dec--)
		if (img->endian == ft_sl()->g.local_endian)
		{
			if (img->endian)
				*(line + byte + dec) = ((ucolor))[4 - opp + dec];
			else
				*(line + byte + dec) = ((ucolor))[dec];
		}
		else
		{
			if (img->endian)
				*(line + byte + dec) = ((ucolor))[opp - 1 - dec];
			else
				*(line + byte + dec) = ((ucolor))[3 - dec];
		}
}

static void	fill_img(t_img *img, int w, int h, int **bmp)
{
	int				x;
	int				y;
	int				color;
	int				color2;
	unsigned char	*ptr;

	y = 0;
	while (y < h)
	{
		ptr = (unsigned char *)img->data + y * img->bpl;
		x = 0;
		while (x < w)
		{
			color = bmp[y][x];
			color2 = mlx_get_color_value(ft_sl()->g.mlx, color);
			set_color_ptr(ptr, img, color2, x);
			x++;
		}
		y++;
	}
}
*/
void		ft_plotrt(void)
{
	t_sl	*s;

	s = ft_sl();
	s->g.img = malloc(sizeof(t_img *) * (s->map_height * s->map_width + 1));
	if (!s->g.img)
		exit_error(strerror(errno));
	int	size;
	size = SPRITE;
	s->g.img[0] = mlx_xpm_file_to_image(s->g.mlx, WALL, &size, &size);//
	if (!s->g.img[0])
		exit_error("minilibx img failed\n");
	s->g.img[0]->width = SPRITE;
	s->g.img[0]->height = SPRITE;

	int i = 0;
	if (!s->map)
		ft_putendl("{MAP DOES NOT EXISTS}");
	while (s->map && i < s->map_height)
	{
		int j = 0;
		while (j < s->map_width)
		{
			if (s->map && s->map[i][j].type == '1')
				mlx_put_image_to_window(s->g.mlx, s->g.win, s->g.img[0], j * SPRITE, i * SPRITE);
			j++;
		}
		i++;
	}

	/*
	tmp = mlx_new_image(s->mlx, SPRITE, SPRITE);
	if (!tmp)
		exit_error("minilbx img failed\n");
	tmp = mlx_get_data_addr(s->g.img, &s->i.bpp, &l->bpl, &l->endian);
	fill_img(l, S.res[0], S.res[1], cam->bmp);
	mlx_put_image_to_window(S.mlx, S.win, cam->layer.img, 0, 0);
	*/
}
