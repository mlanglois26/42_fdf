/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:19:55 by malanglo          #+#    #+#             */
/*   Updated: 2024/02/01 18:44:23 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

// void ft_centre_map_on_screen(t_map *map)
// {
//     int j_axis;
//     int i_axis;
   
//     j_axis = 0;
//     while (j_axis < map->total_height)
//     {
//         i_axis = 0;
//         while (i_axis < map->total_width)
//         {
//             printf("point AVANT nouvelle assoc x = %f | y = %f\n", map->point_index[j_axis *map->total_width + i_axis].x, map->point_index[j_axis *map->total_width + i_axis].y);
//             map->point_index[j_axis *map->total_width + i_axis].x +=  (WIN_WIDTH / 2);
//             map->point_index[j_axis *map->total_width + i_axis].y += (WIN_HEIGHT / 2);
//             printf("point APRES nouvelle assoc x = %f | y = %f\n", map->point_index[j_axis *map->total_width + i_axis].x, map->point_index[j_axis *map->total_width + i_axis].y);
//             i_axis++;
//         }
//         j_axis++;
//     }
// }

void center(t_mlx *fdf)
{
    fdf->cam->x_offset += ((WIN_WIDTH - fdf->map->total_width) / 2);
    fdf->cam->y_offset = -500;
}

int main(int argc, char **argv)
{
    t_mlx *mlx;

    if (argc != 2)
        exit (0);
    else
    {
        mlx = init_fdf(argv[1]);
        if (!mlx)
            return (MLX_ERROR);
        center(mlx);
        ft_render_map(mlx);
        mlx_key_hook(mlx->mlx_win_ptr, &key_scale, mlx);
        hooks_handler(mlx);
        mlx_loop(mlx->mlx_ptr);
    }
    return (0);
}
