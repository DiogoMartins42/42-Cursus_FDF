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

typedef struct s_fdf
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

}		t_fdf;

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
}		t_point;

float	mod(float i);
void	read_file(char *file, t_fdf *data);
void	algory(t_fdf *data, int a, t_point *cord);
void	draw(t_fdf *data);
void	isometric(t_point *cord);
void	position(t_fdf *data, int a, t_point *cord);

#endif
