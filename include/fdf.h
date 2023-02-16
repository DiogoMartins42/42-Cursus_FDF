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

#include "../libft/include/libft.h"
#include "../minilibx-linux/mlx.h"

typedef struct
{
    int width;
    int height;
    int **z_pos;
}           fdf;

void    read_file(char *file,fdf *data);

#endif

