#include "recast.h"

static void	rot_right(t_inf *s)
{
	int	x;
	int	y;

	x = s->info.p_x;
	y = s->info.p_y;

	s->info.rot += deg2rad(2);
	if (s->info.rot >= 2 * M_PI)
		s->info.rot = 0;
}

static void	rot_left(t_inf *s)
{
	int	x;
	int	y;

	x = s->info.p_x;
	y = s->info.p_y;
	s->info.rot -= deg2rad(2);
	if (s->info.rot < 0)
		s->info.rot = 2 * M_PI;
}

static void	move_up(t_inf *s)
{
	float	x;
	float	y;

	
	x = s->info.p_x;
	y = s->info.p_y;
	s->info.p_x = x + (3 * cos(s->info.rot));
	s->info.p_y = y + (3 * sin(s->info.rot));
}

static void	move_right(t_inf *s)
{
	float	x;
	float	y;

	x = s->info.p_x;
	y = s->info.p_y;
	s->info.p_x = x - (3 * sin(s->info.rot));
	s->info.p_y = y + (3 * cos(s->info.rot));
}

static void	move_down(t_inf *s)
{
	float	x;
	float	y;

	x = s->info.p_x;
	y = s->info.p_y;
	s->info.p_x = x - (3 * cos(s->info.rot));
	s->info.p_y = y - (3 * sin(s->info.rot));
}

static void	move_left(t_inf *s)
{
	float	x;
	float	y;

	x = s->info.p_x;
	y = s->info.p_y;
	s->info.p_x = x + (3 * sin(s->info.rot));
	s->info.p_y = y - (3 * cos(s->info.rot));
}

void	draw_map_p(t_inf *dr)
{
	int	i;
	int	j;

	i = -1;
	while (dr->plan[++i])
	{
		j = 0;
		while (dr->plan[i][j])
		{
			if (dr->plan[i][j] == '1')
				draw_wall(dr, j, i);
			else
				draw_floor(dr, j, i);
			j++;
		}
	}
}

void	routine(void *arg)
{
	t_inf	*s;
	double	hi_s;
	double	vi_s;
	t_crd	in;
	t_crd	fi;
	t_line	l;

	// mlx_delete_image(s->mlx, s->im);
	s = (t_inf *)arg;
	if (mlx_is_key_down(s->mlx, MLX_KEY_RIGHT))
		rot_right(s);
	if (mlx_is_key_down(s->mlx, MLX_KEY_LEFT))
		rot_left(s);
	if (mlx_is_key_down(s->mlx, MLX_KEY_W))
		(move_up(s));
	if (mlx_is_key_down(s->mlx, MLX_KEY_D))
		(move_right(s));// && (vi_s = vi_section(s, &fi));
	if (mlx_is_key_down(s->mlx, MLX_KEY_S))
		(move_down(s)); //&& (hi_s = hi_section(s, &in));
	if (mlx_is_key_down(s->mlx, MLX_KEY_A))
		(move_left(s));// && (vi_s = vi_section(s, &fi));
	// (draw_map_p(s), draw_player(s));
	hi_s = hi_section(s, &in);
	vi_s = vi_section(s, &fi);
	l.start.x = s->info.p_x;
	l.start.y = s->info.p_y;
	if (hi_s < vi_s)
	{
		l.end.x = in.x;
		l.end.y = in.y;
	}
	else
	{
		l.end.x = fi.x;
		l.end.y = fi.y;
	}
	(draw_map_p(s), draw_line(s, l), draw_player(s));
}

