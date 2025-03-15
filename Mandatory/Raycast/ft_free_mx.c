/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:01:11 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 15:02:28 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includs/raycast.h"

void ft_free_mx(t_inf *s)
{
	int i;

	i = 0;
	while (s->mem->array[i])
	{
		free (s->mem->array[i]);
		i++;
	}
	free(s->mem->array);
	mlx_delete_texture(s->mem->no_tex);
	mlx_delete_texture(s->mem->so_tex);
	mlx_delete_texture(s->mem->we_tex);
	mlx_delete_texture(s->mem->ea_tex);
	i = 0;
	while (s->plan[i])
	{
		free (s->plan[i]);
		i++;
	}
	free(s->plan);
	free (s->mem);
}
