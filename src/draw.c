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

t_point	position(fdf *data, int a, t_point cord)
{
	if (a == 1)
		x1 = x + 1;
	else
		x1 = x;
	if (a == 2)
		y1 = y + 1;
	else
		y1 = y;
	z = data->z_pos[(int)y][(int)x];
	z1 = data->z_pos[(int)y1][(int)x1];
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	return (cord)
}
void	algory(fdf *data,  int a, t_point *cord)
{
	float	x_math;
	float	y_math;
	int		max;

	position(data, a, cord);
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
	t_point	cord;
	
	cord = malloc(sizeof(t_point));
	if (!cord)
		exit (1);
	cord->yi = -1;
	while (cord->yi++ < data->height)
	{
		cord->xi = -1;
		cord->y = cord->yi;
		while (cord->xi++ < data->width)
		{
			cord->x = cord->xi;
			if (cord->xi < data->width - 1)
				algory(data, 1, cord);
			if (y < data->height - 1)
				algory(data, 2, cord);
		}
	}
}
