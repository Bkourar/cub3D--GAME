#include "recast.h"

void	direct(double ang, t_rys *orient, t_ply *player)
{
	if (orient != NULL)
	{
		if ((M_PI / 2) < ang && ang < (M_PI + (M_PI / 2)))
			orient->dr_x = 'L';
		else
			orient->dr_x = 'R';
		if (M_PI < ang && ang < (2 * M_PI))
			orient->dr_y = 'U';
		else
			orient->dr_y = 'D';
	}
	else if (player != NULL)
	{
		if ((M_PI / 2) < ang && ang < (M_PI + (M_PI / 2)))
			player->dr_x = 'L';
		else
			player->dr_x = 'R';
		if (M_PI < ang && ang < (2 * M_PI))
			player->dr_y = 'U';
		else
			player->dr_y = 'D';
	}

}


double	norm_ray(double ang)
{
	ang = fmod(ang, 2 * M_PI);
	if (ang < 0)
		ang += 2 * M_PI;
	return (ang);

}

void	raycasting(t_inf *s)
{
	double	i;
	double	k;
	t_crd	cr_h;
	t_crd	cr_v;

	int		j;

	j = 0;
	i = (deg2rad(FOV) / WIDTH);
	k = s->pl.rot - deg2rad(30);
	while (j < WIDTH)
	{
		s->ra[j].rot = norm_ray(k);
		direct(s->ra[j].rot, &s->ra[j], NULL);
		cr_h = h_ins(s, 0, j);
		cr_v = v_ins(s, 0, j);
		set_distance(&s->ra[j], cr_h, cr_v, s->pl);
		k += i;
		j++;
	}
}

// void	draw_wa(t_inf *d, int x, int y)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	while (j < PX)
// 	{
// 		i = 0;
// 		while (i < PX)
// 		{
// 			// if (i + x * PX < 0 || j + y * PX < 0 || i + x * PX >  d->x || j + y * PX > d->y)
// 			// 	return ;
// 			mlx_put_pixel(d->im, i + x * PX, j + y * PX, (uint32_t)BLACK);
// 			i++;
// 		}
// 		j++;
// 	}
// }

// void	draw_fl(t_inf *d, int x, int y)
// {
// 	int	i;
// 	int	j;

// 	if (x < 0 || y < 0 || x > d->w_w || y > d->h_h)
// 		return ;
// 	j = 0;
// 	while (j < PX)
// 	{
// 		i = 0;
// 		while (i < PX)
// 		{
// 			// if (i + x * PX < 0 || j + y * PX < 0 || i + x * PX >  d->x || j + y * PX > d->y)
// 			// 	return ;
// 			mlx_put_pixel(d->im, i + x * PX, j + y * PX, (uint32_t)WHITE);
// 			i++;
// 		}
// 		j++;
// 	}
// }

// void	draw_ma__p_p(t_inf *dr)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (dr->plan[++i])
// 	{
// 		j = 0;
// 		while (dr->plan[i][j])
// 		{
// 			if (dr->plan[i][j] == '1')
// 				draw_wa(dr, j, i);
// 			else
// 				draw_fl(dr, j, i);
// 			j++;
// 		}
// 	}
// }

static void moveing(t_inf *s)
{
    bool mv = false;
    static int32_t last_mouse_x = -1;
    int32_t mouse_x, mouse_y;
	mlx_set_cursor_mode(s->mlx, MLX_MOUSE_HIDDEN);
    mlx_get_mouse_pos(s->mlx, &mouse_x, &mouse_y);
    if (last_mouse_x != -1)
    {
        int mouse_delta = mouse_x - last_mouse_x;
        if (mouse_delta > 5)
        {
            mv = rot_right(s);
        }
        else if (mouse_delta < -5)
        {
            mv = rot_left(s);
        }
    }
    last_mouse_x = mouse_x;
    if (mlx_is_key_down(s->mlx, MLX_KEY_RIGHT) || mlx_is_mouse_down(s->mlx, MLX_MOUSE_BUTTON_RIGHT))
        mv = rot_right(s);
    if (mlx_is_key_down(s->mlx, MLX_KEY_LEFT) || mlx_is_mouse_down(s->mlx, MLX_MOUSE_BUTTON_LEFT))
        mv = rot_left(s);
    if (mlx_is_key_down(s->mlx, MLX_KEY_W))
        mv = up(s);
    if (mlx_is_key_down(s->mlx, MLX_KEY_D))
        mv = rt(s);
    if (mlx_is_key_down(s->mlx, MLX_KEY_S))
        mv = dn(s);
    if (mlx_is_key_down(s->mlx, MLX_KEY_A))
        mv = lt(s);
    if (mlx_is_key_down(s->mlx, MLX_KEY_ESCAPE))
        exit(1);
    
	s->wid = 0;
    if (mouse_x < 100 || mouse_x > s->wid - 100)
    {
        mlx_set_mouse_pos(s->mlx, s->wid / 2, mouse_y);
        last_mouse_x = s->wid / 2;
    }
    
    if (mv)
    {
        raycasting(s);
        rendereding(s, 0);
    }
}

void	rou_tine(void *arg)
{
	t_inf	*s;
	s = (t_inf *)arg;
	moveing(s);
}
