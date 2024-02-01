/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:18:57 by malanglo          #+#    #+#             */
/*   Updated: 2024/02/01 18:48:55 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

// void my_pixel_put(t_image *img, int x, int y, int color)
// {
//     char *dst;
    
//     if (x >= MENU && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
//     {
//         dst = img->img_ptr + (y * img->line_length + x * (img->bpp / 8));
//         *(unsigned int *)dst = color;
//     }
// }

void	my_pixel_put(t_image *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_length * y) + (x * (img->bpp / 8));
	*((unsigned int *)(offset + img->addr)) = color;
}

void ft_algo_bres(t_point start, t_point end, t_mlx *data)
{
	float x_distance;
	float y_distance;
	int max;

	x_distance = end.x - start.x;
	y_distance = end.y - start.y;

	max = ft_max(ft_abs(x_distance), ft_abs(y_distance));
    x_distance /= max;
    y_distance /= max;

    end.color = (end.z || start.z) ? 0xfc0345 : 0xBBFAFF;
	end.color = (end.z != start.z) ? 0xfc031c : end.color;
    while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->mlx_win_ptr, start.x, start.y, end.color);
		start.x += x_distance;
		start.y += y_distance;
	} 
}
void ft_iso_transform(t_point *point, float angle, float map_center_x, float map_center_y) 
{
    float original_x = point->x;
    float original_y = point->y;

    float new_x = (original_x - original_y) * cos(angle);
    float new_y = (original_x + original_y) * sin(angle) - point->z;

    point->x = new_x + map_center_x;
    point->y = new_y + map_center_y;
}

void ft_render_line(t_mlx *fdf, t_point start, t_point end)
{
    
	// ft_apply_colors(&start);
    // ft_apply_colors(&end);

	ft_apply_zoom(&start, fdf->cam->zoom);
    ft_apply_zoom(&end, fdf->cam->zoom);

    ft_apply_x_offset(&start, fdf->cam->x_offset);
    ft_apply_x_offset(&end, fdf->cam->x_offset);

    ft_apply_y_offset(&start, fdf->cam->y_offset);
    ft_apply_y_offset(&end, fdf->cam->y_offset);
    
    ft_z_increase(&start, fdf->cam->z_increase);
    ft_z_increase(&end, fdf->cam->z_increase);

	ft_iso_transform(&start, ANGLE,0, 0);
    ft_iso_transform(&end, ANGLE, 0, 0);

    fdf->image->line = ft_init_line(start, end);

    ft_algo_bres(fdf->image->line->start, fdf->image->line->end, fdf);
    
    free(fdf->image->line);
}

void	draw_background(t_mlx *fdf)
{
	int	*img;
	int	i;

	img = (int *)fdf->image->addr;
	i = 0;
	while (i < WIN_WIDTH * WIN_HEIGHT)
	{
		if (i % WIN_WIDTH < MENU)
			img[i] = 0x23364c;
		else
			img[i] = 0x172432;
		i++;
	}
}

void ft_render_map(t_mlx *fdf)
{
    int j_axis;
    int i_axis;
    
    draw_background(fdf);
    j_axis = 0;
    while (j_axis < fdf->map->total_height)
    {
        i_axis = 0;
        while (i_axis < fdf->map->total_width)
        {
            if (i_axis < fdf->map->total_width - 1)
                ft_render_line(fdf, fdf->map->point_index[j_axis * fdf->map->total_width + i_axis], fdf->map->point_index[j_axis *fdf->map->total_width + i_axis + 1]);

            if (j_axis < fdf->map->total_height - 1)
                ft_render_line(fdf, fdf->map->point_index[j_axis * fdf->map->total_width + i_axis], fdf->map->point_index[(j_axis + 1) *fdf->map->total_width + i_axis]);
            
            i_axis++;
        }
        j_axis++;
    }
    ft_print_menu(fdf);
}


// void ft_render_fdf(t_mlx *fdf)
// {
//     draw_background(fdf);
//     ft_render_map(fdf);
//     ft_print_menu(fdf);
// }