/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:05:12 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/08 12:38:22 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_mlx *init_fdf(char *file)
{
    t_mlx *fdf;

    fdf = malloc(sizeof(t_mlx));
    if (!fdf)
        return NULL;
    fdf->map = read_map(file);
    if (!fdf->map)
        return (free(fdf), NULL);
    fdf->mlx_ptr = mlx_init();
    if (!fdf->mlx_ptr)
        return (free(fdf), NULL);
    fdf->mlx_win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Fil de Fer");
    if (!fdf->mlx_win_ptr)
        return (free(fdf), NULL);
    fdf->image = ft_init_image();
    if (!fdf->image)
        return (free(fdf), NULL);
    fdf->image->img_ptr = mlx_new_image(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    if (!fdf->image->img_ptr)
        return (free(fdf), NULL);
    fdf->image->addr = mlx_get_data_addr(fdf->image->img_ptr, &fdf->image->bpp, &fdf->image->line_length, &fdf->image->endian);
    fdf->cam = ft_init_cam();
    if (!fdf->cam)
        return (free(fdf), NULL);
    return (fdf);
}

