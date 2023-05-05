#include "../include/fdf.h"

static void	free_map(t_mlx_map **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]->alt);
		free(map[i]);
		i++;
	}
}

void	free_mlx(t_mlx *mlx)
{
	free_map(mlx->map);
	free(mlx->map);
	free(mlx->win);
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
