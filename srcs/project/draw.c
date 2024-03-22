/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:52:02 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/22 16:29:35 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_algo_bres(t_point start, t_point end, t_fdf *fdf)
{
	float	x_distance;
	float	y_distance;
	int		max;

	x_distance = end.x - start.x;
	y_distance = end.y - start.y;
	max = ft_max(ft_abs(x_distance), ft_abs(y_distance));
	x_distance /= max;
	y_distance /= max;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		my_pixel_put(fdf, start.x, start.y, color(start, end));
		start.x += x_distance;
		start.y += y_distance;
		if (start.x > WIN_WIDTH || start.y > WIN_HEIGHT || start.y < 0
			|| start.x < 0)
			break ;
	}
}

void	ft_iso_transform(t_point *point, float angle)
{
	float	new_x;
	float	new_y;

	new_x = (point->x - point->y) * cos(angle);
	new_y = (point->x + point->y) * sin(angle) - point->z;
	point->x = new_x;
	point->y = new_y;
}

void	ft_render_line(t_fdf *fdf, t_point start, t_point end)
{
	ft_apply_zoom(&start, fdf->cam->zoom);
	ft_apply_zoom(&end, fdf->cam->zoom);
	ft_z_increase(&start, fdf->cam->z_increase);
	ft_z_increase(&end, fdf->cam->z_increase);
	ft_iso_transform(&start, ANGLE);
	ft_iso_transform(&end, ANGLE);
	ft_apply_x_offset(&start, fdf->cam->x_offset);
	ft_apply_x_offset(&end, fdf->cam->x_offset);
	ft_apply_y_offset(&start, fdf->cam->y_offset);
	ft_apply_y_offset(&end, fdf->cam->y_offset);
	if (fdf->map->point_index->color == -1)
		add_map_default_colors(fdf->map);
	ft_algo_bres(start, end, fdf);
}

void	ft_render_map_heart(t_fdf *fdf, int j_axis, int i_axis)
{
	if (i_axis < fdf->map->total_width - 1)
		ft_render_line(fdf, fdf->map->point_index[j_axis * fdf->map->total_width
			+ i_axis], fdf->map->point_index[j_axis * fdf->map->total_width
			+ i_axis + 1]);
	if (j_axis < fdf->map->total_height - 1)
		ft_render_line(fdf, fdf->map->point_index[j_axis * fdf->map->total_width
			+ i_axis], fdf->map->point_index[(j_axis + 1)
			* fdf->map->total_width + i_axis]);
}

void	ft_render_map(t_fdf *fdf)
{
	int	j_axis;
	int	i_axis;

	project_background(fdf);
	j_axis = 0;
	while (j_axis < fdf->map->total_height)
	{
		i_axis = 0;
		while (i_axis < fdf->map->total_width)
		{
			ft_render_map_heart(fdf, j_axis, i_axis);
			i_axis++;
		}
		j_axis++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->mlx_win_ptr, fdf->image->img_ptr,
		0, 0);
	project_menu(fdf);
}
