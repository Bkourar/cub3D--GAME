#ifndef RECAST_H
#define RECAST_H

#define PX 32
#define BLACK 0x00000FFF
#define WHITE 0xFFFFFFFF
// #define BLUE 0x0000BBAA
#define BLUE 0x00FF0000
#define YL 0xFFFF00AA
#define RED 0x000000FF
#define GREAN 0x0000FF00

#include <MLX42/include/MLX42/MLX42.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct	coordition
{
	float	p_x;
	float	p_y;
	double	rot;
}	t_cor;

typedef struct	s_crd
{
	double	x;
	double	y;
}	t_crd;

typedef struct	s_line
{
	t_crd	start;
	t_crd	end;
}	t_line;

typedef struct	s_angle
{
	t_crd	dirction;
	t_crd	intrsection;
	t_crd	angle;
}			t_ang;

typedef struct	information
{
	float		x;
	float		y;
	char		**plan;
	mlx_t		*mlx;
	void		*wi;
	void		*wall;
	void		*floor;
	void		*plr;
	mlx_image_t	*im;
	t_cor		info;
	t_ang		set;
}				t_inf;

double	deg2rad(double deg);
double	rad2deg(double rad);
void	routine(void *arg);
void	draw_floor(t_inf *d, int x, int y);
void	draw_line(t_inf *data, t_line ln);
void	draw_wall(t_inf *d, int x, int y);
void	draw_floor(t_inf *d, int x, int y);
void	draw_player(t_inf *d);
double	hi_section(t_inf *s, t_crd *d);
double	vi_section(t_inf *s, t_crd *d);
// void	draw_ray(t_inf *d);

# endif