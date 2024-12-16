#include "recast.h"
#include <string.h>

static	void	start_game(t_inf mx)
{
	mlx_image_to_window(mx.mlx, mx.im, 0, 0);
	raycasting(&mx);
	rendereding(&mx);
	mlx_loop_hook(mx.mlx, routine, &mx);
	mlx_loop(mx.mlx);
	for (int i = 0; i < 12; i++)
		free(*(mx.plan + i));
	free(mx.plan);
}

int main()
{
	t_inf	mx;
	mx.plan = (char **)malloc(sizeof(char *) * 12);
	if (!mx.plan)
		return (1);
	*(mx.plan)      =  strdup("1111111111111111111");
	*(mx.plan + 1)  =  strdup("1000000000001000001");
	*(mx.plan + 2)  =  strdup("1010010000001000001");
	*(mx.plan + 3)  =  strdup("1111000S00101000001");
	*(mx.plan + 4)  =  strdup("1000000000101000001");
	*(mx.plan + 5)  =  strdup("1000000011111000001");
	*(mx.plan + 6)  =  strdup("1000000000000000001");
	*(mx.plan + 7)  =  strdup("1000000000000000001");
	*(mx.plan + 8)  =  strdup("1111110001111000001");
	*(mx.plan + 9)  =  strdup("1000000000000000001");
	*(mx.plan + 10) =  strdup("1111111111111111111");
	*(mx.plan + 11) =  0;
	mx.h_h = 11 * PX;
	mx.w_w = 20 * PX;
	mx.mlx = mlx_init(WIDTH, HIGHT, "Win", false);
	mx.im = mlx_new_image(mx.mlx, WIDTH, HIGHT);
	mx.pl.p.x = (7 * TZ) + (TZ / 2);
	mx.pl.p.y = (3 * TZ) + (TZ / 2);
	mx.pl.rot = deg2rad(270);
	start_game(mx);
}
