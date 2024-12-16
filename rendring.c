#include "recast.h"

void	rendereding(t_inf *s)
{
	double	ds_h;
	double	y_h;
	double	celling;
	double	angl;
	int		i;
	int 	j;

	i = 0;
	angl = tan(deg2rad(FOV / 2));
	while (i < WIDTH)
	{
		j = 0;
		ds_h = (WIDTH / 2) / angl;
		y_h = (PX / s->ra[i].ds) * ds_h;
		celling = (HIGHT / 2) - (y_h / 2);
		while (celling > 0)
		{
			mlx_put_pixel(s->im, i, j++, (uint32_t)BLUE);
			celling--;
		}
		int l = (int)y_h;
		while (l > 0 && j < HIGHT)
		{
			mlx_put_pixel(s->im, i, j++, (uint32_t)YL);
			l--;
		}
		while (j < HIGHT)
			mlx_put_pixel(s->im, i, j++, (uint32_t)WHITE);
		i++;
	}
}