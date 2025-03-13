#include "../Includs/raycast_bonus.h"
#include "../Includs/parse_bonus.h"

bool	rot_right(t_inf *s)
{
	s->pl.rot += deg2rad(2);
	if (s->pl.rot >= 2 * M_PI)
		s->pl.rot = 0;
	return (true);
}

bool	rot_left(t_inf *s)
{
	s->pl.rot -= deg2rad(2);
	if (s->pl.rot < 0)
		s->pl.rot = 2 * M_PI;
	return (true);
}

static void moveing(t_inf *s, bool mv)
{
    static int32_t last_mouse_x = -1;
    int32_t mouse_x;
    int32_t mouse_y;
    int mouse_delta;

    mlx_set_cursor_mode(s->mlx, MLX_MOUSE_HIDDEN);
    mlx_get_mouse_pos(s->mlx, &mouse_x, &mouse_y);
    
    if (last_mouse_x != -1)
    {
        mouse_delta = mouse_x - last_mouse_x;
        if (mouse_delta > 5)
            mv = rot_right(s);
        else if (mouse_delta < -5)
            mv = rot_left(s);
    }
    
    last_mouse_x = mouse_x;
    
    if (mouse_x < 100 || mouse_x > s->wid - 100)
    {
        mlx_set_mouse_pos(s->mlx, s->wid / 2, mouse_y);
        last_mouse_x = s->wid / 2;
    }
    
    if (mlx_is_key_down(s->mlx, MLX_KEY_RIGHT) || mlx_is_mouse_down(s->mlx, MLX_MOUSE_BUTTON_RIGHT))
        mv = rot_right(s);
    if (mlx_is_key_down(s->mlx, MLX_KEY_LEFT) || mlx_is_mouse_down(s->mlx, MLX_MOUSE_BUTTON_LEFT))
        mv = rot_left(s);
    if (mlx_is_key_down(s->mlx, MLX_KEY_W))
        mv = up(s);
    if (mlx_is_key_down(s->mlx, MLX_KEY_D))
        mv = right(s);
    if (mlx_is_key_down(s->mlx, MLX_KEY_S))
        mv = down(s);
    if (mlx_is_key_down(s->mlx, MLX_KEY_A))
        mv = left(s);
    
	s->sprit_on = false;
    if (mlx_is_key_down(s->mlx, MLX_KEY_SPACE) && s->sprit_on == false)
        s->sprit_on = true;
    else if (mlx_is_key_down(s->mlx, MLX_KEY_SPACE) && s->sprit_on == true)
    {
        s->sprit_on = false;
        usleep(2500);
    }
    if (mlx_is_key_down(s->mlx, MLX_KEY_ESCAPE))
        exit(1);
    if (mv || s->sprit_on || !s->sprit_on)
        raycasting(s);
}

void	run(void *arg)
{
	t_inf	*s;
	s = (t_inf *)arg;
	moveing(s, false);
	usleep(1000);
}