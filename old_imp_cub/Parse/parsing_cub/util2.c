/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:39:02 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/12 13:57:07 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Includs/parse.h"
#include "Includs/raycast.h"

char	*ft_strdup_1(char *s, t_buff *mem)
{
	int		i;
	char	*p;

	if (s == NULL)
		return (NULL);
	i = 0;
	p = malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	while (s[i])
	{
		if (s[i] == ' ')
			p[i] = '1';
		if (s[i] == '0' || s[i] == '1' || s[i] == 'E' || s[i] == 'W' || s[i] == 'N' || s[i] == 'S')
			p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	mem->array_w = i;
	return (p);
}

static void	set_data(double ang, int y, int x, t_buff *inf)
{
	inf->player_deg = ang;
	inf->playerY = y;
	inf->playerX = x;
}

void	get_player_pos(t_inf *mx, t_buff *inf)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (mx->plan[i])
	{
		j = 0;
		while (mx->plan[i][j])
		{
			if (mx->plan[i][j] == 'N')
				set_data(deg2rad(270), i, j, inf);
			if (mx->plan[i][j] == 'E')
				set_data(deg2rad(0), i, j, inf);
			if (mx->plan[i][j] == 'S')
				set_data(deg2rad(90), i, j, inf);
			if (mx->plan[i][j] == 'W')
				set_data(deg2rad(180), i, j, inf);
			j++;
		}
		i++;
	}
}
