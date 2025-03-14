#ifndef PARSE_BONUS_H
#define PARSE_BONUS_H

# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <math.h>
# include <fcntl.h>
# include "../../MLX42/include/MLX42/MLX42.h"
# include "../Parse/get_next_line/get_next_line.h"
# include "raycast_bonus.h"
#define scal 0.25
typedef struct s_cordinates
{
	int	x;
	int	y;
}	t_cordinates;


typedef struct s_utils
{
	double	top_x;
	double	top_y;
	double	left_x;
	double	left_y;
	double	right_x;
	double	right_y;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}	t_utils;

typedef struct	s_map
{
	char			*s;
	char			*tmp;
	int				count;
	struct s_map	*next;
}					t_map;

typedef struct	s_buff
{
	char			**array;
	int				count;
	int				array_w;
	int				array_h;
	int				no[2];
	int				so[2];
	int				we[2];
	int				ea[2];
	int				c[2];
	int				f[2];
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	char			*celling;
	char 			*floor_c;
	uint32_t		cell;
	uint32_t		floo;
	mlx_texture_t	*no_tex;
	mlx_texture_t	*so_tex;
	mlx_texture_t	*we_tex;
	mlx_texture_t	*ea_tex;
	int				playerX;
	int				playerY;
	double			player_deg;

}					t_buff;

int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strlen_m(char *s, char c);
char	*ft_strjoin_m(char *s1, int add);
void	ft_error(char *str1, char *str2, char *str3);
char	*ft_strdup_p(char *s);
char	*ft_strdup_1(char *s, t_buff *mem);
void	get_player_pos(t_inf *mx, t_buff *inf);
int		get_map_mem(t_inf *mx, t_buff *mem);
void	ft_free(t_buff *mem);
void	ft_free_list (t_map *tmp);
void	ft_free_textures(t_buff *mem);
t_buff	*ft_parsing(int ac, char **av);
char	*ft_skip_spaces(char *s);
char	*ft_re_alloc(char *buffer);
int		ft_cheek_fd(int ac , char **av);
char	*ft_re_alloc(char *buffer);
void	draw_mini_map(t_inf *s);


#endif