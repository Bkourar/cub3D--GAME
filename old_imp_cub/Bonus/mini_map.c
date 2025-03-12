#include "recast.h"

#define scal 0.25

typedef struct s_utils
{
	double	top_x;
	double	top_y;
	double	left_x;
	double	left_y;
	double	right_x;
	double	right_y;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}	t_utils;

int	get_s(int c1, int c2)
{
	if (c1 < c2)
		return (1);
	return (-1);
}


void my_put_pixel(t_inf *s, int x, int y, int color)
{
	if (x < 0 || x >= TZ * 10 * scal)
		return;
	if (y < 0 || y >= TZ * 10 * scal)
		return;
	
	mlx_put_pixel(s->im, x,y, color);
}

void	draw_t_line(t_inf *s, t_cordinates c1
	, t_cordinates c2, uint32_t color)
{
	t_utils	u;

	u.dx = abs(c2.x - c1.x);
	u.dy = abs(c2.y - c1.y);
	u.sx = get_s(c1.x, c2.x);
	u.sy = get_s(c1.y, c2.y);
	u.err = u.dx - u.dy;
	while (1)
	{
		// put_pixel(s->im, c1.x, c1.y, color);
		my_put_pixel(s,  c1.x, c1.y, color);
		if (c1.x == c2.x && c1.y == c2.y)
			break ;
		u.e2 = 2 * u.err;
		if (u.e2 > -u.dy)
		{
			u.err -= u.dy;
			c1.x += u.sx;
		}
		if (u.e2 < u.dx)
		{
			u.err += u.dx;
			c1.y += u.sy;
		}
	}
}



void	ft_put_player(t_inf *s, int tz)
{
	int		p_x;
	int		p_y;
	double	angle;

	p_x = 5 * tz ;
	p_y = 5 * tz ;
	angle = s->pl.rot;

	my_put_pixel(s, tz * 5 - 1, tz * 5, 0xFFFFFFFF);
	my_put_pixel(s, tz * 5 + 1, tz * 5, 0xFFFFFFFF);
	my_put_pixel(s, tz * 5, tz * 5 - 1, 0xFFFFFFFF);
	my_put_pixel(s, tz * 5, tz * 5 + 1, 0xFFFFFFFF);
	draw_t_line(s, (t_cordinates){p_x, p_y},
			(t_cordinates){p_x + cos(angle) * tz,
			p_y + sin(angle) * tz}, 0xFF0000BB);

}

void	draw_rect(t_inf *s, int x, int y, int color, int fact)
{
	int i = 0, j;

	while (i < fact)
	{
		j = 0;
		while (j < fact)
		{
			my_put_pixel(s, x + i, y + j, color);
			j ++;
		}
		i ++;
	}
}

int	get_til_color(char c)
{
	if (c == '1')
		return (0xBBBBBB99);
	else if (c == '0')
		return (0xE6F40AFF);
	else if (c == 'D')
		return (255);
	else
		return (0xE6F40AFF);
}

void	draw_mini_map(t_inf *s)
{
	int		i;
	int		j;

	int		p_x;
	int		p_y;

	int		o_x;
	int		o_y;

	// float scal = 0.25;

	p_x = s->pl.p.x / TZ;
	p_y = s->pl.p.y / TZ;
	
	o_x = s->pl.p.x - (5 * TZ);
	o_y = s->pl.p.y - (5 * TZ);

	i = p_x - 5;

	while (i <= p_x + 5)
	{
		j = p_y - 5;
		while (j <= p_y + 5)
		{
			if (i >= 0 && j >= 0 && i < s->mem_width && j < s->mem_hight)
				draw_rect(s, ((i * TZ) - o_x) * scal, ((j * TZ) - o_y) * scal,
				 get_til_color(s->plan[j][i]), TZ * scal);
			else
				draw_rect(s, ((i * TZ) - o_x) * scal, ((j * TZ) - o_y) * scal, 0xC2C2C2FF,TZ * scal);
			j ++;
		}
		
		i++;
	}
	
	ft_put_player(s, TZ * scal);
}