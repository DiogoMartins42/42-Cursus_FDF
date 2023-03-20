/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:23:48 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/02/15 13:23:50 by dmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define MAX(a, b) (a > b ? a : b)
# define MOD(a) ((a < 0) ? -a : a)

typedef struct
{
	int		width;
	int		height;
	int		**z_pos;
	int		zoom;
	int		color;

	void	*mlx_ptr;
	void	*win_ptr;
	
	float	xpos;
	float	ypos;
	float	xpos1;
	float	ypos1;
	
}		fdf;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	float	x1;
	float	y1;
	float	z1;
	float	xi;
	float	yi;
	float	xfinal;
	float	yfinal;
	float	x1final;
	float	y1final;
}		t_point;

float	mod(float i);
void	read_file(char *file, fdf *data);
void	algory(fdf *data,  int a, t_point *cord);
void	draw(fdf *data);
void	isometric(t_point *cord);
void	position(fdf *data, int a, t_point *cord);

#endif
