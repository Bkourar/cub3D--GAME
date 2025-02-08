#include "recast.h"
#include <string.h>

static	void	start_game(t_inf mx)
{
	mx.text = mlx_load_png("door (1).png");
	mx.pic = mlx_texture_to_image(mx.mlx, mx.text);
	mlx_image_to_window(mx.mlx, mx.im, 0, 0);
	raycasting(&mx);
	rendereding(&mx, 0);
	// draw_ma__p_p(&mx);
	// t_line l;
	// l.start.x = mx.pl.p.x;
	// l.start.y = mx.pl.p.y;
	// l.end.x = mx.pl.p.x + 20 * cos(mx.pl.rot);
	// l.end.y = mx.pl.p.y + 20 * sin(mx.pl.rot);
	// draw_line(&mx, l);
	mlx_loop_hook(mx.mlx, rou_tine, &mx);
	mlx_loop(mx.mlx);
	for (int i = 0; i < 12; i++)
		free(*(mx.plan + i));
	free(mx.plan);
}

void fe()
{
	system("leaks cub3D");
}



int main(int ac, char **av)
{
	// atexit(fe);
	t_inf	mx;
	int i;
	t_buff *mem;

	i = 0;
	mem = ft_parsing(ac, av);
	if (!mem)
		return (1);
	mx.plan = (char **)malloc(sizeof(char *) * (mem->count + 1));
	if (!mx.plan)
		return (1);
	// return (1);
	while (mem->array[i] != NULL)
	{
		*(mx.plan + i) = ft_strdup(mem->array[i]);
		free (mem->array[i]);
		i++;
	}
	free(mem);
	*(mx.plan + i) = NULL;

	mx.h_h = 12 * PX;
	mx.w_w = 33 * PX;

	// mx.pl.p.x = (7 * TZ) + (TZ / 2);
	// mx.pl.p.y = (3 * TZ) + (TZ / 2);
	mx.pl.p.x = (14 * TZ) + (TZ / 2);
	mx.pl.p.y = (2 * TZ) + (TZ / 2);
	mx.pl.rot = deg2rad(0);
	mx.mlx = mlx_init(WIDTH, HIGHT, "cub3D", false);
	mx.im = mlx_new_image(mx.mlx, WIDTH, HIGHT);
	// mlx_image_to_window(mx.mlx, mx.im, 0, 0);

	start_game(mx);
}
