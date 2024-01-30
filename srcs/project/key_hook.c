/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:49:54 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/30 17:41:03 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

// int close_cross_window(void)
// {
//     exit(0);
//     return (0);
// }

// void	my_pixel_put(t_image *img, int x, int y, int color)
// {
// 	int	offset;

// 	offset = (img->line_length * y) + (x * (img->bpp / 8));
// 	*((unsigned int *)(offset + img->addr)) = color;
// }

// void color_screen(t_mlx *data, int color)
// {
//     int y;
//     int x;

//     y = 0;
    
//     while (y < WIN_HEIGHT)
//     {
//         x = 0;
//         while (x < WIN_WIDTH)
//         {
//             my_pixel_put(data->image, x, y, color);
//             ++x;
//         }
//         ++y;
//     }
// }

// int escape(int key, t_mlx *mlx)
// {
//     if (key == XK_Escape)
//         exit (0);
//     else if (key == XK_r)
//     {
//         color_screen(mlx, 0xffffff);
//     }
//     mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win_ptr, mlx->image->img_ptr, 0, 0);
//     return (0);
// }

// void hooks_handler(t_mlx *mlx)
// {
//     mlx_key_hook(mlx->mlx_win_ptr, escape, &mlx);
//     mlx_hook(mlx->mlx_win_ptr, 17, 0, close_cross_window, mlx);
// }
