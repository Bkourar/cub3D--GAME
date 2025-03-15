#include "Includs/parse_bonus.h"
#include "Includs/raycast_bonus.h"

static int	init_parameter(t_inf *mx, t_buff *mem)
{
	mx->mlx = mlx_init(WIDTH, HIGHT, "cub3D", false);
	mx->im = mlx_new_image(mx->mlx, WIDTH, HIGHT);
	mlx_image_to_window(mx->mlx, mx->im, 0, 0);
	mx->load_i.frame1 = mlx_load_png("Bonus/Images/weapon_1.png");
	mx->load_i.frame2 = mlx_load_png("Bonus/Images/weapon_3.png");
	mx->load_i.door = mlx_load_png("Bonus/Images/7.png");
	if (!mx->load_i.frame1 || !mx->load_i.frame2 || !mx->load_i.door)
		return (ft_error1("Error\nload data\n"), 1);
	mx->load_i.text_n = mem->no_tex;
	mx->load_i.text_s = mem->so_tex;
	mx->load_i.text_w = mem->we_tex;
	mx->load_i.text_e = mem->ea_tex;
	mx->load_i.cillen = mem->cell;
	mx->load_i.floor = mem->floo;
	mx->h_h = mem->array_h * TZ;
	mx->w_w = mem->array_w * TZ;
	mx->pl.p.x = (mem->playerx * TZ) + (TZ / 2);
	mx->pl.p.y = (mem->playery * TZ) + (TZ / 2);
	mx->pl.rot = mem->player_deg;
	mx->sprit_on = false;
	mx->is_door = false;
	mx->text = NULL;
	return (0);
}

static void	destroy_parameter(t_inf mx, t_buff *mem)
{
	(void)mem;
	mlx_terminate(mx.mlx);
	mlx_delete_texture(mx.load_i.frame1);
	mlx_delete_texture(mx.load_i.frame2);
	mlx_delete_texture(mx.load_i.door);
	free_struct(&mx);
}

static void	start_game(t_inf mx, t_buff *mem)
{
	(raycasting(&mx), rendering(&mx));
	mlx_loop_hook(mx.mlx, run, &mx);
	mlx_loop_hook(mx.mlx, rendering, &mx);
	mlx_loop(mx.mlx);
	destroy_parameter(mx, mem);
}

void g()
{
	system("leaks cub3D_bonus");
}

int	main(int ac, char **av)
{
	atexit(g);
	t_inf	mx;
	t_buff *mem;

	mem = ft_parsing(ac, av);
	if (!mem)
		return (1);
	if (get_map_mem(&mx, mem))
		return (1);
	mx.mem = mem;
	get_player_pos(&mx, mem);
	if (init_parameter(&mx, mem) == 1)
		return (free_struct(&mx), 1);
	start_game(mx, mem);
}
