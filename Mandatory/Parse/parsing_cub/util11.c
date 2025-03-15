/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util11.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:04:39 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 03:11:55 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includs/parse.h"
#include "../../Includs/raycast.h"

int	ft_cheeck_walls_util3(char **array, int count, int i)
{
	i = 0;
	while (array[count - 1] && array[count - 1][i])
	{
		if (array[count - 1][i] != '1' && array[count - 1][i] != ' ')
			return (ft_error1("Error\nInvalid Map\n"), 1);
		i++;
	}
	return (0);
}

int	cheek_walls(char **array, int count)
{
	int	i;

	i = 0;
	if (ft_cheeck_walls_util2(array, count, i) == 1)
		return (1);
	while (array[count])
	{
		i = 0;
		while (array[count][i])
		{
			if (array[count][i] == '0' || array[count][i] == 'N' \
			|| array[count][i] == 'E' || array[count][i] == 'S' \
			|| array[count][i] == 'W')
			{
				if (ft_cheeck_walls_util1(array, count, i) == 1)
					return (1);
			}
			i++;
		}
		count++;
	}
	if (ft_cheeck_walls_util3(array, count, i) == 1)
		return (1);
	return (0);
}

int	cheek_map_char_util(char **array, int count, t_mapp *ele)
{
	while (array[count])
	{
		ele->j = 0;
		while (array[count][ele->j])
		{
			(array[count][ele->j] == 'N') && (ele->n++);
			(array[count][ele->j] == 'E') && (ele->e++);
			(array[count][ele->j] == 'S') && (ele->s++);
			(array[count][ele->j] == 'W') && (ele->w++);
			if (array[count][ele->j] != '1' && array[count][ele->j] != ' ' \
			&& array[count][ele->j] != '0' \
			&& array[count][ele->j] != 'S' && array[count][ele->j] != 'N' \
			&& array[count][ele->j] != 'W' && array[count][ele->j] != 'E')
				return (ft_error1("Error\nMap chararcters\n"), 1);
			ele->j++;
		}
		count++;
	}
	if (cheek_player_pos(ele->s, ele->e, ele->w, ele->n) == 1)
		return (1);
	return (0);
}
