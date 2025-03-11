/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:39:02 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/11 17:48:07 by bikourar         ###   ########.fr       */
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

void	get_player_pos(t_inf *mx)
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
			{
				mx->pl.rot = deg2rad(270);
				mx->pl.p = (t_crd){j, i};
			}
			if (mx->plan[i][j] == 'E')
			{
				mx->pl.rot = deg2rad(0);
				mx->pl.p = (t_crd){j, i};
			}
			if (mx->plan[i][j] == 'S')
			{
				mx->pl.rot = deg2rad(90);
				mx->pl.p = (t_crd){j, i};
			}
			if (mx->plan[i][j] == 'W')
			{
				mx->pl.rot = deg2rad(180);
				mx->pl.p = (t_crd){j, i};
			}
			j++;
		}
		i++;
	}
}
