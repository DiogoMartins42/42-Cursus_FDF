/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:13:01 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/05/06 10:11:23 by dmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	clear_mlx(t_mlx	*mlx)
{
	int	i;

	i = 0;
	mlx_destroy_image(mlx->id, mlx->img->id);
	mlx_destroy_window(mlx->id, mlx->win->id);
	mlx_destroy_display(mlx->id);
	while (mlx->map[i])
	{
		free_mlxmap(mlx->map[i]);
		i++;
	}
	free (mlx->map);
	free_mlx(mlx);
}

static int	handle_input(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
	{
		clear_mlx(mlx);
		exit (0);
	}
	return (0);
}

static int	close_win(t_mlx *mlx)
{
	clear_mlx(mlx);
	exit(0);
	return (0);
}

static void	create_window(t_mlx *mlx)
{
	t_mlx_win	*win;

	win = mlx->win;
	win->id = mlx_new_window(mlx->id, WIN_WIDTH, WIN_HEIGHT, "FDF");
	mlx_hook(win->id, 17, 1L << 17, close_win, mlx);
	mlx_key_hook(win->id, &handle_input, mlx);
}

int	main(int argc, char **argv)
{
	char		*file_ext;
	t_mlx		*mlx;

	if (argc == 2)
	{
		file_ext = ft_strchr(argv[1], '.');
		if (!ft_strncmp(file_ext, ".fdf", ft_strlen(file_ext)) \
			&& check_file(argv[1]) == 0)
		{
			mlx = generate_t_mlx(argv[1]);
			read_map(argv[1], mlx);
			mlx->id = mlx_init();
			create_window(mlx);
			create_image(mlx, argv[1]);
			mlx_loop(mlx->id);
		}
	}
	return (0);
}
