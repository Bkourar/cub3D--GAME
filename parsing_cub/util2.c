/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:39:02 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/06 14:32:58 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../recast.h"

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
		// if (s[i] == ' ')
		// 	p[i] = '1';
		if (s[i] == '0' || s[i] == '1' || s[i] == 'E' || s[i] == 'W' || s[i] == 'N' || s[i] == 'S')
			p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	mem->array_w = i;
	return (p);
}

void get_player_pos(t_inf *mx)
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
				mx->player_deg = 270;
				mx->pl.dr_y = i;
				mx->pl.dr_x = j;
			}
			if (mx->plan[i][j] == 'E')
			{
				mx->player_deg = 0;
				mx->pl.dr_y = i;
				mx->pl.dr_x = j;
			}
			if (mx->plan[i][j] == 'S')
			{
				mx->player_deg = 90;
				mx->pl.dr_y = i;
				mx->pl.dr_x = j;
			}
			if (mx->plan[i][j] == 'W')
			{
				mx->player_deg = 180;
				mx->pl.dr_y = i;
				mx->pl.dr_x = j;
			}
			j++;
		}
		i++;
	}
}