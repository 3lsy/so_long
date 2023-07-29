#include "so_long.h"

void    game(void)
{
  t_sl  *s;

  s = ft_sl();
  ft_plot_map();

  printf("(%d, %d)\n", s->p.x, s->p.y);
  mlx_put_image_to_window(s->g.mlx, s->g.win, s->p.dw, s->p.x * SPRITE, s->p.y * SPRITE);
  
  mlx_loop(ft_sl()->g.mlx);
}
