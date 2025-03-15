/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:05:53 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 15:34:27 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includs/parse_bonus.h"
#include "../../Includs/raycast_bonus.h"

t_buff	*ft_count_nodes(t_map *buffer)
{
	t_map	*tmp3;
	t_buff	*mem;
	int		count;

	count = 0;
	tmp3 = buffer;
	mem = NULL;
	while (tmp3)
		(1) && (tmp3 = tmp3->next, count++);
	mem = (t_buff *)malloc(sizeof(t_buff));
	if (!mem)
		return (ft_free_list(buffer), NULL);
	mem->count = count;
	mem->array = (char **)malloc(sizeof(char *) * (mem->count + 1));
	if (!mem->array)
		return (ft_free_list(buffer), free (mem), NULL);
	mem->array[mem->count] = NULL;
	return (mem);
}

t_buff	*swap_content(t_map *buffer, t_buff *mem)
{
	int		i;
	t_map	*tmp2;
	t_map	*tmp3;
	t_map	*tmp4;

	(1) && (i = 0, tmp2 = NULL, tmp3 = NULL, tmp4 = NULL);
	tmp3 = buffer;
	while (buffer)
	{
		tmp2 = buffer;
		mem->array[i] = ft_strdup(buffer->s);
		if (!mem->array[i])
			return (ft_free_list(tmp3), ft_free (mem), free (mem), NULL);
		buffer = buffer->next;
		i++;
	}
	ft_free_list(tmp3);
	return (mem);
}

t_buff	*ft_parsing(int ac, char **av)
{
	t_map	*buffer;
	t_buff	*mem;
	t_map	*tmp2;
	t_map	*tmp3;

	(1) && (buffer = NULL, mem = NULL, tmp2 = NULL, tmp3 = NULL);
	buffer = ft_load_file_contenent(ac, av);
	if (!buffer)
		return (ft_free_list(buffer), NULL);
	mem = ft_count_nodes(buffer);
	if (!mem)
		return (NULL);
	if (!swap_content(buffer, mem))
		return (NULL);
	if (ft_util1(mem) == 1)
		return (NULL);
	if (ft_cheek_tex(mem->array, mem))
		return (ft_free(mem), free (mem), NULL);
	ft_free_textures(mem);
	return (mem);
}
