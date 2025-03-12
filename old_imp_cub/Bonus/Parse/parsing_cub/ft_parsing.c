/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:05:53 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/11 15:08:46 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../recast.h"

int util_color1(char *s)
{
	int i;
	int flag;

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

int util_color3(char *s, int *count_nbr2, int *i, int *g)
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
		((*count_nbr2)++, (*i)++);
	}
	while (s[(*i)] && s[(*i)] == ' ')
		(*i)++;
	if (s[(*i)++] != ',')
		return (write (2, "Error\nColors\n", 13), -1);
	return (0);
}

int util_color4(char *s, int *count_nbr3, int *i, int *b)
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
		((*count_nbr3)++, (*i)++);
	}
	if (s[(*i)] != '\0')
		return (write (2, "Error\nColors\n", 13), -1);
	return (0);
}

int ft_parse_color(char *s, uint32_t *color)
{
	int r;
	int g;
	int b;
	uint32_t result;
	int count_nbr1;
	int count_nbr2;
	int count_nbr3;
	int i;
	
	i = 0;
	(1) && (r = 0, g = 0, b = 0, result = 0);
	(1) && (count_nbr1 = 0, count_nbr2 = 0, count_nbr3 = 0);
	if (util_color1(s) == -1)
		return (-36);
	if (util_color3(s, &count_nbr1, &i, &r) == -1)
		return (-36);
	if (util_color3(s, &count_nbr2, &i, &g) == -1)
		return (-36);
	if (util_color4(s, &count_nbr3, &i, &b) == -1)
		return (-36);
	if (count_nbr1 == 0 || count_nbr2 == 0 || count_nbr3 == 0)
		return ((write (2, "Error\nColors\n", 13)), -36);
	result = (r << 24) | (g << 16) | (b << 8) | 255;
	*color = result;
	return (result);
}

int find_map(char **array)
{
	int i;
	char *s;

	i = 0;
	while (array[i])
	{
		if (array[i][0] && ft_skip_spaces(array[i])[0] == '1' || ft_skip_spaces(array[i])[0] == '0')
			break ;
		i++;
	}
	return (i);
}

int get_max(char **array, int i)
{
	int count;
	int max;

	(1) && (max = 0, count = 0);
	while (array[i])
	{
		count = ft_strlen(array[i]);
		(max < count) && (max = count);
		i++;
	}
	return (max);
}
int ft_util1(t_buff *mem)
{
	int	i;
	int	max;
	char c;
	
	(1) && (i = 0, max = 0);
	i = 0;
	while (mem->array[i])
	{
		c = ft_skip_spaces(mem->array[i])[0];
		if (c != '\0' &&  c != '1' && c != 'N'  && c != 'S' && c != 'W' && c != 'E' && c != 'C' && c != 'F' && c != 'D')
			return ( ft_error(NULL, NULL, "Error\ninvalid line\n"), ft_free (mem), free (mem), 1);
		i++;
	}
	i = find_map(mem->array);
	max = get_max(mem->array, i);
	while (mem->array[i] != NULL)
	{
		if (ft_strlen(mem->array[i]) < max)
		{	
			mem->array[i] = ft_strjoin_m(mem->array[i], (max - ft_strlen(mem->array[i])));
			if (!mem->array[i])
				return (ft_free(mem), free(mem), 1);
		}
		i++;
	}
	return (0);
}

int get_nbr_tex(int no, int so, int we, int ea)
{
	int flag;

	flag = 0;
	if (no != 1)
		ft_error("Error\nThere is no NO_tex or is duplicated\n", NULL, NULL), flag++;
	if (so != 1)
		ft_error("Error\nThere is no SO_tex or is duplicated\n", NULL, NULL), flag++;
	if (we != 1)
		ft_error("Error\nThere is no WE_tex or is duplicated\n", NULL, NULL), flag++;
	if (ea != 1)
		ft_error("Error\nThere is no EA_tex or is duplicated\n", NULL, NULL), flag++;
	return (flag);
}

