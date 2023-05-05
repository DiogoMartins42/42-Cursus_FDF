/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:58:11 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/03/14 10:58:15 by dmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	draw_line_r(t_mlx *mlx, t_point *p0, t_point *p1, t_point *cur)
{
	double	s;
	double	step;

	s = (float)(p1->y - p0->y) / (float)(p1->x - p0->x);
	step = p1->y - s * p1->x;
	*cur = *p0;
	if (p0->x <= p1->x)
	{
		while (cur->x <= p1->x)
		{
			pix(mlx, cur->x, round(s * cur->x + step), getcolor(p0, cur, p1));
			cur->x++;
		}
	}
	else if (p0->x > p1->x)
	{
		while (cur->x >= p1->x)
		{
			pix(mlx, cur->x, round(s * cur->x + step), getcolor(p0, cur, p1));
			cur->x--;
		}
	}
}

void	draw_line_rr(t_mlx *mlx, t_point *p0, t_point *p1, t_point *cur)
{
	double	s;
	double	step;

	s = (float)(p1->y - p0->y) / (float)(p1->x - p0->x);
	step = p1->y - s * p1->x;
	*cur = *p0;
	if (p0->y <= p1->y)
	{
		while (cur->y <= p1->y)
		{
			pix(mlx, round((cur->y - step) / s), cur->y, getcolor(p0, cur, p1));
			cur->y++;
		}
	}
	else if (p0->y > p1->y)
	{
		while (cur->y >= p1->y)
		{
			pix(mlx, round((cur->y - step) / s), cur->y, getcolor(p0, cur, p1));
			cur->y--;
		}
	}
}

int	draw_map_x(t_mlx *mlx, char *argv, int y, int x)
{
	t_point	*p0;
	t_point	*p1;

	while (mlx->map[y]->alt[x])
	{
		if (y > 0)
		{
			p0 = set_coords(mlx, argv, y - 1, x);
			p1 = set_coords(mlx, argv, y, x);
			draw_line(mlx, p0, p1);
			free(p0);
			p0 = 0;
			free(p1);
			p1 = 0;
		}
		x++;
	}
	while (--x)
		draw_map_y(mlx, argv, y, x);
	return (0);
}

int	draw_map_y(t_mlx *mlx, char *argv, int y, int x)
{
	t_point	*p0;
	t_point	*p1;

	p0 = set_coords(mlx, argv, y, x - 1);
	p1 = set_coords(mlx, argv, y, x);
	draw_line(mlx, p0, p1);
	free(p0);
	p0 = 0;
	free(p1);
	p1 = 0;
	return (0);
}
