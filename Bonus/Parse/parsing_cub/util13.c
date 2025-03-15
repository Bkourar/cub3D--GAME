/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:45:42 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 12:02:32 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includs/parse_bonus.h"
#include "../../Includs/raycast_bonus.h"

void	cheek_doors_util(char **array, int i, int count, int *flag)
{
	flag[0]++;
	if (array[count + 1][i] != '\0' && array[count + 1][i] == '1' \
	&& array[count - 1][i] != '\0' && array[count - 1][i] == '1')
	{
		if (array[count][i + 1] != '\0' && array[count][i + 1] == '0' \
		&& array[count][i - 1] != '\0' && array[count][i - 1] == '0')
			flag[1]++;
	}
	else if (array[count + 1][i] != '\0' && array[count + 1][i] == '0' \
	&& array[count - 1][i] != '\0' && array[count - 1][i] == '0')
	{
		if (array[count][i + 1] != '\0' && array[count][i + 1] == '1' \
		&& array[count][i - 1] != '\0' && array[count][i - 1] == '1')
			flag[1]++;
	}
}

int	cheek_doors(char **array, int count)
{
	int	i;
	int	flag[2];

	flag[0] = 0;
	flag[1] = 0;
	while (array[count])
	{
		i = 0;
		while (array[count][i])
		{
			(1) && (flag[0] = 0, flag[1] = 0);
			if (array[count][i] != '\0' && array[count][i] == 'D')
				cheek_doors_util(array, i, count, flag);
			if (flag[0] == 1 && flag[1] != 1)
				return (ft_error1("Error\nInvalid map!\n"), 1);
			i++;
		}
		count++;
	}
	return (0);
}
