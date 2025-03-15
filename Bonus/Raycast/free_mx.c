/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:19:30 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 15:58:23 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includs/parse_bonus.h"
#include "../Includs/raycast_bonus.h"


void free_struct(t_inf *s)
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

void deep_free(t_inf *s)
{
	mlx_delete_texture(s->load_i.frame1);
	mlx_delete_texture(s->load_i.frame2);
	mlx_delete_texture(s->load_i.door);
	free_struct(s);
}