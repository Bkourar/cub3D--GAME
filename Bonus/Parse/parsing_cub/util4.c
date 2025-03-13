/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bikourar <bikourar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 23:46:52 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/13 11:07:19 by bikourar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includs/raycast_bonus.h"
#include "../../Includs/parse_bonus.h"

void	ft_free(t_buff *mem)
{
	int	i;

	i = 0;
	while (i < mem->count)
	{
		if (mem->array[i] != NULL)
			free (mem->array[i]);
		i++;
	}
	if (mem->array)
		free (mem->array);
}

void	ft_free_list(t_map *tmp)
{
	t_map	*lst;

	lst = NULL;
	while (tmp != NULL)
	{
		lst = tmp;
		if (tmp->s != NULL)
			free (tmp->s);
		tmp = tmp->next;
		if (lst != NULL)
			free (lst);
	}
}

void ft_free_textures(t_buff *mem)
{
	if (mem->no[0] != 0)
		free (mem->NO);
	if (mem->so[0] != 0)
		free (mem->SO);
	if (mem->we[0] != 0)
		free (mem->WE);
	if (mem->ea[0] != 0)
		free (mem->EA);
	if (mem->c[0] != 0)
		free (mem->celling);
	if (mem->f[0] != 0)
		free (mem->floor_c);
}
