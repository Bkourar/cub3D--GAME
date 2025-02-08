#ifndef RECAST_H
#define RECAST_H

#define PX 60
#define TZ 60
#define FOV 60
//map 2d
// #define WIDETH 1980
// #define HIGHT 352
//map 3d
#define WIDTH 1280
#define HIGHT 720
#define BLACK 0x00000FFF
#define WHITE 0xFFFFFFFF
#define BLUE 0x0000BBAA
#define YL 0xFFFF00AA
#define RED 0xFF000000
#define IMG "photo.png"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <fcntl.h>
#include "MLX42/include/MLX42/MLX42.h"
#include "get_next_line/get_next_line.h"

typedef struct	s_crd
{
	double	x;
	double	y;
}	t_crd;

typedef struct	plyer
{
	double	rot;
	char	dr_x;
	char	dr_y;
	t_crd	p;
}	t_ply;


typedef struct	s_line
{
	t_crd	start;
	t_crd	end;
}	t_line;

typedef struct	rays
{
	double	rot;
	double	ds;
	char	dr_x;
	char	dr_y;
	bool	sens;
	t_crd	r;
}	t_rys;

// typedef struct	information
// {
// 	float		w_w;
// 	float		h_h;
// 	char		**plan;
// 	void		*wi;
// 	void		*wall;
// 	void		*floor;
// 	void		*plr;
// 	mlx_t		*mlx;
// 	mlx_image_t	*im;
// 	t_ply		pl;
// 	t_rys		ra[WIDTH];
// }				t_inf;


typedef struct	information
{
	float		w_w;
	float		h_h;
	mlx_texture_t *text;
	mlx_image_t	*pic;
	char		**plan;
	void		*wi;
	void		*wall;
	void		*floor;
	void		*plr;
	mlx_t		*mlx;
	mlx_image_t	*im;
	t_ply		pl;
	t_rys		ra[WIDTH];
}				t_inf;

void	draw_ma__p_p(t_inf *dr);
void	rou_tine(void *arg);
double	deg2rad(double deg);
double	rad2deg(double rad);
bool	rot_left(t_inf *s);
bool	rot_right(t_inf *s);
bool	up(t_inf *s);
bool	lt(t_inf *s);
bool	dn(t_inf *s);
bool	rt(t_inf *s);
t_crd	h_ins(t_inf *s,double check, int i);
t_crd	v_ins(t_inf *s,double check, int i);
void	set_distance(t_rys *r, t_crd h, t_crd v, t_ply b);
void	raycasting(t_inf *s);
void	draw_wall(t_inf *d, int x, int y);
void	draw_floor(t_inf *d, int x, int y);
void	draw_player(t_inf *d);
void	direct(double ang, t_rys *orient, t_ply *player);
void	dda(double x0, double y0, double x1, double y1, t_inf *s);
void	rendereding(t_inf *s, int i);
void	draw_map_p(t_inf *dr);
void	draw_line(t_inf *data, t_line ln);
// double	hi_section(t_inf *s, t_crd *d);
// double	vi_section(t_inf *s, t_crd *d);
// void	draw_ray(t_inf *d);
//-------------------------------------------------parsing----------------------------------
typedef struct s_map
{
	char *s;
	char **array;
	int count;
	struct s_map *next;
} t_map;

typedef struct s_buff
{
	char **array;
	int count;
} t_buff;

int ft_strncmp(char *s1, char *s2, int n);
void ft_error(char *str1, char *str2, char *str3);
t_buff *ft_parsing(int ac, char **av);

# endif
