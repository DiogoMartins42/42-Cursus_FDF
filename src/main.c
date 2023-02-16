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

int main(int argc, char **argv)
{
    fdf *data;

    data = (fdf *)malloc(sizeof(fdf));
    read_file(argv[1], data);

    int i;
    int j;
    (void) argc;
    i = 0;
    while (i < data->height)
    {
        j = 0;
        while (j < data->width)
        {
            ft_printf("%d", data->z_pos[i][j]);
            j++;
        }
        ft_printf("\n");
        i++;
    }
    free(data);
}

