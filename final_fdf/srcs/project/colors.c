/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:53:36 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/11 15:54:01 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

double percent(double cur_z, double z_min, double z_max)
{
	double range;
	double delta;
	
	range = z_max - z_min;
	delta = cur_z - z_min;
	if (range == 0)
		return (1.0);
	else
		return (delta / range);
}

int attribute_color_default(double value)
{
	if (value <= 0.2)
		return (0xFF7EDB);
	else if (value <= 0.4)
		return (0x40b1f6);
	else if (value <= 0.6)
		return (0x4b64f5);
	else if (value <= 0.8)
		return (0xa571e8);
	else
		return (0x36F9F6);	
}

int find_z_min(t_map *map)
{
	double z;
	int j_axis;
	int i_axis;

    z = INT_MAX;
	j_axis = 0;
	while (j_axis < map->total_height)
	{
		i_axis = 0;
		while (i_axis < map->total_width)
		{
			if (z > map->point_index[j_axis * map->total_width + i_axis].z)
				z = map->point_index[j_axis * map->total_width + i_axis].z;
			i_axis++;
		}
		j_axis++;
	}
	return (z);
}

int find_z_max(t_map *map)
{
	double z;
	int j_axis;
	int i_axis;

    z = INT_MIN;
	j_axis = 0;
	while (j_axis < map->total_height)
	{
		i_axis = 0;
		while (i_axis < map->total_width)
		{
			if (z < map->point_index[j_axis * map->total_width + i_axis].z)
				z = map->point_index[j_axis * map->total_width + i_axis].z;
			i_axis++;
		}
		j_axis++;
	}
	return (z);
}

void add_map_default_colors(t_map *map)
{
	int j_axis;
	int i_axis;
	double z_min;
	double z_max;
	double value;
	
	z_min = find_z_min(map);
	z_max = find_z_max(map);
	j_axis = 0;
	while (j_axis < map->total_height)
	{
		i_axis = 0;
		while (i_axis < map->total_width)
		{
			value = percent(map->point_index[j_axis * map->total_width + i_axis].z, z_min, z_max);
			map->point_index[j_axis * map->total_width + i_axis].color = attribute_color_default(value);
			i_axis++;
		}
		j_axis++;
	}
}

int color(t_point start, t_point end)
{
	int color = (start.color + end.color);
	return (color); 
}

