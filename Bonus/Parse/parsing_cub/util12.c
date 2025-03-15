/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util12.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:04:37 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 15:15:17 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includs/parse_bonus.h"
#include "../../Includs/raycast_bonus.h"

int	cheek_map_char(char **array, int count)
{
	t_mapp	ele;

	(1) && (ele.j = 0, ele.e = 0, ele.n = 0, ele.w = 0, ele.s = 0);
	(1) && (ele.map_flag = 0, ele.i = count, count = find_map(array));
	while (array[ele.i])
	{
		if (ft_skip_spaces(array[ele.i])[0] == '\0')
			return (ft_error1("Error\nInvalid map\n"), 1);
		if (ft_skip_spaces(array[ele.i])[0] == '1')
			ele.map_flag++;
		ele.i++;
	}
	if (ele.map_flag == 0)
		return (ft_error1("Error\nThere is no map\n"), 1);
	ele.i = count;
	if (cheek_walls(array, ele.i) == 1)
		return (1);
	if (cheek_doors(array, ele.i) == 1)
		return (1);
	if (cheek_map_char_util(array, count, &ele) == 1)
		return (1);
	return (0);
}

void	ft_free_mlx_texture_t(t_buff *mem)
{
	if (mem->no_tex)
		mlx_delete_texture(mem->no_tex);
	if (mem->so_tex)
		mlx_delete_texture(mem->so_tex);
	if (mem->we_tex)
		mlx_delete_texture(mem->we_tex);
	if (mem->ea_tex)
		mlx_delete_texture(mem->ea_tex);
}

int	ft_cheek_tex(char **array, t_buff *mem)
{
	int	count;

	count = find_map(array);
	if (get_tex(mem, count))
		return (1);
	if (cheek_per(mem) == 1)
		return (ft_free_textures(mem), 1);
	if (cheek_map_char(array, count))
		return (ft_free_textures(mem), 1);
	mem->no_tex = mlx_load_png(mem->no_tt);
	if (mem->no_tex == NULL)
		return (ft_error1("Error\n"), 1);
	mem->so_tex = mlx_load_png(mem->so_tt);
	if (mem->so_tex == NULL)
		return (ft_error1("Error\n"), 1);
	mem->we_tex = mlx_load_png(mem->we_tt);
	if (mem->we_tex == NULL)
		return (ft_error1("Error\n"), 1);
	mem->ea_tex = mlx_load_png(mem->ea_tt);
	if (mem->ea_tex == NULL)
		return (ft_error1("Error\n"), 1);
	return (0);
}

t_map	*get_ptr(t_map *buffer, int fd)
{
	buffer = (t_map *)malloc(sizeof (t_map));
	if (!buffer)
		return (close(fd), NULL);
	buffer->s = ft_strdup_p(get_next_line(fd));
	if (!buffer->s)
		return (close(fd), free(buffer), NULL);
	return (buffer);
}
