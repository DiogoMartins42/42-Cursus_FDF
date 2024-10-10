/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 10:10:38 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/05/06 10:10:43 by dmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/*void	free_map(t_mlx_map *map)
{
	int	i;
	
	i = 0;
	while (map->alt[i])
	{
		free (map->alt[i]);
		i++;
	}
}*/

void	free_mlxmap(t_mlx_map *mlx)
{
	int	i;

	i = 0;
	while (mlx->alt[i])
	{
		free(mlx->alt[i]);
		i++;
	}
	free(mlx->alt);
	free (mlx);
}

void	free_mlx(t_mlx *mlx)
{
	free(mlx->id);
	free(mlx->win);
	free(mlx->img);
	free(mlx);
}

int	check_file(char *argv)
{
	int	fd;
	int	status;

	fd = open(argv, O_RDONLY);
	status = 0;
	if (read(fd, 0, 0) == -1)
		status = 1;
	close(fd);
	return (status);
}
