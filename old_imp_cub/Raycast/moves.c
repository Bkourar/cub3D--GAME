#include "Includs/raycast.h"

bool	up(t_inf *s)
{
	double	x;
	double	y;

	x = s->pl.p.x +  (3 * cos(s->pl.rot));
	y = s->pl.p.y + (3 * sin(s->pl.rot));
	if (x < 0 || y < 0 || x  > WIDTH || y > HIGHT)
		return (false);
	if (!checking(s->pl.p.x, y, s))
		s->pl.p.y = y;
	if (!checking(x, s->pl.p.y, s))
		s->pl.p.x = x;
	return (true);
}

bool	down(t_inf *s)
{
	double	x;
	double	y;

	x = s->pl.p.x -  (3 * cos(s->pl.rot));
	y = s->pl.p.y - (3 * sin(s->pl.rot));
	if (x < 0 || y < 0 || x > WIDTH || y > HIGHT)
		return (false);
	if (!checking(s->pl.p.x, y, s))
		s->pl.p.y = y;
	if (!checking(x, s->pl.p.y, s))
		s->pl.p.x = x;
	return (true);
}

bool	left(t_inf *s)
{
	double	x;
	double	y;

	x = s->pl.p.x + (3 * sin(s->pl.rot));
	y = s->pl.p.y -  (3 * cos(s->pl.rot));
	if (x < 0 || y < 0 || x > WIDTH || y > HIGHT )
		return (false);
	if (!checking(s->pl.p.x, y, s))
		s->pl.p.y = y;
	if (!checking(x, s->pl.p.y, s))
		s->pl.p.x = x;
	return (true);
}

bool	right(t_inf *s)
{
	double	x;
	double	y;

	x = s->pl.p.x - (3 * sin(s->pl.rot));
	y = s->pl.p.y +  (3 * cos(s->pl.rot));
	if (x < 0 || y < 0 || x > WIDTH || y > HIGHT)
		return (false);
	if (!checking(s->pl.p.x, y, s))
		s->pl.p.y = y;
	if (!checking(x, s->pl.p.y, s))
		s->pl.p.x = x;
	return (true);
}


// bool	up(t_inf *s)
// {
// 	double	x;
// 	double	y;

	
// 	x = s->pl.p.x + (3 * cos(s->pl.rot));
// 	y = s->pl.p.y + (3 * sin(s->pl.rot));
// 	if (x <= 0 || y <= 0 || x > WIDTH || y > HIGHT)
// 		return (false);
// 	if (s->plan[(int)y / PX][(int)x / PX] == '1')
// 		return (false);
// 	s->pl.p.x = x;
// 	s->pl.p.y = y;
// 	return (true);
// }

// bool	dn(t_inf *s)
// {
// 	double	x;
// 	double	y;

// 	x = s->pl.p.x - (3 * cos(s->pl.rot));
// 	y = s->pl.p.y - (3 * sin(s->pl.rot));
// 	if (x <= 0 || y <= 0 || x > WIDTH || y > HIGHT)
// 		return (false);
// 	if (s->plan[(int)y / PX][(int)x / PX] == '1')
// 		return (false);
// 	s->pl.p.x = x;
// 	s->pl.p.y = y;
// 	return (true);
// }

// bool	lt(t_inf *s)
// {
// 	double	x;
// 	double	y;

// 	x = s->pl.p.x + (3 * sin(s->pl.rot));
// 	y = s->pl.p.y - (3 * cos(s->pl.rot));
// 	if (x <= 0 || y <= 0 || x > WIDTH || y > HIGHT)
// 		return (false);
// 	if (s->plan[(int)y / PX][(int)x / PX] == '1')
// 		return (false);
// 	s->pl.p.x = x;
// 	s->pl.p.y = y;
// 	return (true);
// }

// bool	rt(t_inf *s)
// {
// 	double	x;
// 	double	y;
	
// 	x = s->pl.p.x - (3 * sin(s->pl.rot));
// 	y = s->pl.p.y + (3 * cos(s->pl.rot));
// 	if (x <= 0 || y <= 0 || x > WIDTH || y > HIGHT)
// 		return (false);
// 	if (s->plan[(int)y / PX][(int)x / PX] == '1')
// 		return (false);
// 	s->pl.p.x = x;
// 	s->pl.p.y = y;
// 	return (true);
// }