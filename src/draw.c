
#include "../include/fdf.h"

float   mod(float i)
{
    return (i < 0) ? -i : i;
}

void    algory(float x, float y, float x1, float y1)
{
    float   x_math;
    float   y_math;
    int     max;

    x_math = x1 - x;
    y_math = y1 - y;

    max = MAX(MOD(x_math); Mod(y_math));
    x_math /= max;
    y_math /= max;
    while((int)(x -x1) || (int)(y -y1))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x ,y, 0xffffff);
        x += x_math;
        y += y_math;
    }
}