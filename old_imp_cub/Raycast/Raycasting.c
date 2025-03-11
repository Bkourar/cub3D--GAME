#include "Includs/raycast.h"

// static t_crd	i_horizontal(t_inf *s, int i)
// {
// 	t_crd	cur;
// 	t_crd	nex;
// 	int		x;
// 	int		y;

// 	cur.y = floor(s->pl.p.y / TZ) * TZ;
// 	if (get_direction(s, s->ra[i].rot, false, i) == SOUTH)
// 		cur.y += TZ;
// 	cur.x = s->pl.p.x + ((cur.y - s->pl.p.y) / tan(s->ra[i].rot));
// 	nex.y = TZ * (1 - (2 * (s->ra[i].dr == NORTH)));
// 	nex.x = nex.y / tan(s->ra[i].rot);
// 	nex.x *= 1 - (2 * (nex.x > 0 && s->ra[i].dr == WEST) || (nex.x < 0 && s->ra[i].dr == EAST));
// 	while (cur.x >= 0 && cur.y >= 0 && cur.x < s->w_w && cur.y  < s->h_h)
// 	{
// 		if (s->ra[i].dr == NORTH)
// 			cur.y -= 1;
// 		x = cur.x / TZ;
// 		y = cur.y / TZ;
// 		if (s->plan[y][x] == '1')
// 			return (cur);
// 		cur.y = cur.y + nex.y;
// 		cur.x = cur.x + nex.x;
// 	}
// 	return ((t_crd){INT_MAX, INT_MAX});
// }

// static t_crd	i_vertical(t_inf *s, int i)
// {
// 	t_crd	cur;
// 	t_crd	nex;
// 	int		x;
// 	int		y;

// 	cur.x = floor(s->pl.p.x / TZ) * TZ;
// 	if (get_direction(s, s->ra[i].rot, true, i) == EAST)
// 		cur.x += TZ;
// 	cur.y = s->pl.p.y + ((cur.x - s->pl.p.x) / tan(s->ra[i].rot));
// 	nex.x = TZ * (1 - (2 * (s->ra[i].dr == WEST)));
// 	nex.y = nex.x / tan(s->ra[i].rot);
// 	nex.y *= 1 - (2 * (nex.y > 0 && s->ra[i].dr == NORTH) || (nex.y < 0 && s->ra[i].dr == SOUTH));
// 	while (cur.x >= 0 && cur.y >= 0 && cur.x < s->w_w && cur.y  < s->h_h)
// 	{
// 		if (s->ra[i].dr == WEST)
// 			cur.x -= 1;
// 		// cur.x -= (s->ra[i].dr == WEST);
// 		x = cur.x / TZ;
// 		y = cur.y / TZ;
// 		if (s->plan[y][x] == '1')
// 			return (cur);
// 		cur.x = cur.x + nex.x;
// 		cur.y = cur.y + nex.y;
// 	}
// 	return ((t_crd){INT_MAX, INT_MAX});
// }

// void	raycasting(t_inf *s)
// {
// 	t_crd	c_horizontal;
// 	t_crd	c_vertical;
// 	t_crd	parameter;
// 	int		i;

// 	parameter.x = deg2rad(FOV) / WIDTH;
// 	parameter.y = s->pl.rot - deg2rad(30);
// 	i = 0;
// 	while (i < WIDTH)
// 	{
// 		s->ra[i].rot = norm_rays(parameter.y);
// 		c_horizontal = i_horizontal(s, i);
// 		c_vertical = i_vertical(s, i);
// 		set_distance(&s->ra[i], c_horizontal, c_vertical, s->pl);
// 		parameter.y += parameter.x;
// 		i++;
// 	}
// }
// void	direct(double ang, t_rys *orient, t_ply *player)
// {
// 	if (orient != NULL)
// 	{
// 		if (M_PI_2 < ang && ang < 3 * M_PI_2)
// 			orient->dr_x = 'L';
// 		else
// 			orient->dr_x = 'R';
// 		if (M_PI < ang && ang < 2 * M_PI)
// 			orient->dr_y = 'U';
// 		else
// 			orient->dr_y = 'D';
// 	}
// 	else if (player != NULL)
// 	{
// 		if (M_PI_2 < ang && ang < 3 * M_PI_2)
// 			player->dr_x = 'L';
// 		else
// 			player->dr_x = 'R';
// 		if (M_PI < ang && ang < 2 * M_PI)
// 			player->dr_y = 'U';
// 		else
// 			player->dr_y = 'D';
// 	}

// }

// t_crd	i_vertical(t_inf *s, double check, int i)
// {
// 	double	yi;
// 	double	xi;
// 	double	yn;
// 	double	xn;

// 	xi = floor(s->pl.p.x / TZ) * TZ;
// 	if (s->ra[i].dr_x == 'R')
// 		xi += TZ;
// 	yi = s->pl.p.y + ((xi - s->pl.p.x) * tan(s->ra[i].rot));
// 	xn = TZ * (1 - (2 * (s->ra[i].dr_x == 'L')));
// 	yn = xn * tan(s->ra[i].rot);
// 	yn *= 1 - (2 * (yn > 0 && s->ra[i].dr_y == 'U') || (yn < 0 && s->ra[i].dr_y == 'D'));
// 	while (xi >= 0 && yi >= 0 && xi < s->w_w && yi < s->h_h)
// 	{
// 		check = xi - (s->ra[i].dr_x == 'L');
// 		if (s->plan[(int)(yi / TZ)][(int)(check / TZ)] == '1')
// 			return ((t_crd){xi, yi});
// 		xi = xi + xn;
// 		yi = yi + yn;
// 	}
// 	return ((t_crd){INT_MAX, INT_MAX});
// }

// t_crd	i_horizontal(t_inf *s, double check, int i)
// {
// 	double	xi;
// 	double	yi;
// 	double	xn;
// 	double	yn;

// 	yi = floor(s->pl.p.y / TZ) * TZ;
// 	if (s->ra[i].dr_y == 'D')
// 		yi += TZ;
// 	xi = s->pl.p.x + ((yi - s->pl.p.y) / tan(s->ra[i].rot));
// 	yn = TZ * (1 - (2 * (s->ra[i].dr_y == 'U')));
// 	xn = yn / tan(s->ra[i].rot);
// 	xn *= 1 - (2 * (xn > 0 && s->ra[i].dr_x == 'L') || (xn < 0 && s->ra[i].dr_x == 'R'));
// 	while (xi >= 0 && yi >= 0 && xi < s->w_w && yi  < s->h_h)
// 	{
// 		check = yi - (s->ra[i].dr_y == 'U');
// 		if (s->plan[(int)(check / TZ)][(int)(xi / TZ)] == '1')
// 			return ((t_crd){xi, yi});
// 		yi = yi + yn;
// 		xi = xi + xn;
// 	}
// 	return ((t_crd){INT_MAX, INT_MAX});
// }


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