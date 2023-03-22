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

float	max_calc(float a, float b)
{
	float	x;
	
	x = 0;
	if (a > b)
		x = a;
	if (b > a)
		x = b;
	return (x);
}

void	position(t_fdf *data, int a, t_point *cord)
{
	if (a == 1)
	{
		cord->x1 = cord->x + 1;
		cord->y1 = cord->y;
	}
	else
		cord->x1 = cord->x;
	if (a == 2)
	{
		cord->y1 = cord->y + 1;
		cord->x1 = cord->x;
	}
	else
		cord->y1 = cord->y;
	cord->z = data->z_pos[(int)cord->y][(int)cord->x];
	cord->z1 = data->z_pos[(int)cord->y1][(int)cord->x1];
	if (cord->z != 0 || cord->z1 != 0)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
	isometric(cord);
}

void	algory(t_fdf *data, int a, t_point *cord)
{
	float	x_math;
	float	y_math;
	int		max;

	cord->x = cord->xi;
	cord->y = cord->yi;
	position(data, a, cord);
	x_math = cord->x1 - cord->x;
	y_math = cord->y1 - cord->y;
	max = max_calc(mod(x_math), mod(y_math));
	x_math /= max;
	y_math /= max;
	while ((int)(cord->x - cord->x1) || (int)(cord->y - cord->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, cord->x,
			cord->y, data->color);
		cord->x += x_math;
		cord->y += y_math;
	}
}

void	draw(t_fdf *data)
{
	t_point	*cord;

	cord = malloc(sizeof(t_point));
	if (!cord)
		exit (1);
	cord->yi = 0;
	while (cord->yi < data->height)
	{
		cord->xi = 0;
		cord->y = cord->yi;
		while (cord->xi < data->width)
		{
			cord->x = cord->xi;
			if (cord->xi < data->width - 1)
				algory(data, 1, cord);
			if (cord->yi < data->height - 1)
				algory(data, 2, cord);
			cord->xi++;
		}
		cord->yi++;
	}
	free(cord);
}
