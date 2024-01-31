/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:18:57 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/31 20:06:39 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void ft_z_increase(t_point *point, float z)
{
    point->x *= z;
    point->y *= z;
}

void ft_algo_bres(t_point start, t_point end, t_mlx *data)
{
	float x_distance;
	float y_distance;
	int max;

    ft_apply_zoom(&start, data->cam->zoom);
    ft_apply_zoom(&end, data->cam->zoom);

    ft_apply_x_offset(&start, data->cam->x_offset);
    ft_apply_x_offset(&end, data->cam->x_offset);

    ft_apply_y_offset(&start, data->cam->y_offset);
    ft_apply_y_offset(&end, data->cam->y_offset);
    
    ft_z_increase(&start, data->cam->z_increase);
    ft_z_increase(&end, data->cam->z_increase);

	transform(&start, 0.6);
    transform(&end, 0.6);
	
	x_distance = end.x - start.x;
	y_distance = end.y - start.y;

	max = ft_max(ft_abs(x_distance), ft_abs(y_distance));
    x_distance /= max;
    y_distance /= max;
	end.color = (end.z || start.z) ? 0xfc0345 : 0xff;
	end.color = (end.z != start.z) ? 0xfc031c : end.color;

 	while ((int)(start.x - end.x) || (int)(start.y - end.y))
    {
		mlx_pixel_put(data->mlx_ptr, data->mlx_win_ptr, start.x, start.y, end.color);
		start.x += x_distance;
		start.y += y_distance;
    }
}


// void ft_join_points(t_mlx **data)
// {
// 	int j_axis;
// 	int i_axis;
// 	t_point start;
// 	t_point end;
// 	int total_width = (*data)->map->total_width;
// 	j_axis = 0;
// 	while (j_axis < (*data)->map->total_height)
// 	{
// 		i_axis = 0;
// 		while (i_axis < (*data)->map->total_width)
// 		{
// 			if (i_axis < (*data)->map->total_width - 1)
//             {
//                 start.x = i_axis;
//                 start.y = j_axis;
// 				start.z = (*data)->map->point_index[j_axis * total_width + i_axis].z;

//                 end.x = i_axis + 1;
//                 end.y = j_axis;
// 				end.z = (*data)->map->point_index[j_axis * total_width + i_axis + 1].z;
//                 ft_algo_bres(start, end, (*data));
//             }
//             if (j_axis < (*data)->map->total_height - 1)
//             {
//                 start.x = i_axis;
//                 start.y = j_axis;
// 				start.z = (*data)->map->point_index[j_axis *total_width + i_axis].z;

//                 end.x = i_axis;
//                 end.y = j_axis + 1;
// 				end.z = (*data)->map->point_index[j_axis * total_width + i_axis + 1].z;
                
// 				ft_algo_bres(start, end, (*data));
//             }
// 			i_axis++;
// 		}
// 		j_axis++;
// 	}
// }

float interpolate(t_point *point_index, int total_width, float x, float y)
{
    int x_start = (int)floor(x);
    int y_start = (int)floor(y);
    int x_end = (int)ceil(x);
    int y_end = (int)ceil(y);

    float value1 = point_index[y_start * total_width + x_start].z;
    float value2 = point_index[y_start * total_width + x_end].z;
    float value3 = point_index[y_end * total_width + x_start].z;
    float value4 = point_index[y_end * total_width + x_end].z;

    float x_fraction = x - x_start;
    float y_fraction = y - y_start;

    float interpolated_value = (1.0 - x_fraction) * ((1.0 - y_fraction) * value1 + y_fraction * value3) +
                               x_fraction * ((1.0 - y_fraction) * value2 + y_fraction * value4);

    return interpolated_value;
}



// je vais devoir update start.z et en.z start.z *= fdf->cam->z_increase;


void ft_join_points(t_mlx **data)
{
    float j_axis;
    float i_axis;
    t_point start;
    t_point end;
    int total_width = (*data)->map->total_width;
	// ft_print_menu(*data);
    // draw_background((*data));
    // ft_print_back(*data);
    j_axis = 0.0;
    while (j_axis < (*data)->map->total_height)
    {
        i_axis = 0.0;
        while (i_axis < (*data)->map->total_width)
        {

            if (i_axis < (*data)->map->total_width - 1.0)
            {
                printf("check x = %f\n", start.x);
                start.x = i_axis;
                start.y = j_axis;
                start.z = interpolate((*data)->map->point_index, total_width, i_axis, j_axis);

                end.x = i_axis + 1.0;
                end.y = j_axis;
                end.z = interpolate((*data)->map->point_index, total_width, i_axis + 1.0, j_axis);
                ft_algo_bres(start, end, (*data));
            }
            if (j_axis < (*data)->map->total_height - 1.0)
            {
                start.x = i_axis;
                start.y = j_axis;
                start.z = interpolate((*data)->map->point_index, total_width, i_axis, j_axis);

                end.x = i_axis;
                end.y = j_axis + 1.0;
                end.z = interpolate((*data)->map->point_index, total_width, i_axis, j_axis + 1.0);
                ft_algo_bres(start, end, (*data));
            }
            i_axis++;
        }
        j_axis++;
    }
}


// void ft_render_image(t_mlx *fdf)
// {
//     int j_axis;
//     int i_axis;

//     // clear_image
//     // draw background
//     j_axis = 0;
//     while (j_axis < fdf->map->total_height)
//     {
//         i_axis = 0;
//         while (i_axis < fdf->map->total_width)
//         {
//             if (x_axis < fdf->map->total_width - 1.0)
//                 ft_draw_lines();

//             if (y_axis < fdf->map->total_height - 1.0)
//                 ft_draw_lines();
            
//             i_axis++;
//         }
//         j_axis++;
//     }
//     // mlx_put_image_to_window
//     // menu
// }

// dans ft_draw_lines
// rescale z
// apply_colors

// init_line

// rotate
// project
// transform
// bresenham

// free line