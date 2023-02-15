/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tutorial.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:42:32 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/01/20 11:43:33 by dmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
}	t_data;

t_data  *generate_t_data()
{
    t_data  *data;
    data = malloc(sizeof(t_data));
    if (!data)
        return(0);
    data->mlx = 0;
    data->win = 0;
    return (data);
}

int	draw_line(t_data *data, int beginX, int beginY, int endX, int endY, int color)
{
	double	deltaX = endX - beginX; // 10
	double	deltaY = endY - beginY; // 0
	int 	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	
	//  pixels = sqrt((10 * 10) + (0 * 0)) = sqrt(100) = 10
	deltaX /= pixels; // 1
	deltaY /= pixels; // 0
	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
    		mlx_pixel_put(data->mlx, data->win, pixelX, pixelY, color);
    		pixelX += deltaX;
   		pixelY += deltaY;
    		--pixels;
	}
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->win);
	return (0);
}

static int	close_win(void)
{
	exit(0);
	return (0);
}

int	main()
{
	t_data *data;

	data = generate_t_data();
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 640, 360, "Tutorial Window");
	draw_line(data, 640, 360, 0, 0, 0xFFFFFF);
	mlx_hook(data->win, 17, 1L << 17, close_win, NULL);
	mlx_key_hook(data->win, &handle_input, &data);
	mlx_loop(data->mlx);
}
