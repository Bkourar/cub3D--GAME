/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:03:08 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 11:51:07 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includs/parse_bonus.h"
#include "../../Includs/raycast_bonus.h"

int	cheek_player_pos(int s, int e, int w, int n)
{
	if ((s + e + w + n) == 0)
		return (ft_error1("Error\nThere is no player pos\n"), 1);
	if ((s + e + w + n) > 1)
		return (ft_error1("Error\nplayer position is duplicated\n"), 1);
	return (0);
}

int	util_walls(char **array, int count, int i)
{
	if (array[count] != NULL && array[count][i] != '0' \
	&& array[count][i] != '1' && array[count][i] != 'N' \
	&& array[count][i] != 'S' && array[count][i] != 'W' \
	&& array[count][i] != 'E' && array[count][i] != 'D')
		return (ft_error1("Error\nInvalid Map characters\n"), 1);
	return (0);
}

int	ft_cheeck_walls_util1(char **array, int count, int i)
{
	if (util_walls(array, count + 1, i) == 1)
		return (1);
	if (util_walls(array, count - 1, i) == 1)
		return (1);
	if (util_walls(array, count, i + 1) == 1)
		return (1);
	if (util_walls(array, count, i - 1) == 1)
		return (1);
	return (0);
}

int	ft_cheeck_walls_util2(char **array, int count, int i)
{
	i = 0;
	while (array[count] && array[count][i])
	{
		if (array[count][i] != '1' && array[count][i] != ' ')
			return (ft_error1("Error\nInvalid Map\n"), 1);
		i++;
	}
	return (0);
}