int get_nbr_color(int c, int f)
{
	int flag;

	flag = 0;
	if (c != 1)
		ft_error("Error\nThere is no floor_c or duplicate\n", NULL, NULL), flag++;
	if (f != 1)
		ft_error("Error\nThere is no celling_c or duplicate\n", NULL, NULL), flag++;
	return (flag);
}

int ft_get_tex_pngs(char **buffer, char *s, int *count_tex, char *str)
{
	if (s[0] == str[0] && s[1] == str[1] && (s[2] ==  '\0' || s[2] == ' '))
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

int ft_get_celling_floor_color(char **buffer, char *s, int *count_tex, char *str)
{
	if (s[0] == str[0] && (s[1] ==  '\0' || s[1] == ' '))
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

int get_tex(t_buff *mem, int count)
{
	int j;
	int i = 0;
	char *s;
	
	(1) && (j = 0);
	(1) && (mem->no[0] = 0, mem->no[1] = 0, mem->so[0] = 0, mem->so[1] = 0, mem->we[0] = 0, mem->we[1] = 0, mem->ea[0] = 0, mem->ea[1] = 0);
	(1) && (mem->c[0] = 0, mem->c[1] = 0, mem->f[0] = 0, mem->f[1] = 0);
	(1) && (mem->NO = NULL, mem->SO = NULL, mem->EA = NULL, mem->WE = NULL);
	while (mem->array[j] && j < count)
	{
		s = ft_skip_spaces(mem->array[j]);
		if (ft_get_tex_pngs(&mem->NO, s, mem->no, "NO"))
			return (ft_error(NULL, NULL, "Error\nNO_tex_path\n"), ft_free_textures(mem), 1);
		if (ft_get_tex_pngs(&mem->SO, s, mem->so, "SO"))
			return (ft_error(NULL, NULL, "Error\nSO_tex_path\n"), ft_free_textures(mem), 1);
		if (ft_get_tex_pngs(&mem->WE, s, mem->we, "WE"))
			return (ft_error(NULL, NULL, "Error\nWE_tex_path\n"), ft_free_textures(mem), 1);
		if (ft_get_tex_pngs(&mem->EA, s, mem->ea, "EA"))
			return (ft_error(NULL, NULL, "Error\nEA_tex_path\n"), ft_free_textures(mem), 1);
		if (ft_get_celling_floor_color(&mem->celling, s, mem->c, "C"))
			return (ft_error(NULL, NULL, "Error\ncolor_numbers\n"), ft_free_textures(mem), 1);
		if (ft_get_celling_floor_color(&mem->floor_c, s, mem->f, "F"))
			return (ft_error(NULL, NULL, "Error\ncolor_numbers\n"), ft_free_textures(mem), 1);
		j++;
	}
	if (get_nbr_tex(mem->no[1], mem->so[1], mem->we[1], mem->ea[1]) != 0)
		return (ft_free_textures(mem), 1);
	if (get_nbr_color(mem->c[1], mem->f[1]) != 0)
		return (ft_free_textures(mem), 1);
	return (0);
}

void ft_close(int fd1, int fd2, int fd3, int fd4)
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

int cheek_per(t_buff *mem)
{
	int fd1;
	int fd2;
	int fd3;
	int fd4;

	(1) && (fd1 = -1, fd2 = -1, fd3 = -1, fd4 = -1);
	if (ft_parse_color(mem->celling, &mem->cell) == -36)
		return (1);
	if (ft_parse_color(mem->floor_c, &mem->floo) == -36)
		return (1);
	fd1 = open (mem->NO, O_RDONLY);
	if (fd1 == -1)
		return (ft_close(fd1, fd2, fd3, fd4), ft_error("Error\nPermission deneid of NO_tex file does not exist\n", NULL, NULL), 1);
	fd2 = open (mem->SO, O_RDONLY);
	if (fd2 == -1)
		return (ft_close(fd1, fd2, fd3, fd4), ft_error("Error\nPermission deneid of SO_tex file does not exist\n", NULL, NULL), 1);
	fd3 = open (mem->WE, O_RDONLY);
	if (fd3 == -1)
		return (ft_close(fd1, fd2, fd3, fd4), ft_error("Error\nPermission deneid of WE_tex file does not exist\n", NULL, NULL), 1);
	fd4 = open (mem->EA, O_RDONLY);
	if (fd4 == -1)
		return (ft_close(fd1, fd2, fd3, fd4), ft_error("Error\nPermission deneid of EA_tex file does not exist\n", NULL, NULL), 1);
	ft_close(fd1, fd2, fd3, fd4);
	return (0);
}

int cheek_player_pos(int s, int e, int w, int n)
{
	if ((s + e + w + n) == 0)
		return (ft_error(NULL, NULL, "Error\nThere is no player pos\n"), 1);
	if ((s + e + w + n) > 1)
		return (ft_error(NULL, NULL, "Error\nplayer position is duplicated\n"), 1);
	return (0);
}

int util_walls(char **array, int count, int i)
{
	if (array[count] != NULL &&  array[count][i] != '0' && array[count][i] != '1' \
	&& array[count][i] != 'N' && array[count][i] != 'S' \
	&& array[count][i] != 'W' && array[count][i] != 'E' && array[count][i] != 'D')
		return (ft_error(NULL, NULL, "Error\nInvalid Map characters22\n"), 1);
	return (0);
}

int cheek_walls(char **array, int count)
{
	int i;

	i = 0;
	while (array[count] &&  array[count][i])
	{
		if (array[count][i] != '1' && array[count][i] != ' ')
			return (ft_error(NULL, NULL, "Error\nInvalid Map\n"), 1);
		i++;
	}
	while (array[count])
	{
		i = 0;
		while (array[count][i])
		{
			if (array[count][i] == '0' || array[count][i] == 'N' || array[count][i] == 'E' || array[count][i] == 'S' || array[count][i] == 'W')
			{
				if (util_walls(array, count + 1, i) == 1)
					return (1);
				if (util_walls(array, count - 1, i) == 1)
					return (1);
				if (util_walls(array, count, i + 1) == 1)
					return (1);
				if (util_walls(array, count, i - 1) == 1)
					return (1);
			}
			i++;
		}
		count++;
	}
	i = 0;
	while (array[count - 1] && array[count - 1][i])
	{
		if (array[count - 1][i] != '1' && array[count - 1][i] != ' ')
			return (ft_error(NULL, NULL, "Error\nInvalid Map\n"), 1);
		i++;
	}
	return (0);
}

int cheek_doors(char **array, int count)
{
	int i;
	int flag1 = 0;
	int flag2 = 0;
	
	while (array[count])
	{
		i = 0;
		while (array[count][i])
		{
			(1) && (flag1 = 0, flag2 = 0);
			if (array[count][i] != '\0' &&  array[count][i] == 'D')
			{
				flag1++;
				if (array[count + 1][i] != '\0' && array[count + 1][i] == '1' && array[count - 1][i] != '\0' && array[count - 1][i] == '1')
				{
					if (array[count][i + 1] != '\0' && array[count][i + 1] == '0' && array[count][i - 1] != '\0' && array[count][i - 1] == '0')
					{
						flag2++;
					}
				}
				else if (array[count + 1][i] != '\0' && array[count + 1][i] == '0' && array[count - 1][i] != '\0' && array[count - 1][i] == '0')
				{
					if (array[count][i + 1] != '\0' && array[count][i + 1] == '1' && array[count][i - 1] != '\0' && array[count][i - 1] == '1')
					{	
						flag2++;
					}
				}
			}
			if (flag1 == 1 && flag2 != 1)
				return (ft_error(NULL, NULL, "Error\nInvalid door structure\n"), 1);
			i++;
		}
		count++;
	}
	return (0);
}

int cheek_map_char(char **array, int count)
{
	int j;
	int i;
	int e;
	int n;
	int w;
	int s;
	int map_flag = 0;
	
	(1) && (count = find_map(array), j = 0, e = 0, n = 0, w = 0, s = 0);
	i = count;
	while (array[i])
	{
		if (ft_skip_spaces(array[i])[0] == '\0')
			return (ft_error(NULL, NULL, "Error\nInvalid map\n"), 1);
		if (ft_skip_spaces(array[i])[0] == '1')
			map_flag++;
		i++;
	}
	if (map_flag == 0)
		return (ft_error(NULL, NULL, "Error\nThere is no map\n"), 1);
	i = count;
	if (cheek_walls(array, i) == 1)
		return (1);
	if (cheek_doors(array, i) == 1)
		return (1);
	while (array[count])
	{
		j = 0;
		while (array[count][j])
		{
			(array[count][j] == 'N') && (n++);
			(array[count][j] == 'E') && (e++);
			(array[count][j] == 'S') && (s++);
			(array[count][j] == 'W') && (w++);
			if (array[count][j] != '1' && array[count][j] != ' ' && array[count][j] != '0' \
			&& array[count][j] != 'S' && array[count][j] != 'N' && array[count][j] != 'W' && array[count][j] != 'E' && array[count][j] != 'D')
				return (ft_error(NULL, NULL, "Error\nMap chararcters\n"), 1);
			j++;
		}
		count++;
	}
	count = find_map(array);
	if (cheek_player_pos(s, e, w, n) == 1)
		return (1);
	return (0);
}

void ft_free_mlx_texture_t(t_buff *mem)
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

int ft_cheek_tex(char **array, t_buff *mem)
{
	int count;
	
	count = find_map(array);
	if (get_tex(mem, count))
		return (1);
	if (cheek_per(mem) == 1)
		return (ft_free_textures(mem), 1);
	if (cheek_map_char(array, count))
		return (ft_free_textures(mem), 1);
	mem->no_tex =  mlx_load_png(mem->NO);
	if (mem->no_tex == NULL)
		return (ft_error("Error\n", NULL, NULL), 1);
	mem->so_tex =  mlx_load_png(mem->SO);
	if (mem->so_tex == NULL)
		return (ft_error("Error\n", NULL, NULL), 1);
	mem->we_tex =  mlx_load_png(mem->WE);
	if (mem->we_tex == NULL)
		return (ft_error("Error\n", NULL, NULL), 1);
	mem->ea_tex = mlx_load_png(mem->EA);
	if (mem->ea_tex == NULL)
		return (ft_error("Error\n", NULL, NULL), 1);
	ft_free_textures(mem);
	return(0);
}

t_map *ft_get_line(int fd)
{
	t_map *buffer;
	t_map *tmp;
	t_map *tmp1;

	(1) && (buffer = NULL, tmp = NULL, tmp1 = NULL);
	buffer = (t_map *)malloc(sizeof (t_map));
	if (!buffer)
		return (close(fd), NULL);
	buffer->next = NULL;
	tmp = buffer;
	buffer->s = ft_strdup_p(get_next_line(fd));
	if (!buffer->s)
		return (close(fd), free(buffer), NULL);
	while ((buffer->tmp = get_next_line(fd)))
	{
		tmp1 = (t_map *)malloc(sizeof(t_map));
		if (!tmp1)
			return(close(fd), ft_free_list(buffer), NULL);
		tmp1->s = ft_strdup_p(buffer->tmp);
		if (!tmp1->s)
			return (close(fd), ft_free_list(buffer), NULL);
		tmp->next = tmp1;
		(1) && (tmp1->next = NULL, tmp = tmp->next);
	}
	close(fd);
	return (buffer);
}



t_map *ft_load_file_contenent(int ac, char **av)
{
	t_map	*buffer;
	int		fd;

	(1) && (fd = -1, buffer = NULL);
	fd = ft_cheek_fd(ac, av);
	if (fd == -1)
		return (NULL);
	buffer = ft_get_line(fd);
	if (!buffer)
		return (NULL);
	return (buffer);
}

t_buff *ft_count_nodes(t_map *buffer)
{
	t_map	*tmp3;
	t_buff	*mem;
	int count;

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

t_buff *swap_content(t_map *buffer, t_buff *mem)
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

t_buff *ft_parsing(int ac, char **av)
{
	t_map *buffer;
	t_buff *mem;
	t_map *tmp2;
	t_map *tmp3;
	int i = 0;
	
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
	return (mem);
}
