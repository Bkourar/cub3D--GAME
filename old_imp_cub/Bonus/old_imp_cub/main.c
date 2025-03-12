#include "recast.h"
#include <string.h>

int main()
{
	t_inf	mx;
	mx.plan = (char **)malloc(sizeof(char *) * 12);
	if (!mx.plan)
		return (1);
	*(mx.plan) = strdup("111111111111111");
	*(mx.plan + 1) = strdup("100000000000101");
	*(mx.plan + 2) = strdup("101001000000101");
	*(mx.plan + 3) = strdup("1111000S0010101");
	*(mx.plan + 4) = strdup("100000000010101");
	*(mx.plan + 5) = strdup("100000001111101");
	*(mx.plan + 6) = strdup("100000000000001");
	*(mx.plan + 7) = strdup("100000000000001");
	*(mx.plan + 8) = strdup("111111000111101");
	*(mx.plan + 9) = strdup("100000000000001");
	*(mx.plan + 10) = strdup("111111111111111");
	*(mx.plan + 11) = 0;
	// for (int i = 0; i < 11; i++)
	// 	for (int j = 0; j < 15; j++)
	// 		if (mx.plan[i][j] == 'S')
	// 			printf("%d--%d\n", i, j);
	// exit(1);
	mx.x = (15 * PX);
	mx.y = (11 * PX);
	mx.mlx = mlx_init(mx.x, mx.y, "Win", false);
	mx.im = mlx_new_image(mx.mlx, mx.x, mx.y);
	mx.info.p_x = (7 * PX) + 16;
	mx.info.p_y = (3 * PX) + 16;
	mx.info.rot = deg2rad(270);
	// printf("%f---\n", mx.info.p_y);
	// exit(1);
	mlx_image_to_window(mx.mlx, mx.im, 0, 0);
	mlx_loop_hook(mx.mlx, routine, &mx);
	// mlx_key_hook(mx.mlx, routine, &mx);
	mlx_loop(mx.mlx);
	for (int i = 0; i < 12; i++)
		free(*(mx.plan + i));
	free(mx.plan);
}