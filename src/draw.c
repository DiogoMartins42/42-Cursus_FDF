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

void	position(fdf *data)
{
	int		z;
	int		z1;

	z = data->z_pos[(int)data->ypos][(int)data->xpos];
	z1 = data->z_pos[(int)data->ypos1][(int)data->xpos1];
	data->xpos *= data->zoom;
	data->ypos *= data->zoom;
	data->xpos1 *= data->zoom;
	data->ypos1 *= data->zoom;
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	isometric(&data->xpos, &data->ypos, z);
	isometric(&data->xpos1, &data->ypos1, z1);
	data->xpos += 150;
	data->ypos += 150;
	data->xpos1 += 150;
	data->ypos1 += 150;
}
void	algory(fdf *data)
{
	float	x_math;
	float	y_math;
	int		max;

	data->xpos1 = data->xpos + 1;
	position(data);
	x_math = data->xpos1 - data->xpos;
	y_math = data->ypos1 - data->ypos;
	max = MAX(mod(x_math), mod(y_math));
	x_math /= max;
	y_math /= max;
	while ((int)(data->xpos - data->xpos1) || (int)(data->ypos - data->ypos1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->xpos, data->ypos, data->color);
		data->xpos += x_math;
		data->ypos += y_math;
	}
}

void	algory2(fdf *data)
{
	float	x_math;
	float	y_math;
	int		max;

	data->ypos1 = data->ypos + 1;
	position(data);
	x_math = data->xpos1 - data->xpos;
	y_math = data->ypos1 - data->ypos;
	max = MAX(mod(x_math), mod(y_math));
	x_math /= max;
	y_math /= max;
	while ((int)(data->xpos - data->xpos1) || (int)(data->ypos - data->ypos1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->xpos, data->ypos, data->color);
		data->xpos += x_math;
		data->ypos += y_math;
	}
}

void	draw(fdf *data)
{
	fdf	*posdata;
	int		x;
	int		y;
	
	posdata = data;
	y = 0;
	posdata->ypos = 0;
	posdata->zoom = 20;
	while (y < posdata->height)
	{
		x = 0;

		while (x < posdata->width)
		{
			posdata->xpos = x;
			posdata->ypos = y;
			if (x < posdata->width - 1)
				algory(posdata);
			posdata->xpos = x;
			posdata->ypos = y;
			if (y < posdata->height - 1)
			{
				algory2(posdata);
			}
			x++;
		}
		y++;
	}
}
