/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:15:42 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/12 13:29:05 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_map	*ft_init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->point_index = NULL;
	map->total_width = 0;
	map->total_height = 0;
	map->max_z = 0.00;
	map->min_z = 0.00;
	return (map);
}

t_point	*ft_init_point_index(int total_height, int total_width)
{
	t_point	*point_index;
	int		j_axis;
	int		i_axis;

	point_index = malloc(total_width * total_height * sizeof(t_point));
	if (!point_index)
		return (NULL);
	j_axis = 0;
	while (j_axis < total_height)
	{
		i_axis = 0;
		while (i_axis < total_width)
		{
			point_index[j_axis * total_width + i_axis].y = 0;
			point_index[j_axis * total_width + i_axis].x = 0;
			point_index[j_axis * total_width + i_axis].z = 0;
			point_index[j_axis * total_width + i_axis].color = 0;
			i_axis++;
		}
		j_axis++;
	}
	return (point_index);
}

t_image	*ft_init_image(void)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->img_ptr = NULL;
	image->addr = NULL;
	image->bpp = 0;
	image->line_length = 0;
	image->endian = 0;
	return (image);
}

t_cam	*ft_init_cam(void)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	cam->zoom = 30;
	cam->x_offset =  0;
	cam->y_offset = 0;
	cam->z_increase = 1;
	return (cam);
}

t_line	*ft_init_line(t_point start, t_point end)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	line->start.x = start.x;
	line->start.y = start.y;
	line->start.z = start.z;
	line->start.color = start.color;
	line->end.x = end.x;
	line->end.y = end.y;
	line->end.color = end.color;
	return (line);
}
