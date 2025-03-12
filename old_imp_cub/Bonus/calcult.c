#include "recast.h"

t_crd	h_ins(t_inf *s, double check, int i)
{
	double	xi;
	double	yi;
	double	xn;
	double	yn;
	t_crd	cor;

	yi = (floor(s->pl.p.y / TZ) * TZ);
	if (s->ra[i].dr_y == 'D')
		yi += TZ;
	xi = s->pl.p.x + ((yi - s->pl.p.y) / tan(s->ra[i].rot));
	yn = TZ * (1 - (2 * (s->ra[i].dr_y == 'U')));
	xn = yn / tan(s->ra[i].rot);
	xn *= 1 - (2 * (xn > 0 && s->ra[i].dr_x == 'L') || (xn < 0 && s->ra[i].dr_x == 'R'));
	while (xi >= 0 && yi >= 0 && xi < s->w_w && yi < s->h_h)
	{
		check = yi - (s->ra[i].dr_y == 'U');
		if (s->plan[((int)check / TZ)][((int)xi / TZ)] == '1')
			return (cor.x = xi, cor.y = check, cor);
		yi = yi + yn;
		xi = xi + xn;
	}
	return (cor.x = INT_MAX, cor.y = INT_MAX, cor);
}

t_crd	v_ins(t_inf *s, double check, int i)
{
	double	yi;
	double	xi;
	double	yn;
	double	xn;
	t_crd	cor;

	xi = floor(s->pl.p.x / TZ) * TZ;
	if (s->ra[i].dr_x == 'R')
		xi += TZ;
	yi = s->pl.p.y + ((xi - s->pl.p.x) * tan(s->ra[i].rot));
	xn = TZ * (1 - (2 * (s->ra[i].dr_x == 'L')));
	yn = xn * tan(s->ra[i].rot);
	yn *= 1 - (2 * (yn > 0 && s->ra[i].dr_y == 'U') || (yn < 0 && s->ra[i].dr_y == 'D'));
	while (xi >= 0 && yi >= 0 && xi < s->w_w && yi < s->h_h)
	{
		check = xi - (s->ra[i].dr_x == 'L');
		if (s->plan[((int)yi / TZ)][((int)check / TZ)] == '1')
			return (cor.x = check, cor.y = yi, cor);
		xi = xi + xn;
		yi = yi + yn;
	}
	return (cor.x = INT_MAX, cor.y = INT_MAX, cor);
}


void	set_distance(t_rys *r, t_crd h, t_crd v, t_ply b)
{
	double	dh;
	double	dv;

	dv = sqrt(pow(v.x - b.p.x, 2) + pow(v.y - b.p.y, 2));
	dh = sqrt(pow(h.x - b.p.x, 2) + pow(h.y - b.p.y, 2));
	if (dh < dv)
	{
		r->r = h;
		r->ds = fabs(dh * cos(b.rot - r->rot));
		r->sens = true;
	}
	else if (dv < dh)
	{
		r->r = v;
		r->ds = fabs(dv * cos(b.rot - r->rot));
		r->sens = false;
	}
}
