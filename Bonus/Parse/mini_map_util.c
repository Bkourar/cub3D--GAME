/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:17:07 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 13:48:23 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includs/parse_bonus.h"
#include "../Includs/raycast_bonus.h"

int	get_s(int c1, int c2)
{
	if (c1 < c2)
		return (1);
	return (-1);
}

void	my_put_pixel(t_inf *s, int x, int y, int color)
{
	if (x < 0 || x >= TZ * 10 * SCAL)
		return ;
	if (y < 0 || y >= TZ * 10 * SCAL)
		return ;
	mlx_put_pixel(s->im, x, y, color);
}

void	draw_line(t_inf *s, t_cordinates c1, t_cordinates c2, uint32_t color)
{
	t_utils	u;

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
