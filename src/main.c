/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:13:01 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/02/16 11:13:02 by dmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

static void	free_z(int **z)
{
	int	i;

	i = 0;
	while (z[i])
	{
		free(z[i]);
		i++;
	}
	free(z);
}

static void	clear_win(t_fdf *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data);
}

static int	close_win(int keycode, void *param)
{
	if (keycode == 65307 || (int *)param == (int *)347)
	{
		//clear_win(data);
		exit(0);
	}
	return (0);
}

static int	handle_input(int keysym, t_fdf *data)
{
	if (keysym == XK_Escape)
	{	
		free_z(data->z_pos);
		clear_win(data);
		exit (0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	(void) argc;
	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	data->zoom = 5;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	draw(data);
	mlx_key_hook(data->win_ptr, &handle_input, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, close_win, NULL);
	mlx_loop(data->mlx_ptr);
	free_z(data->z_pos);
	clear_win(data);
}
