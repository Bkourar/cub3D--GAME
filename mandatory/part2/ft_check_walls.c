/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anqabbal <anqabbal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:13:48 by anqabbal          #+#    #+#             */
/*   Updated: 2024/10/29 18:04:56 by anqabbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_the_right_value(char ind, int *x, int *y, t_exec *e)
{
	if (ind == 0)
	{
		*x = e->ply.px - (cos(e->ply.rotangle - degree_to_rad(90))
				* (e->i + 20));
		*y = e->ply.py - (sin(e->ply.rotangle - degree_to_rad(90))
				* (e->i + 20));
	}
	else if (ind == 1)
	{
		*x = e->ply.px - (cos(e->ply.rotangle) * (e->i + 20));
		*y = e->ply.py - (sin(e->ply.rotangle) * (e->i + 20));
	}
	else if (ind == 2)
	{
		*x = e->ply.px - (cos(e->ply.rotangle + degree_to_rad(90))
				* (e->i + 20));
		*y = e->ply.py - (sin(e->ply.rotangle + degree_to_rad(90))
				* (e->i + 20));
	}
	else if (ind == 3)
	{
		*x = e->ply.px + (cos(e->ply.rotangle) * (e->i + 20));
		*y = e->ply.py + (sin(e->ply.rotangle) * (e->i + 20));
	}
}

int	ft_check_walls(t_exec *exec, int ind)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	while (++i <= exec->ply.move_inc)
	{
		exec->i = i;
		set_the_right_value(ind, &x, &y, exec);
		if (i == 1 && exec->info.map[(int)floor(y / PIXELS)]
			[(int)floor(x / PIXELS)] == '1')
			return (0);
		else if (exec->info.map[(int)floor(y / PIXELS)]
			[(int)floor(x / PIXELS)] == '1')
			return (exec->ply.move_inc = i - 1, i);
	}
	exec->ply.move_inc = i - 1;
	return (i);
}
