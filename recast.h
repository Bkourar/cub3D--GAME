#ifndef RECAST_H
#define RECAST_H

#define PX 60
#define TZ 60
#define FOV 60
//map 2d
// #define WIDTH 480
// #define HIGHT 352
//map 3d
#define WIDTH 1280
#define HIGHT 720
#define BLACK 0x00000FFF
#define WHITE 0xFFFFFFFF
#define BLUE 0x0000BBAA
#define YL 0xFFFF00AA
#define RED 0xFF000000

#include <MLX42/include/MLX42/MLX42.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
typedef struct	s_crd
{
	double	x;
	double	y;
}	t_crd;

typedef struct	plyer
{
	t_crd	p;
	double	rot;
	char	dr_x;
	char	dr_y;
}	t_ply;


typedef struct	s_line
{
	t_crd	start;
	t_crd	end;
}	t_line;

typedef struct	rays
{
	t_crd	r;
	double	rot;
	double	ds;
	char	dr_x;
	char	dr_y;
}	t_rys;

typedef struct	information
{
	float		w_w;
	float		h_h;
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


void	routine(void *arg);
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
void	rendereding(t_inf *s);
void	draw_map_p(t_inf *dr);
// double	hi_section(t_inf *s, t_crd *d);
// double	vi_section(t_inf *s, t_crd *d);
// void	draw_ray(t_inf *d);

# endif