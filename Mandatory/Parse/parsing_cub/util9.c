/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 03:02:58 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 12:39:34 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includs/parse.h"
#include "../../Includs/raycast.h"

int	ft_get_tex_path(t_buff *mem, int j)
{
	char	*s;

	s = ft_skip_spaces(mem->array[j]);
	if (ft_get_tex_pngs(&mem->no_tt, s, mem->no, "NO"))
		return (ft_error1("Error\nNO_tex_path\n"), ft_free_textures(mem), 1);
	if (ft_get_tex_pngs(&mem->so_tt, s, mem->so, "SO"))
		return (ft_error1("Error\nSO_tex_path\n"), ft_free_textures(mem), 1);
	if (ft_get_tex_pngs(&mem->we_tt, s, mem->we, "WE"))
		return (ft_error1("Error\nWE_tex_path\n"), ft_free_textures(mem), 1);
	if (ft_get_tex_pngs(&mem->ea_tt, s, mem->ea, "EA"))
		return (ft_error1("Error\nEA_tex_path\n"), ft_free_textures(mem), 1);
	if (ft_get_color(&mem->celling, s, mem->c, "C"))
		return (ft_error1("Error\nColors\n"), ft_free_textures(mem), 1);
	if (ft_get_color(&mem->floor_c, s, mem->f, "F"))
		return (ft_error1("Error\nColors\n"), ft_free_textures(mem), 1);
	return (0);
}

int	get_tex(t_buff *mem, int count)
{
	int		j;

	(1) && (j = 0);
	(1) && (mem->no[0] = 0, mem->no[1] = 0, mem->so[0] = 0);
	(1) && (mem->so[1] = 0, mem->we[0] = 0, mem->we[1] = 0);
	(1) && (mem->ea[0] = 0, mem->ea[1] = 0);
	(1) && (mem->c[0] = 0, mem->c[1] = 0, mem->f[0] = 0, mem->f[1] = 0);
	(1) && (mem->no_tt = NULL, mem->so_tt = NULL, mem->ea_tt = NULL);
	mem->we_tt = NULL;
	while (mem->array[j] && j < count)
	{
		if (ft_get_tex_path(mem, j) == 1)
			return (1);
		j++;
	}
	if (get_nbr_tex(mem->no[1], mem->so[1], mem->we[1], mem->ea[1]) != 0)
		return (ft_free_textures(mem), 1);
	if (get_nbr_color(mem->c[1], mem->f[1]) != 0)
		return (ft_free_textures(mem), 1);
	return (0);
}

void	ft_close(int fd1, int fd2, int fd3, int fd4)
{
	if (fd1 != -1)
		close(fd1);
	if (fd2 != -1)
		close (fd2);
	if (fd3 != -1)
		close(fd3);
	if (fd4 != -1)
		close(fd4);
}

int	cheek_per(t_buff *mem)
{
	t_fd	ele;

	(1) && (ele.fd1 = -1, ele.fd2 = -1, ele.fd3 = -1, ele.fd4 = -1);
	if (ft_parse_color(mem->celling, &mem->cell) == -36)
		return (1);
	if (ft_parse_color(mem->floor_c, &mem->floo) == -36)
		return (1);
	ele.fd1 = open (mem->no_tt, O_RDONLY);
	if (ele.fd1 == -1)
		return (ft_close(ele.fd1, ele.fd2, ele.fd3, ele.fd4), \
	ft_error1("Error\nPermission deneid ,or NO_tex file doesn't exist\n"), 1);
	ele.fd2 = open (mem->so_tt, O_RDONLY);
	if (ele.fd2 == -1)
		return (ft_close(ele.fd1, ele.fd2, ele.fd3, ele.fd4), \
	ft_error1("Error\nPermission deneid ,or SO_tex file doesn't exist\n"), 1);
	ele.fd3 = open (mem->we_tt, O_RDONLY);
	if (ele.fd3 == -1)
		return (ft_close(ele.fd1, ele.fd2, ele.fd3, ele.fd4), \
	ft_error1("Error\nPermission deneid ,or WE_tex file doesn't exist\n"), 1);
	ele.fd4 = open (mem->ea_tt, O_RDONLY);
	if (ele.fd4 == -1)
		return (ft_close(ele.fd1, ele.fd2, ele.fd3, ele.fd4), \
	ft_error1("Error\nPermission deneid ,or EA_tex file doesn't exist\n"), 1);
	ft_close(ele.fd1, ele.fd2, ele.fd3, ele.fd4);
	return (0);
}
