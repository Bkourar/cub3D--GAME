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
			// if (i + x * PX < 0 || j + y * PX < 0 || i + x * PX >  d->x || j + y * PX > d->y)
			// 	return ;
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

	if (x < 0 || y < 0 || x > d->x || y > d->y)
		return ;
	j = 0;
	while (j < PX)
	{
		i = 0;
		while (i < PX)
		{
			// if (i + x * PX < 0 || j + y * PX < 0 || i + x * PX >  d->x || j + y * PX > d->y)
			// 	return ;
			mlx_put_pixel(d->im, i + x * PX, j + y * PX, (uint32_t)WHITE);
			i++;
		}
		j++;
	}
}

void	draw_player(t_inf *d)
{
	t_line line;

	line.start.x = d->info.p_x;
	line.start.y = d->info.p_y;
	line.end.x = line.start.x + 20 * cos(d->info.rot);
	line.end.y = line.start.y + 20 * sin(d->info.rot);
	draw_line(d, line);
	// if (d->info.p_x < 0 || d->info.p_x > d->x || d->info.p_y < 0 || d->info.p_y > d->y)
	// 	return ;
	mlx_put_pixel(d->im, d->info.p_x , d->info.p_y, (uint32_t)YL);
}

// void	draw_ray(t_inf *d)
// {
// 	d->set.dirction = get_direction(d->info.rot);
// 	// draw_line(d, line);
// 	// mlx_put_pixel(d->im, d->info.p_x , d->info.p_y, (uint32_t)WHITE);
// }



