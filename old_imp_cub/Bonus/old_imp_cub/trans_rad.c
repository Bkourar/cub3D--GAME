#include "recast.h"

double	deg2rad(double deg)
{
	return	(deg * (M_PI / 180.0));
}

double	rad2deg(double rad)
{
	return	(rad * 180.0 / M_PI);
}

void	pinter(float x, float y, t_inf *s)
{
	if (x < 0 || x > s->x)
		return ;
	if (y < 0 || y > s->y)
		return ;
	mlx_put_pixel(s->im, x, y, (uint32_t)BLUE);
}