/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:19:55 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/30 18:26:53 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

// #define	SIDE_LEN		1980
#define MLX_ERROR 1
#define X				200
#define Y				200

t_mlx *init_fdf(char *file)
{
    t_mlx *fdf;

    fdf = malloc(sizeof(t_mlx));
    if (!fdf)
        return NULL;

    fdf->mlx_ptr = mlx_init();
    if (!fdf->mlx_ptr)
    {
        free(fdf);
        return NULL;
    }

    fdf->mlx_win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Fil de Fer");
    if (!fdf->mlx_win_ptr)
    {
        free(fdf);
        return NULL;
    }

    // fdf->image = ft_init_image();
    // if (!fdf->image)
    // {
    //     free(fdf);
    //     return NULL;
    // }

    // fdf->image->img_ptr = mlx_new_image(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    // if (!fdf->image->img_ptr)
    // {
    //     free(fdf);
    //     return NULL;
    // }

    // fdf->image->addr = mlx_get_data_addr(fdf->image->img_ptr, &fdf->image->bpp, &fdf->image->line_length, &fdf->image->endian);
	
    fdf->map = read_map(file);
    fdf->zoom = 30;

    ft_join_points(&fdf);

    return fdf;
}

int close_cross_window(void)
{
    exit(0);
    return (0);
}

void	my_pixel_put(t_image *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_length * y) + (x * (img->bpp / 8));
	*((unsigned int *)(offset + img->addr)) = color;
}

void color_screen(t_mlx *data, int color)
{
    int y;
    int x;

    y = 0;
    
    while (y < WIN_HEIGHT)
    {
        x = 0;
        while (x < WIN_WIDTH)
        {
            my_pixel_put(data->image, x, y, color);
            ++x;
        }
        ++y;
    }
}

int escape(int key, t_mlx *mlx)
{
    if (key == XK_Escape)
        exit (0);
    else if (key == XK_r)
    {
        color_screen(mlx, 0xcecece);
        // ft_join_points(&mlx);
    }
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win_ptr, mlx->image->img_ptr, 0, 0);
    return (0);
}

void hooks_handler(t_mlx *mlx)
{
    mlx_key_hook(mlx->mlx_win_ptr, escape, mlx);
    mlx_hook(mlx->mlx_win_ptr, 17, 0, close_cross_window, mlx);
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
        // ft_join_points(&mlx);
        hooks_handler(mlx);
        mlx_loop(mlx->mlx_ptr);
    }
    return (0);
}
