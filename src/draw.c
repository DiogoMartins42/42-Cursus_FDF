/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:39:19 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/02/23 10:39:25 by dmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

float	mod(float i)
{
	if (i < 0)
		i = -i;
	return (i);
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	algory(float x, float y, float x1, float y1, fdf *data)
{
	float	x_math;
	float	y_math;
	int		max;
	int		z;
	int		z1;

	z = data->z_pos[(int)y][(int)x];
	z1 = data->z_pos[(int)y1][(int)x1];
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	x += 150;
	y += 150;
	x1 += 150;
	y1 += 150;
	x_math = x1 - x;
	y_math = y1 - y;
	max = MAX(mod(x_math), mod(y_math));
	x_math /= max;
	y_math /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_math;
		y += y_math;
	}
}

void	draw(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	data->zoom = 20;
	while (y < data ->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				algory(x, y, x + 1, y, data);
			if (y < data->height - 1)
				algory(x, y, x, y + 1, data);
			x++;
		}
	y++;
	}
}
