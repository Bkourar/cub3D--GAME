/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_formulas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:11:45 by bikourar          #+#    #+#             */
/*   Updated: 2025/03/14 17:31:58 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includs/raycast_bonus.h"

double	deg2rad(double deg)
{
	return	(deg * (M_PI / 180.0));
}

double	rad2deg(double rad)
{
	return	(rad * 180.0 / M_PI);
}

double	norm_rays(double ang, t_rys *r, t_inf *s)
{
	ang = fmod(ang, 2 * M_PI);
	if (ang < 0)
		ang += 2 * M_PI;
	if (s->is_door == true && r->stat == true)
		r->stat = false;
	else
		r->stat = false;
	return (ang);
}
