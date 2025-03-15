/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:23:41 by eenassir          #+#    #+#             */
/*   Updated: 2025/03/15 15:16:18 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H

# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <math.h>
# include <fcntl.h>
# include "../../MLX42/include/MLX42/MLX42.h"
# include "../Parse/get_next_line/get_next_line.h"
# include "raycast_bonus.h"
# define SCAL 0.25

typedef struct s_par
{
	int	i;
	int	j;
	int	p_x;
	int	p_y;
	int	o_x;
	int	o_y;
}	t_par;

typedef struct s_mapp
{
	int	j;
	int	i;
	int	e;
	int	n;
	int	w;
	int	s;
	int	map_flag;
}	t_mapp;

typedef struct s_fd
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;
}	t_fd;

typedef struct s_col
{
	int			r;
	int			g;
	int			b;
	uint32_t	result;
	int			count_nbr1;
	int			count_nbr2;
	int			count_nbr3;
	int			i;
}	t_col;

typedef struct s_cordinates
{
	int	x;
	int	y;
}	t_cordinates;

typedef struct s_utils
{
	double	top_x;
	double	top_y;
	double	left_x;
	double	left_y;
	double	right_x;
	double	right_y;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}	t_utils;

typedef struct s_map
{
	char			*s;
	char			*tmp;
	int				count;
	struct s_map	*next;
}					t_map;

int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strlen_m(char *s, char c);
char	*ft_strjoin_m(char *s1, int add);
void	ft_error1(char *str1);
void	ft_error2(char *str1, char *str2);
void	ft_error3(char *str1, char *str2, char *str3);
char	*ft_strdup_p(char *s);
char	*ft_strdup_1(char *s, t_buff *mem);
void	get_player_pos(t_inf *mx, t_buff *inf);
int		get_map_mem(t_inf *mx, t_buff *mem);
void	ft_free(t_buff *mem);
void	ft_free_list(t_map *tmp);
void	ft_free_textures(t_buff *mem);
t_buff	*ft_parsing(int ac, char **av);
char	*ft_skip_spaces(char *s);
char	*ft_re_alloc(char *buffer);
int		ft_cheek_fd(int ac, char **av);
char	*ft_re_alloc(char *buffer);
void	draw_mini_map(t_inf *s);
t_map	*ft_load_file_contenent(int ac, char **av);
t_map	*ft_get_line(int fd);
int		ft_util1(t_buff *mem);
int		ft_cheek_tex(char **array, t_buff *mem);
int		cheek_map_char(char **array, int count);
void	ft_free_mlx_texture_t(t_buff *mem);
t_map	*get_ptr(t_map *buffer, int fd);
int		ft_get_tex_pngs(char **buffer, char *s, int *count_tex, char *str);
int		ft_get_color(char **buffer, char *s, int *count_tex, char *str);
int		get_nbr_color(int c, int f);
int		get_nbr_tex(int no, int so, int we, int ea);
int		ft_parse_color(char *s, uint32_t *color);
int		util_walls(char **array, int count, int i);
int		ft_cheeck_walls_util2(char **array, int count, int i);
int		ft_cheeck_walls_util1(char **array, int count, int i);
int		cheek_player_pos(int s, int e, int w, int n);
int		find_map(char **array);
int		cheek_walls(char **array, int count);
int		cheek_map_char(char **array, int count);
int		cheek_map_char_util(char **array, int count, t_mapp *ele);
int		get_tex(t_buff *mem, int count);
int		cheek_per(t_buff *mem);
void	cheek_doors_util(char **array, int i, int count, int *flag);
int		cheek_doors(char **array, int count);
int		get_s(int c1, int c2);
void	my_put_pixel(t_inf *s, int x, int y, int color);
void	draw_line(t_inf *s, t_cordinates c1, t_cordinates c2, uint32_t color);

#endif