#include "recast.h"
#include <string.h>


void fe()
{
	system("leaks cub3D");
}


static	void	start_game(t_inf mx, t_buff *mem)
{
	(void)mem;
	mx.text = mx.no_tex;
	mx.pic = mlx_texture_to_image(mx.mlx, mx.text);
	mlx_image_to_window(mx.mlx, mx.im, 0, 0);
	raycasting(&mx);
	rendereding(&mx, 0);
	mlx_loop_hook(mx.mlx, rou_tine, &mx);
	mlx_loop(mx.mlx);
	for (int i = 0; i < 14; i++)
		free(*(mx.plan + i));
	free(mx.plan);
}

int main(int ac, char **av)
{
	// atexit(fe);
	t_inf	mx;
	t_buff *mem;

	mem = ft_parsing(ac, av);
	if (!mem)
		return (1);
	if (get_map_mem(&mx, mem))
		return (1);
	get_player_pos(&mx);

	mx.mem_hight = mem->array_h;
	mx.mem_width = mem->array_w;
	mx.h_h = mem->array_h * PX;
	mx.w_w = mem->array_w * PX;


	mx.pl.p.x = (mx.pl.dr_x * TZ) + (TZ / 2);
	mx.pl.p.y = (mx.pl.dr_y * TZ) + (TZ / 2);

	mx.pl.rot = deg2rad(mx.player_deg);

	mx.mlx = mlx_init(WIDTH, HIGHT, "cub3D", false);
	mx.im = mlx_new_image(mx.mlx, WIDTH, HIGHT);

	mx.no_tex = mem->no_tex;
	mx.ea_tex = mem->ea_tex;
	mx.so_tex = mem->so_tex;
	mx.we_tex = mem->we_tex;
	mx.cell = mem->cell;
	mx.floo = mem->floo;
	start_game(mx, mem);
}
