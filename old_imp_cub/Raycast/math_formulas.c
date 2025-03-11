/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_formulas.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:11:45 by bikourar          #+#    #+#             */
/*   Updated: 2025/03/09 09:29:49 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includs/raycast.h"

double	deg2rad(double deg)
{
	return	(deg * (M_PI / 180.0));
}

double	rad2deg(double rad)
{
	return	(rad * 180.0 / M_PI);
}

double	norm_rays(double ang)
{
	ang = fmod(ang, 2 * M_PI);
	if (ang < 0)
		ang += 2 * M_PI;
	return (ang);
}
