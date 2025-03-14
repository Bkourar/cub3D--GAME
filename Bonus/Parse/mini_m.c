/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_m.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:55:20 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/13 17:41:55 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includs/parse_bonus.h"

int get_s(int c1, int c2)
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
	mlx_put_pixel(s->im, x, y, color);
}

void draw_line(t_inf *s, t_cordinates c1, t_cordinates c2, uint32_t color)
{
	t_utils u;

	u.dx = abs(c2.x - c1.x);
	u.dy = abs(c2.y - c1.y);
	u.sx = get_s(c1.x, c2.x);
	u.sy = get_s(c1.y, c2.y);
	u.err = u.dx - u.dy;
	while (1)
	{
		my_put_pixel(s, c1.x, c1.y, color);
		if (c1.x == c2.x && c1.y == c2.y)
			break ;
		u.e2 = 2 * u.err;
		if (u.e2 > -u.err)
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

void ft_put_player(t_inf *s, int tz)
{
	int p_x;
	int p_y;
	double angle;
	
	p_x = 5 * tz;
	p_y = 5 * tz;
	angle = s->pl.rot;

	my_put_pixel(s, tz * 5 - 1, tz * 5, 255);
	my_put_pixel(s, tz * 5 + 1, tz * 5, 255);
	my_put_pixel(s, tz * 5, tz * 5 - 1, 255);
	my_put_pixel(s, tz * 5, tz * 5 + 1, 255);
	draw_line(s, (t_cordinates){p_x, p_y}, (t_cordinates){p_x + cos(angle) * tz, p_y + sin(angle) * tz}, 0xFF0000BB);
}

void draw_rect(t_inf *s, int x, int y, int color, int fact)
{
	int i;
	int j;

	i = 0;
	while (i < fact)
	{
		j = 0;
		while (j < fact)
		{
			my_put_pixel(s, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

int get_til_color(char c)
{
	if (c == '1')
		return (0xBBBBBB99);
	else if (c == '0')
		return (0xE6F40AFF);
	else if (c == 'D')
		return (0xE6F40AFF);
	else
		return (0xE6F40AFF);
}

void draw_mini_map(t_inf *s)
{
	int i;
	int j;
	int p_x;
	int p_y;
	int o_x;
	int o_y;


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
			if (i >= 0 && j >= 0 && i < (s->w_w / TZ) && j < (s->h_h / TZ))
			{
				draw_rect(s, ((i * TZ) - o_x) * scal, ((j * TZ) - o_y) * scal, get_til_color(s->plan[j][i]), TZ * scal);
			}
			else
				draw_rect(s, ((i * TZ) - o_x) * scal, ((j * TZ) - o_y) * scal, 0xC2C2C2FF, TZ * scal);
			j++;
		}
		i++;
	}
	ft_put_player(s, TZ * scal);
}
