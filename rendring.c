#include "recast.h"

uint32_t	get_color(uint32_t color)
{
	uint8_t	b;
	uint8_t	g;
	uint8_t	r;

	b = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	r = color & 0xFF;
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

// static void    set_color_value(t_exe *exec, float angle, int *color, t_ray *ray)
// {
//     if (ray->hv == 0 && ((angle >= 0 && angle < M_PI_2)
//             || (angle >= 3 * M_PI_2 && angle < 2 * M_PI)))
//         *color = get_pixel(exec->we->pixels, ray->o);
//     else if (ray->hv == 0 && angle >= M_PI_2 && angle < 3 * M_PI_2)
//         *color = get_pixel(exec->ea->pixels, ray->o);
//     else if (ray->hv == 1 && angle >= 0 && angle < M_PI)
//         *color = get_pixel(exec->so->pixels, ray->o);
//     else if (ray->hv == 1 && angle >= M_PI && angle < 2 * M_PI)
//         *color = get_pixel(exec->no->pixels, ray->o);
//     if (exec->info.old_map[(int)floor(exec->ply.py / PIXELS)]
//         [(int)floor(exec->ply.px / PIXELS)] == 'D')
//         draw_opened_door(exec, color, ray);
//     if (ray->d == 2)
//         *color = get_pixel(exec->d->pixels, ray->o);
// }


void	rendereding_wall(t_inf *s, int pos_w, int w_hight, int *j)
{
	uint32_t		color;
	int				index;
	int				offex;
	int				offey;
	int				ds_from_to_pp;
	int				start = w_hight;
	uint32_t *pexel_arr = (uint32_t *)s->pic->pixels;
	if (s->ra[pos_w].sens == true)
		offex = ((int)s->ra[pos_w].r.x % TZ);
	else
		offex = ((int)s->ra[pos_w].r.y % TZ);
	while (start > 0 && *j < HIGHT)
	{
		ds_from_to_pp = (*j) + (w_hight / 2) - (HIGHT / 2);
		offey = ds_from_to_pp * ((float)TZ / w_hight);
		index = ((s->pic->width * offey) + offex);
		// printf("%d\n", index);
		color = get_color(pexel_arr[index]);
		mlx_put_pixel(s->im, pos_w, (*j)++, color);
		start--;
	}
}

void	rendereding_celling(t_inf *s, int i, double y_h, int *j)
{
	int	celling = (HIGHT / 2) - (y_h / 2);
	while (celling > 0) 
	{
		mlx_put_pixel(s->im, i, (*j)++, s->cell);
		celling--;
	}
}

void	rendereding_floor(t_inf *s, int i,int *j)
{

	while (*j < HIGHT) {
		mlx_put_pixel(s->im, i, (*j)++, s->floo);
	}
}

void	rendereding(t_inf *s, int i)
{
	double		cosx = (WIDTH / 2) / tan(deg2rad(FOV / 2));
	double		wall_h;
	int			j;

	while (i < WIDTH)
	{
		j = 0;
		wall_h = (TZ / s->ra[i].ds) * cosx;
		rendereding_celling(s, i, wall_h, &j);
		rendereding_wall(s, i, wall_h, &j);
		rendereding_floor(s, i ,&j);
		i++;
	}
}