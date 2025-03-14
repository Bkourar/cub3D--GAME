#include "../Includs/raycast_bonus.h"

void	off_on(bool *key, bool signal)
{
	*key = signal;
}

bool	rot_right(t_inf *s)
{
	s->pl.rot += deg2rad(2);
	if (s->pl.rot >= 2 * M_PI)
		s->pl.rot = 0;
	return (true);
}

bool	rot_left(t_inf *s)
{
	s->pl.rot -= deg2rad(2);
	if (s->pl.rot < 0)
		s->pl.rot = 2 * M_PI;
	return (true);
}

static void	moveing(t_inf *s, bool mv)
{
	if (mlx_is_key_down(s->mlx, MLX_KEY_RIGHT))
		mv = rot_right(s);
	if (mlx_is_key_down(s->mlx, MLX_KEY_LEFT))
		mv = rot_left(s);
	if (mlx_is_key_down(s->mlx, MLX_KEY_W))
		mv = up(s);
	if (mlx_is_key_down(s->mlx, MLX_KEY_D))
		mv = right(s);
	if (mlx_is_key_down(s->mlx, MLX_KEY_S))
		mv = down(s);
	if (mlx_is_key_down(s->mlx, MLX_KEY_A))
		mv = left(s);
	if (mlx_is_key_down(s->mlx, MLX_KEY_SPACE) && s->sprit_on == false)
		off_on(&s->sprit_on, true);
	else if (s->sprit_on == true)
		off_on(&s->sprit_on, false);
	if (mlx_is_key_down(s->mlx, MLX_KEY_ESCAPE))
		exit(1);
	if (mlx_is_key_down(s->mlx, MLX_KEY_E) && s->is_door == false)
		(off_on(&s->is_door, true), switch_map(&s->plan, true, s->pl));
	if(mlx_is_key_down(s->mlx, MLX_KEY_R) && s->is_door == true)
		(off_on(&s->is_door, false), switch_map(&s->plan, false, s->pl));
	if (mv || s->sprit_on || !s->sprit_on || !s->is_door || s->is_door)
		raycasting(s);
}

void	run(void *arg)
{
	t_inf	*s;
	s = (t_inf *)arg;
	moveing(s, false);
	usleep(2000);
}