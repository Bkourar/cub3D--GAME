#include "Includs/raycast_bonus.h"

int	checking(double x, double y, t_inf *s)
{
	double	check[5][2];
	int		i;
	
	check[0][0] = x;
	check[0][1] = y; 
	check[1][0] = x + 1; 
	check[1][1] = y;
	check[2][0] = x - 1;
	check[2][1] = y;
	check[3][0] = x; 
	check[3][1] = y + 1;
	check[4][0] = x;
	check[4][1] = y - 1;
	i = 0;
	while (i < 5)
	{
		if (s->plan[(int)(check[i][1] / TZ)][(int)(check[i][0] / TZ)] == '1')
			return (1);
		i++;
	}
	return (0);
}


t_maping	gtd_ver(double ang)
{
	if (M_PI_2 < ang && ang < 3 * M_PI_2)
		return (WEST);
	else
		return (EAST);
}

t_maping	gtd_hor(double ang)
{
	if (ang > M_PI && ang < (2 * M_PI))
		return (NORTH);
	else
		return (SOUTH);
}

