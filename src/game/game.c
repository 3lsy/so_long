#include "so_long.h"

int	exit_win(__attribute__((unused)) void *p)
{
	exit(EXIT_SUCCESS);
	return (1);
}

int	key_win(int key, __attribute__((unused)) void *p)
{
	if (key == 0xFF1B)
		exit_win(NULL);
	else if (key == 65361)
		left();
	else if (key == 65363)
		right();
	else if (key == 65362)
		up();
	else if (key == 65364)
		down();
	else
		printf("%d\n", key);
	return (0);
}

void    game(void)
{
  t_sl  *s;

  s = ft_sl();
  ft_plot_map();
  mlx_hook(s->g.win, 33, E_CLOSE, exit_win, 0);
  mlx_key_hook(s->g.win, key_win, s->g.mlx);


  printf("(%d, %d)\n", s->p.x, s->p.y);
  draw_player('d');

  mlx_loop(ft_sl()->g.mlx);
}
