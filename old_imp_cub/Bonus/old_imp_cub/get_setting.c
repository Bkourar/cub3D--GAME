#include "recast.h"

void	get_dircetion(int *d, double ang)
{
	d[0] = 1 - (2 * ((M_PI / 2) < ang  && ang < (M_PI + (M_PI / 2))));
	d[1] = 1 - (2 * (M_PI < ang && ang < (2 * M_PI)));
}

// void	set_pointer(double *v1, double *v2, double vl1, double vl2)
// {
// 	*v1 = vl1;
// 	*v2 = vl2;
// }

static int	is_wall(t_inf *s, double x_i, double y_i, int *dir)
{
	int		i;
	int		j;

	i = (x_i / PX) - (1 * (dir[0] < 0));
	j = (y_i / PX) - (1 * (dir[1] < 0));
	printf("indexes: #%d# ---- #%d#\n", i, j);
	if (j < 0 || i < 0 || i >= s->x || j >= s->y)
		return (1);
	if (s->plan[j][i] == '1')
		return (1);
	return (0);
}

double	hi_section(t_inf *s, t_crd *d)
{
	double	x_p;
	double	y_p;
	// t_line	l;
	int	x_i;
	int	y_i;
	double angle[2]; //0 is adjacent and 1 is the opposite
	int		dir[2]; //0 is the x direction and 1 is the y direction

	x_p = s->info.p_x;
	y_p = s->info.p_y;
	(void)d;
	get_dircetion(dir, s->info.rot);
	y_i = (int)(y_p / PX) * PX;
	printf("dir: [%d] --- [%d]\n",dir[0], dir[1]);
	printf("player: [%f] --- [%f]\n", s->info.p_x, s->info.p_y);
	while (0 < y_i && y_i < s->y)
	{
		if ((dir[1] < 0 && s->info.p_y > y_i) 
			|| (dir[1] > 0 && s->info.p_y < y_i))
		{
			angle[1] = fabs(y_p - y_i);
			angle[0] = fabs(angle[1] / tan(s->info.rot));
			x_i = s->info.p_x + (dir[0] * angle[0]);
			if (is_wall(s, x_i, y_i, dir))
				break ;
		}
		y_i += (1 - (2 * (dir[1] < 0))) * PX;
	}
	// printf("%d---%d\n", x_i, y_i);
	d->x = x_i;
	d->y = y_i;
	return (sqrt(pow(x_i - x_p, 2) + pow(y_i - y_p, 2)));
}

double	vi_section(t_inf *s, t_crd *d)
{
	double	x_p;
	double	y_p;
	int	x_i;
	int	y_i;
	double angle[2]; //0 is adjacent and 1 is the opposite
	int		dir[2]; //0 is the x direction and 1 is the y direction

	x_p = s->info.p_x;
	y_p = s->info.p_y;
	get_dircetion(dir, s->info.rot);
	x_i = (int)(x_p / PX) * PX;
	printf("dir: [%d] --- [%d]\n",dir[0], dir[1]);
	printf("player: [%f] --- [%f]\n", s->info.p_x, s->info.p_y);
	while (0 < x_i && x_i < s->x)
	{
		if ((dir[0] < 0 && s->info.p_x > x_i) 
			|| (dir[0] > 0 && s->info.p_x < x_i))
		{
			angle[1] = fabs(x_p - x_i);
			angle[0] = fabs(angle[1] * tan(s->info.rot));
			y_i = s->info.p_y + (dir[0] * angle[0]);
			if (is_wall(s, x_i, y_i, dir))
				break ;
		}
		x_i += (1 - (2 * (dir[0] < 0))) * PX;
	}
	d->x = x_i;
	d->y = y_i;
	// printf("%d---%d\n", x_i, y_i);
	return (sqrt(pow(x_i - x_p, 2) + pow(y_i - y_p, 2)));
}
