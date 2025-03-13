#include "Includs/parse_bonus.h"
#include "Includs/raycast_bonus.h"

static void	init_parameter(t_inf *mx, t_buff *mem)
{
	mx->mlx = mlx_init(WIDTH, HIGHT, "cub3D", false);
	mx->im = mlx_new_image(mx->mlx, WIDTH, HIGHT);
	mlx_image_to_window(mx->mlx, mx->im, 0, 0);
	mx->load_i.frame1 = mlx_load_png("Bonus/Images/weapon_1.png");
	mx->load_i.frame2 = mlx_load_png("Bonus/Images/weapon_3.png");
	if (!mx->load_i.frame1 || !mx->load_i.frame2)
		puts("falied"), exit(1);
	mx->load_i.text_n = mem->no_tex;
	mx->load_i.text_s = mem->so_tex;
	mx->load_i.text_w = mem->we_tex;
	mx->load_i.text_e = mem->ea_tex;
	mx->load_i.cillen = mem->cell;
	mx->load_i.floor = mem->floo;
	mx->h_h = mem->array_h * TZ;
	mx->w_w = mem->array_w * TZ;
	mx->pl.p.x = (mem->playerX * TZ) + (TZ / 2);
	mx->pl.p.y = (mem->playerY * TZ) + (TZ / 2);
	mx->pl.rot = mem->player_deg;
	mx->sprit_on = false;
	mx->text = NULL;
}

static void	destroy_parameter(t_inf mx, t_buff *mem)
{
	int	i;
	(void)mem;

	i = -1;
	while (++i < mx.h_h / TZ)
		free(*(mx.plan + i));
	free(mx.plan);
}

static void	start_game(t_inf mx, t_buff *mem)
{
	(raycasting(&mx), rendering(&mx));
	mlx_loop_hook(mx.mlx, run, &mx);
	mlx_loop_hook(mx.mlx, rendering, &mx);
	mlx_loop(mx.mlx);
	destroy_parameter(mx, mem);
}

int	main(int ac, char **av)
{
	t_inf	mx;
	t_buff *mem;

	mem = ft_parsing(ac, av);
	if (!mem)
		return (1);
	if (get_map_mem(&mx, mem))
		return (1);
	get_player_pos(&mx, mem);
	init_parameter(&mx, mem);
	start_game(mx, mem);
}
