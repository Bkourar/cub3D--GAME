#include "recast.h"

double	deg2rad(double deg)
{
	return	(deg * (M_PI / 180.0));
}

double	rad2deg(double rad)
{
	return	(rad * 180.0 / M_PI);
}

void dda(double x0, double y0, double x1, double y1, t_inf *s) {
    // Calculate differences
    double dx = x1 - x0;
    double dy = y1 - y0;

    // Calculate number of steps required for drawing the line
    double steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
    
    // Calculate increment values for each step
   double X_increment = dx / (float)steps;
   double Y_increment = dy / (float)steps;

    // Starting podouble
   double x = x0;
   double y = y0;

    // Plot the line
    for (int i = 0; i <= steps; i++) {
		mlx_put_pixel(s->im, x, y, (uint32_t)YL);
        // putpixel(round(x), round(y), WHITE);  // Using putpixel to plot points
        x += X_increment;
        y += Y_increment;
    }
}