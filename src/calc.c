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

float	mod(float i)
{
	if (i < 0)
		i = -i;
	return (i);
}

void	isometric(t_point *cord)
{
	cord->x *= 15;
	cord->x1 *= 15;
	cord->y *= 15;
	cord->y1 *= 15;
	cord->x = (cord->x - cord->y) * cos(0.8);
	cord->y = (cord->x + cord->y) * sin(0.8) - cord->z;
	cord->x1 = (cord->x1 - cord->y1) * cos(0.8);
	cord->y1 = (cord->x1 - cord->y1) * sin(0.8) - cord->z1;
	cord->x += 150;
	cord->x1 += 150;
	cord->y += 150;
	cord->y1 += 150;
}
