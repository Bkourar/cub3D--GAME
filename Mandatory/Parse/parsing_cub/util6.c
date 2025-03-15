/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:00:49 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 03:10:40 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includs/parse.h"
#include "../../Includs/raycast.h"

int	util_color1(char *s)
{
	int	i;
	int	flag;

	(1) && (i = 0, flag = 0);
	while (s[i])
	{
		if (s[i] == ',')
			flag++;
		i++;
	}
	if (flag != 2)
		return (write (2, "Error\nColors\n", 13), -1);
	return (0);
}

int	util_color3(char *s, int *count_nbr2, int *i, int *g)
{
	while (s[(*i)] && s[(*i)] == ' ')
		(*i)++;
	if (s[(*i)] == '+')
		(*i)++;
	while (s[(*i)] && (s[(*i)] >= '0' && s[(*i)] <= '9'))
	{
		(*g) = (*g) * 10 + s[(*i)] - 48;
		if ((*g) > 255)
			return (write(2, "Error\nColors\n", 13), -1);
		(1) && ((*count_nbr2)++, (*i)++);
	}
	while (s[(*i)] && s[(*i)] == ' ')
		(*i)++;
	if (s[(*i)++] != ',')
		return (write (2, "Error\nColors\n", 13), -1);
	return (0);
}

int	util_color4(char *s, int *count_nbr3, int *i, int *b)
{
	while (s[(*i)] && s[(*i)] == ' ')
		(*i)++;
	if (s[(*i)] == '+')
		(*i)++;
	while (s[(*i)] && (s[(*i)] >= '0' && s[(*i)] <= '9'))
	{
		(*b) = (*b) * 10 + s[(*i)] - 48;
		if ((*b) > 255)
			return (write (2, "Error\nColors\n", 13), -1);
		(1) && ((*count_nbr3)++, (*i)++);
	}
	if (s[(*i)] != '\0')
		return (write (2, "Error\nColors\n", 13), -1);
	return (0);
}

int	ft_parse_color(char *s, uint32_t *color)
{
	t_col	ele;

	ele.i = 0;
	(1) && (ele.r = 0, ele.g = 0, ele.b = 0, ele.result = 0);
	(1) && (ele.count_nbr1 = 0, ele.count_nbr2 = 0, ele.count_nbr3 = 0);
	if (util_color1(s) == -1)
		return (-36);
	if (util_color3(s, &ele.count_nbr1, &ele.i, &ele.r) == -1)
		return (-36);
	if (util_color3(s, &ele.count_nbr2, &ele.i, &ele.g) == -1)
		return (-36);
	if (util_color4(s, &ele.count_nbr3, &ele.i, &ele.b) == -1)
		return (-36);
	if (ele.count_nbr1 == 0 || ele.count_nbr2 == 0 || ele.count_nbr3 == 0)
		return ((write (2, "Error\nColors\n", 13)), -36);
	ele.result = (ele.r << 24) | (ele.g << 16) | (ele.b << 8) | 255;
	*color = ele.result;
	return (ele.result);
}
