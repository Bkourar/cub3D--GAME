#include "recast.h"

void	draw_wall(t_inf *d, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < PX)
	{
		i = 0;
		while (i < PX)
		{
			if (i + 1 == PX)
				mlx_put_pixel(d->im, i + x * PX, j + y * PX, (uint32_t)WHITE);
			else if (j + 1 == PX)
				mlx_put_pixel(d->im, i + x * PX, j + y * PX, (uint32_t)WHITE);
			else
				mlx_put_pixel(d->im, i + x * PX, j + y * PX, (uint32_t)BLACK);
			i++;
		}
		j++;
	}
}

void	draw_floor(t_inf *d, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j < PX)
	{
		i = 0;
		while (i < PX)
		{
			if (i + 1 == PX)
				mlx_put_pixel(d->im, i + x * PX, j + y * PX, (uint32_t)BLUE);
			else if (j + 1 == PX)
				mlx_put_pixel(d->im, i + x * PX, j + y * PX, (uint32_t)BLUE);
			else
				mlx_put_pixel(d->im, i + x * PX, j + y * PX, (uint32_t)WHITE);
			i++;
		}
		j++;
	}
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

void	draw_player(t_inf *d)
{
	dda( d->pl.p.x, d->pl.p.y, d->pl.p.x + 20 * cos(d->pl.rot), d->pl.p.y + 20 * sin(d->pl.rot), d);
	mlx_put_pixel(d->im, d->pl.p.x , d->pl.p.y, (uint32_t)RED);
}

void	rendreing2d(t_inf *s)
{
	int	i;

	i = 0;
	(draw_map_p(s), draw_player(s));
	while (i < WIDTH)
	{
		dda(s->pl.p.x, s->pl.p.y, s->ra[i].r.x, s->ra[i].r.y, s);
		mlx_put_pixel(s->im, s->pl.p.x , s->pl.p.y, (uint32_t)RED);
		i++;
	}
}