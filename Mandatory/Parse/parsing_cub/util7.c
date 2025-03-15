/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:01:00 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 03:10:52 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includs/parse.h"
#include "../../Includs/raycast.h"

int	find_map(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if ((array[i][0] && ft_skip_spaces(array[i])[0] == '1') \
		|| ft_skip_spaces(array[i])[0] == '0')
			break ;
		i++;
	}
	return (i);
}

int	get_max(char **array, int i)
{
	int	count;
	int	max;

	(1) && (max = 0, count = 0);
	while (array[i])
	{
		count = ft_strlen(array[i]);
		(max < count) && (max = count);
		i++;
	}
	return (max);
}

int	cheek_first_char(t_buff *mem)
{
	char	c;
	int		i;

	i = 0;
	while (mem->array[i])
	{
		c = ft_skip_spaces(mem->array[i])[0];
		if (c != '\0' && c != '1' && c != 'N' && c != 'S' \
		&& c != 'W' && c != 'E' && c != 'C' && c != 'F')
		{
			ft_error1("Error\ninvalid line\n");
			ft_free (mem);
			free (mem);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_util1(t_buff *mem)
{
	int		max;
	int		i;

	max = 0;
	if (cheek_first_char(mem) == 1)
		return (1);
	i = find_map(mem->array);
	max = get_max(mem->array, i);
	while (mem->array[i] != NULL)
	{
		if ((int)ft_strlen(mem->array[i]) < max)
		{
			mem->array[i] = ft_strjoin_m(mem->array[i], \
			(max - ft_strlen(mem->array[i])));
			if (!mem->array[i])
				return (ft_free(mem), free(mem), 1);
		}
		i++;
	}
	return (0);
}
