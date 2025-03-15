/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:39:38 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 13:51:44 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includs/raycast_bonus.h"

int	get_last_mouse(int i)
{
	static int	last_mouse_x;

	if (i != -1)
	{
		last_mouse_x = i;
	}
	return (last_mouse_x);
}

void	ft_get_mouse_mv(t_inf *s, bool mv)
{
	int32_t	mouse_x;
	int32_t	mouse_y;
	int		mouse_delta;

	mlx_set_cursor_mode(s->mlx, MLX_MOUSE_HIDDEN);
	mlx_get_mouse_pos(s->mlx, &mouse_x, &mouse_y);
	if (get_last_mouse(-1) != -1)
	{
		mouse_delta = mouse_x - get_last_mouse(-1);
		if (mouse_delta > 5)
			mv = rot_right(s);
		else if (mouse_delta < -5)
			mv = rot_left(s);
	}
	get_last_mouse(mouse_x);
	if (mouse_x < 100 || mouse_x > s->wid - 100)
	{
		mlx_set_mouse_pos(s->mlx, s->wid / 2, mouse_y);
		get_last_mouse(s->wid / 2);
	}
	if (mlx_is_mouse_down(s->mlx, MLX_MOUSE_BUTTON_RIGHT))
		mv = rot_right(s);
	if (mlx_is_mouse_down(s->mlx, MLX_MOUSE_BUTTON_LEFT))
		mv = rot_left(s);
}
