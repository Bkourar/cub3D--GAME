#include "Includs/parse.h"
#include "Includs/raycast.h"

static void	init_parameter(t_inf *mx, t_buff *mem, int x, int y)
{
	mx->load_i.text_n = mem->no_tex;
	mx->load_i.text_s = mem->so_tex;
	mx->load_i.text_w = mem->we_tex;
	mx->load_i.text_e = mem->ea_tex;
	mx->load_i.cillen = mem->cell;
	mx->load_i.floor = mem->floo;
	mx->h_h = mem->array_h * PX;
	mx->w_w = mem->array_w * PX;
	mx->pl.p.x = (x * TZ) + (TZ / 2);
	mx->pl.p.y = (y * TZ) + (TZ / 2);
	mx->mlx = mlx_init(WIDTH, HIGHT, "cub3D", false);
	mx->im = mlx_new_image(mx->mlx, WIDTH, HIGHT);
	mlx_image_to_window(mx->mlx, mx->im, 0, 0);
}

// static void	destroy_parameter(t_inf mx, t_buff *mem)
// {
// 	int	i;
// 	(void)mem;

// 	i = -1;
// 	while (++i < mx.w_w)
// 		free(*(mx.plan + i));
// 	free(mx.plan);
// }

// static void	start_game(t_inf mx, t_buff *mem)
// {
// 	(raycasting(&mx), rendering(&mx, 0));
// 	mlx_loop_hook(mx.mlx, run, &mx);
// 	mlx_loop(mx.mlx);
// 	destroy_parameter(mx, mem);
// }

// void fe()
// {
// 	system("leaks cub3D");
// }

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
	init_parameter(&mx, mem, mx.pl.p.x, mx.pl.p.y);
	printf("%d\n",mem->array_h);
	printf("%d\n",mem->array_w);
	for (int i = 0; i < mem->array_w; i++)
	{
		puts(mx.plan[i]);
	}
	// start_game(mx, mem);
}
