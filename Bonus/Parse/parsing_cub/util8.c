/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:01:20 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 11:50:57 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includs/parse_bonus.h"
#include "../../Includs/raycast_bonus.h"

int	get_nbr_tex(int no, int so, int we, int ea)
{
	int	flag;

	flag = 0;
	if (no != 1)
		(ft_error1("Error\nThere is no NO_tex or is duplicated\n"), flag++);
	if (so != 1)
		(ft_error1("Error\nThere is no SO_tex or is duplicated\n"), flag++);
	if (we != 1)
		(ft_error1("Error\nThere is no WE_tex or is duplicated\n"), flag++);
	if (ea != 1)
		(ft_error1("Error\nThere is no EA_tex or is duplicated\n"), flag++);
	return (flag);
}

int	get_nbr_color(int c, int f)
{
	int	flag;

	flag = 0;
	if (c != 1)
		(ft_error1("Error\nThere is no floor_c or duplicate\n"), flag++);
	if (f != 1)
		(ft_error1("Error\nThere is no celling_c or duplicate\n"), flag++);
	return (flag);
}

int	ft_get_tex_pngs(char **buffer, char *s, int *count_tex, char *str)
{
	if (s[0] == str[0] && s[1] == str[1] && (s[2] == '\0' || s[2] == ' '))
	{
		if (count_tex[0] == 0)
		{
			s++;
			s++;
			*buffer = ft_re_alloc(ft_skip_spaces(s));
			if (!(*buffer))
				return (1);
			count_tex[0]++;
		}
		count_tex[1]++;
	}
	return (0);
}

int	ft_get_color(char **buffer, char *s, int *count_tex, char *str)
{
	if (s[0] == str[0] && (s[1] == '\0' || s[1] == ' '))
	{
		if (count_tex[0] == 0)
		{
			s++;
			*buffer = ft_re_alloc(ft_skip_spaces(s));
			if (!(*buffer))
				return (1);
			count_tex[0]++;
		}
		count_tex[1]++;
	}
	return (0);
}
