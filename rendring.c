#include "recast.h"

void	rendereding(t_inf *s)
{
	double	ds_h;
	double	y_h;
	double	celling;
	double	angl;
	int		i;
	int 	j;
	int k;

	i = 0;
	angl = tan(deg2rad(FOV / 2));
	mlx_texture_t  *texture= mlx_load_png("bricks.png");
	// mlx_image_t *img = mlx_texture_to_image(s->mlx, texture);


	uint8_t r = 0;
	uint8_t g = 0;
	uint8_t b = 0;
	uint8_t a = 0;
	uint32_t color = 0;
	int pixel_index = 0;
	while (i < WIDTH)
	{
		j = 0;
		ds_h = (WIDTH / 2) / angl;
		y_h = (PX / s->ra[i].ds) * ds_h;
		celling = (HIGHT / 2) - (y_h / 2);
		while (celling > 0)
		{
			mlx_put_pixel(s->im, i, j++, (uint32_t)BLUE);
			celling--;
		}
		int l = 0;
		int in_x;
		if (s->ra[i].dr_y == 'D')
			in_x = s->ra[i].r.x;
		else
			in_x = s->ra[i].r.y;;
 		int	offx = y_h;
		// int offy =  j * texture->height / y_h;
		int k;
		while (l < y_h && j < HIGHT)
		{
			k = ((offx - l) % (int)((double)PX / y_h));
			pixel_index = (j * texture->width + i) * 4;
			r = texture->pixels[pixel_index];
			g = texture->pixels[pixel_index + 1];
			b = texture->pixels[pixel_index + 2];
			a = texture->pixels[pixel_index + 3];
			color = (r << 24) | (g << 16) | (b << 8) | a;
			mlx_put_pixel(s->im, i, j, color);
				mlx_put_pixel(s->im, k, in_x, (uint32_t)YL);
			l++;
			j++;
		}
		while (j < HIGHT)
			mlx_put_pixel(s->im, i, j++, (uint32_t)WHITE);
		i++;
	}
    // mlx_delete_image(s->mlx, img);
    mlx_delete_texture(texture);
}