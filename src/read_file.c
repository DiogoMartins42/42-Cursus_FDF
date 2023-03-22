/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmanuel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:13:10 by dmanuel-          #+#    #+#             */
/*   Updated: 2023/02/16 11:13:12 by dmanuel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/fdf.h"

int	get_height(char *file)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file, O_RDONLY, 0);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	close (fd);
	return (height);
}

int	get_width(char *file)
{
	int		width;
	int		fd;
	char	*line;

	width = 0;
	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	if (line != NULL)
		width = ft_wdcounter(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	make_z(int *z_line, char *line)
{
	char	**num;
	int		i;

	i = 0;
	num = ft_split(line, ' ');
	while (num[i])
	{
		z_line[i] = ft_atoi(num[i]);
		free(num[i]);
		i++;
	}
	free(num);
}

void	read_file(char *file, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	data->height = get_height(file);
	data->width = get_width(file);
	data->z_pos = malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	fd = open(file, O_RDONLY, 0);
	line = get_next_line(fd);
	while (line)
	{
		data->z_pos[i] = malloc(sizeof(int) * (data->width + 1));
		make_z(data->z_pos[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	data->z_pos[i] = NULL;
}
