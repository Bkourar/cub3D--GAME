#include "Includs/raycast_bonus.h"

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

void	set_distance(t_rys *r, t_crd h, t_crd v, t_ply c) 
{
	double	dh;
	double	dv;

	dv = sqrt(pow(v.x - c.p.x, 2) + pow(v.y - c.p.y, 2));
	dh = sqrt(pow(h.x - c.p.x, 2) + pow(h.y - c.p.y, 2));
	if (dh <= dv)
	{
		r->r = h;
		r->ds = fabs(dh * cos(c.rot - r->rot));
		r->sens = true;
	}
	else
	{
		r->r = v;
		r->ds = fabs(dv * cos(c.rot - r->rot));
		r->sens = false;
	}
}

mlx_texture_t	*get_texture(t_inf *s, int i)
{
	if (s->ra[i].sens && gtd_hor(s->ra[i].rot) == NORTH)
		return(s->load_i.text_n);
	else if (s->ra[i].sens && gtd_hor(s->ra[i].rot) == SOUTH)
		return(s->load_i.text_s);
	else if (!s->ra[i].sens && gtd_ver(s->ra[i].rot) == EAST)
		return(s->load_i.text_e);
	else if (!s->ra[i].sens && gtd_ver(s->ra[i].rot) == WEST)
		return(s->load_i.text_w);
	return (NULL);
}