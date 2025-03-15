/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_m.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:55:20 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 13:48:08 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includs/parse_bonus.h"

void	ft_put_player(t_inf *s, int tz)
{
	int		p_x;
	int		p_y;
	double	angle;

	p_x = 5 * tz;
	p_y = 5 * tz;
	angle = s->pl.rot;
	my_put_pixel(s, tz * 5 - 1, tz * 5, 255);
	my_put_pixel(s, tz * 5 + 1, tz * 5, 255);
	my_put_pixel(s, tz * 5, tz * 5 - 1, 255);
	my_put_pixel(s, tz * 5, tz * 5 + 1, 255);
	draw_line(s, (t_cordinates){p_x, p_y}, \
	(t_cordinates){p_x + cos(angle) * tz, p_y + sin(angle) * tz}, 0xFF0000BB);
}

void	draw_rect(t_inf *s, int x, int y, int color)
{
	int	i;
	int	j;
	int	fact;

	i = 0;
	fact = TZ * SCAL;
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

int	get_til_color(char c)
{
	if (c == '1')
		return (0xBBBBBB99);
	else if (c == '0')
		return (0xE6F40AFF);
	else if (c == 'D')
		return (0xFF0000BB);
	else
		return (0xE6F40AFF);
}

void	draw_mini_map(t_inf *s)
{
	t_par	ele;

	ele.p_x = s->pl.p.x / TZ;
	(1) && (ele.p_y = s->pl.p.y / TZ, ele.o_x = s->pl.p.x - (5 * TZ));
	(1) && (ele.o_y = s->pl.p.y - (5 * TZ), ele.i = ele.p_x - 5);
	while (ele.i <= ele.p_x + 5)
	{
		ele.j = ele.p_y - 5;
		while (ele.j <= ele.p_y + 5)
		{
			if (ele.i >= 0 && ele.j >= 0 \
			&& ele.i < (s->w_w / TZ) && ele.j < (s->h_h / TZ))
			{
				draw_rect(s, ((ele.i * TZ) - ele.o_x) * SCAL, ((ele.j \
				* TZ) - ele.o_y) * SCAL, get_til_color(s->plan[ele.j][ele.i]));
			}
			else
				draw_rect(s, ((ele.i * TZ) - ele.o_x) * SCAL, \
				((ele.j * TZ) - ele.o_y) * SCAL, 0xC2C2C2FF);
			ele.j++;
		}
		ele.i++;
	}
	ft_put_player(s, TZ * SCAL);
}
