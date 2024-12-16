#include "recast.h"

int	ft_sign(int nb)
{
	if (nb > 0)
		return (1);
	else if (nb < 0)
		return (-1);
	return (0);
}

void	ft_swap(double *x, double *y)
{
	double	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	less_than_one(t_inf *data, t_crd start, t_crd end)
{
	double		dy;
	double		dx;
	t_crd		sign;
	double		d_param;

	dy = fabs(end.y - start.y);
	dx = fabs(end.x - start.x);
	sign.y = ft_sign(end.y - start.y);
	sign.x = ft_sign(end.x - start.x);
	d_param = 2 * dy - dx;
	mlx_put_pixel(data->im, start.x, start.y, YL);
	while (start.x < end.x)
	{
		start.x += sign.x;
		if (d_param < 0)
			d_param += 2 * dy;
		else
		{
			start.y += sign.y;
			d_param += (2 * dy) - (2 * dx);
		}
		mlx_put_pixel(data->im, start.x, start.y, YL);
	}
}

void	greater_than_one(t_inf *data, t_crd start, t_crd end)
{
	double	dy;
	double	dx;
	t_crd	sign;
	double	d_param;

	dy = fabs(end.y - start.y);
	dx = fabs(end.x - start.x);
	sign.y = ft_sign(end.y - start.y);
	sign.x = ft_sign(end.x - start.x);
	d_param = 2 * dy - dx;
	mlx_put_pixel(data->im, start.y, start.x, YL);
	while (start.x < end.x)
	{
		start.x += sign.x;
		if (d_param < 0)
			d_param += 2 * dy;
		else
		{
			start.y += sign.y;
			d_param += (2 * dy) - (2 * dx);
		}
		// if (start.y <= 0 || start.x <= 0 || start.y > data->y || start.x > data->x)
		// 	return ;
		mlx_put_pixel(data->im, start.y, start.x, (uint32_t)YL);
	}
}

void	draw_line(t_inf *data, t_line ln)
{
	double	dy;
	double	dx;
	double	slope;

	dy = ln.end.y - ln.start.y;
	dx = ln.end.x - ln.start.x;
	slope = fabs(dy / dx);
	if (slope < 1)
	{
		if (ln.start.x > ln.end.x)
			less_than_one(data, ln.end, ln.start);
		else
			less_than_one(data, ln.start, ln.end);
	}
	else
	{
		ft_swap(&ln.start.y, &ln.start.x);
		ft_swap(&ln.end.y, &ln.end.x);
		if (ln.start.x < ln.end.x)
			greater_than_one(data, ln.start, ln.end);
		else
			greater_than_one(data, ln.end, ln.start);
	}
}