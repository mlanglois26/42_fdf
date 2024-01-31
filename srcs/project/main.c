/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:19:55 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/31 19:44:36 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	my_pixel_put(t_image *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_length * y) + (x * (img->bpp / 8));
	*((unsigned int *)(offset + img->addr)) = color;
}

// void ft_print_back(t_mlx *fdf)
// {
//     int y;
//     int x;
//     void *mlx;
//     void *win;

//     mlx = fdf->mlx_ptr;;
//     win = fdf->mlx_win_ptr;

//     y = WIN_HEIGHT - 50;
//     while (y < WIN_HEIGHT)
//     {
//         x = 0;
//         while (x <=WIN_WIDTH)
//         {
//             mlx_pixel_put(fdf->mlx_ptr, fdf->mlx_win_ptr, x, y, 0xff0000);
//             ++x;
//         }
//         ++y;
//     }
//     mlx_put_image_to_window(fdf->mlx_ptr, fdf->mlx_win_ptr, fdf->image->img_ptr, 0, 0);
// }

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
        ft_join_points(&mlx);
        mlx_key_hook(mlx->mlx_win_ptr, &key_scale, mlx);
        hooks_handler(mlx);
        mlx_loop(mlx->mlx_ptr);
    }
    return (0);
}
