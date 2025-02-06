#include "recast.h"

bool	up(t_inf *s)
{
	double	x;
	double	y;

	
	x = s->pl.p.x + (3 * cos(s->pl.rot));
	y = s->pl.p.y + (3 * sin(s->pl.rot));
	if (x <= 0 || y <= 0 || x > s->w_w || y > s->h_h)
		return (false);
	if (s->plan[(int)y / PX][(int)x / PX] == '1')
	{
		printf("wall hit\n");
		return (false);
	}
	s->pl.p.x = x;
	s->pl.p.y = y;
	return (true);
}

bool	dn(t_inf *s)
{
	double	x;
	double	y;

	x = s->pl.p.x - (3 * cos(s->pl.rot));
	y = s->pl.p.y - (3 * sin(s->pl.rot));
	if (x <= 0 || y <= 0 || x > s->w_w || y > s->h_h)
		return (false);
	if (s->plan[(int)y / PX][(int)x / PX] == '1')
		return (false);
	s->pl.p.x = x;
	s->pl.p.y = y;
	return (true);
}

bool	lt(t_inf *s)
{
	double	x;
	double	y;

	x = s->pl.p.x + (3 * sin(s->pl.rot));
	y = s->pl.p.y - (3 * cos(s->pl.rot));
	if (x <= 0 || y <= 0 || x > s->w_w || y > s->h_h)
		return (false);
	if (s->plan[(int)y / PX][(int)x / PX] == '1')
		return (false);
	s->pl.p.x = x;
	s->pl.p.y = y;
	return (true);
}

bool	rt(t_inf *s)
{
	double	x;
	double	y;
	
	x = s->pl.p.x - (3 * sin(s->pl.rot));
	y = s->pl.p.y + (3 * cos(s->pl.rot));
	if (x <= 0 || y <= 0 || x > s->w_w || y > s->h_h)
		return (false);
	if (s->plan[(int)y / PX][(int)x / PX] == '1')
		return (false);
	s->pl.p.x = x;
	s->pl.p.y = y;
	return (true);
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