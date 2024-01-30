/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:18:57 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/30 18:36:47 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void ft_apply_zoom(t_point *point, float zoom, int x_offset, int y_offset) 
{
    point->x *= zoom;
    point->y *= zoom;
    point->x += x_offset;
    point->y += y_offset;
}

void ft_algo_bres(t_point start, t_point end, t_mlx *data)
{
	float x_distance;
	float y_distance;
	int max;

	
   	ft_apply_zoom(&start, data->zoom, 425, 60);
    ft_apply_zoom(&end, data->zoom, 425, 60);
	
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


void ft_join_points(t_mlx **data)
{
	int j_axis;
	int i_axis;
	t_point start;
	t_point end;
	int total_width = (*data)->map->total_width;
	j_axis = 0;
	while (j_axis < (*data)->map->total_height)
	{
		i_axis = 0;
		while (i_axis < (*data)->map->total_width)
		{
			if (i_axis < (*data)->map->total_width - 1)
            {
                start.x = (float)i_axis;
                start.y = (float)j_axis;
				start.z = (*data)->map->point_index[j_axis * total_width + i_axis].z;

                end.x = (float)i_axis + 1;
                end.y = (float)j_axis;
				end.z = (*data)->map->point_index[j_axis * total_width + i_axis + 1].z;
                ft_algo_bres(start, end, (*data));
            }
            if (j_axis < (*data)->map->total_height - 1)
            {
                start.x = (float)i_axis;
                start.y = (float)j_axis;
				start.z = (*data)->map->point_index[j_axis *total_width + i_axis].z;

                end.x = (float)i_axis;
                end.y = (float)j_axis + 1;
				end.z = (*data)->map->point_index[j_axis * total_width + i_axis + 1].z;
                
				ft_algo_bres(start, end, (*data));
            }
			i_axis++;
		}
		j_axis++;
	}
}
