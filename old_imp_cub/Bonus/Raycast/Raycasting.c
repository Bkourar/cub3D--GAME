#include "Includs/raycast_bonus.h"

t_crd	i_horizontal(t_inf *s, double ang)
{
	t_crd	cur;
	t_crd	nex;
	double	k;

	cur.y = floor(s->pl.p.y / TZ) * TZ;
	if (gtd_hor(ang) == SOUTH)
		cur.y += TZ;
	cur.x = s->pl.p.x + ((cur.y - s->pl.p.y) / tan(ang));
	nex.y = TZ;
	if (gtd_hor(ang) == NORTH)
		nex.y *= -1;
	nex.x = TZ / tan(ang);
	if (gtd_ver(ang) == WEST && nex.x > 0)
		nex.x *= -1;
	if (gtd_ver(ang) == EAST && nex.x < 0)
		nex.x *= -1;
	while (cur.x >= 0 && cur.y >= 0 && cur.x < s->w_w && cur.y < s->h_h)
	{
		k = cur.y - (gtd_hor(ang) == NORTH);
		if (s->plan[(int)floor(k / TZ)][(int)floor(cur.x / TZ)] == '1')
			return (cur);
		cur.y += nex.y;
		cur.x += nex.x;
	}
	return ((t_crd){__INT_MAX__, __INT_MAX__});
}

t_crd	i_vertical(t_inf *s, double ang)
{
	t_crd	cur;
	t_crd	nex;
	double	k;

	cur.x = floor(s->pl.p.x / TZ) * TZ;
	if (gtd_ver(ang) == EAST)
		cur.x += TZ;
	cur.y = s->pl.p.y + ((cur.x - s->pl.p.x) * tan(ang));
	nex.x = TZ;
	if (gtd_ver(ang) == WEST)
		nex.x *= -1;
	nex.y = TZ * tan(ang);
	if (gtd_hor(ang) == NORTH && nex.y > 0)
		nex.y *= -1;
	if (gtd_hor(ang) == SOUTH && nex.y < 0)
		nex.y *= -1;
	while (cur.x >= 0 && cur.y >= 0 && cur.x < s->w_w && cur.y < s->h_h)
	{
		k = cur.x - (gtd_ver(ang) == WEST);
		if (s->plan[(int)floor(cur.y / TZ)][(int)floor(k / TZ)] == '1')
			return (cur);
		cur.y += nex.y;
		cur.x += nex.x;
	}
	return ((t_crd){__INT_MAX__, __INT_MAX__});
}

void	raycasting(t_inf *s)
{
	t_crd	c_horizontal;
	t_crd	c_vertical;
	t_crd	parameter;
	int		i;

	parameter.x = deg2rad(FOV) / WIDTH;
	parameter.y = s->pl.rot - deg2rad(30);
	i = 0;
	while (i < WIDTH)
	{
		s->ra[i].rot = norm_rays(parameter.y);
		c_horizontal = i_horizontal(s, s->ra[i].rot);
		c_vertical = i_vertical(s, s->ra[i].rot);
		set_distance(&s->ra[i], c_horizontal, c_vertical, s->pl);
		parameter.y += parameter.x;
		i++;
	}
}
