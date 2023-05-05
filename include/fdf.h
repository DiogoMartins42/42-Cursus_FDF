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

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define WIN_WIDTH  1280
# define WIN_HEIGHT 720

typedef struct s_map_alt 
{
	int	value;
	int	color;
}		t_map_alt;

typedef struct s_mlx_map
{
	t_map_alt	**alt;
}	t_mlx_map;

typedef struct s_mlx_img
{
	void	*id;
	char	*buffer;
	int		bpp;
	int		size_line;
	int		endian;
	int		height;
	int		width;
}	t_mlx_img;

typedef struct s_mlx_win
{
	void			*id;
}	t_mlx_win;

typedef struct s_mlx
{
	int			zoom;
	void		*id;
	t_mlx_win	*win;
	t_mlx_img	*img;
	t_mlx_map	**map;
}	t_mlx;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

int		count_x_rows(char *argv);
int		count_y_cols(char *argv, int x);
int		getcolor(t_point *p0, t_point *cur, t_point *p1);
int		draw_map_x(t_mlx *mlx, char *argv, int x, int y);
int		draw_map_y(t_mlx *mlx, char *argv, int x, int y);
int		check_file(char *argv);

void	free_mlx(t_mlx *mlx);
void	create_image(t_mlx *mlx, char *argv);
void	read_map(char *argv, t_mlx *mlx);
void	pix(t_mlx *mlx, int x, int y, int color);
void	draw_line(t_mlx *mlx, t_point *p0, t_point *p1);
void	draw_line_r(t_mlx *mlx, t_point *p0, t_point *p1, t_point *cur);
void	draw_line_rr(t_mlx *mlx, t_point *p0, t_point *p1, t_point *cur);

t_mlx	*generate_t_mlx(char *argv);
t_point	*set_coords(t_mlx *mlx, char *argv, int x0, int y0);

#endif
