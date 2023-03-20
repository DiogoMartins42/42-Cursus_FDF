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

void	position(fdf *data, int a, t_point *cord)
{
	if (a == 1)
		cord->x1 = cord->x + 1;
	else
		cord->x1 = cord->x;
	if (a == 2)
		cord->y1 = cord->y + 1;
	else
		cord->y1 = cord->y;
	cord->z = data->z_pos[(int)cord->y][(int)cord->x];
	cord->z1 = data->z_pos[(int)cord->y1][(int)cord->x1];
	data->color = (cord->z || cord->z1) ? 0xe80c0c : 0xffffff;
	isometric(cord);
	//isometric(&cord->x1, &cord->y1, cord->z1);
}
void	algory(fdf *data,  int a, t_point *cord)
{
	float	x_math;
	float	y_math;
	int		max;

	position(data, a, cord);
	x_math = cord->x1 - cord->x;
	y_math = cord->y1 - cord->y;
	max = MAX(mod(x_math), mod(y_math));
	x_math /= max;
	y_math /= max;
	while ((int)(cord->x - cord->x1) || (int)(cord->y - cord->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, cord->x, cord->y, data->color);
		cord->x += x_math;
		cord->y += y_math;
	}
}

void	draw(fdf *data)
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
			{
				cord->x = cord->xi;
				cord->y = cord->yi;
				algory(data, 1, cord);
			}
			if (cord->yi < data->height - 1)
			{
				cord->x = cord->xi;
				cord->y = cord->yi;
				algory(data, 2, cord);
			}
			cord->xi++;
		}
		cord->yi++;
	}
}
