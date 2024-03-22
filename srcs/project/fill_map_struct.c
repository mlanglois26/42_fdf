/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:35:28 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/22 15:03:49 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_map	*fill_map_struct(char *file)
{
	t_map	*map;
	int		width;
	int		height;

	if (ft_get_map_dimensions(file, &height, &width) == -1)
		return (NULL);
	map = ft_init_map();
	if (!map)
		return (NULL);
	map->total_height = height;
	map->total_width = width;
	map->point_index = ft_init_point_index(map->total_height, map->total_width);
	if (!map->point_index)
	{
		free(map);
		return (NULL);
	}
	ft_get_points_data(file, map);
	return (map);
}

void	ft_get_points_data_heart(char *line, t_map *map, int j_axis, int i_axis)
{
	map->point_index[j_axis * map->total_width + i_axis].y = j_axis;
	map->point_index[j_axis * map->total_width + i_axis].x = i_axis;
	map->point_index[j_axis * map->total_width + i_axis].z = ft_get_z(line,
			i_axis);
	map->point_index[j_axis * map->total_width
		+ i_axis].color = ft_get_color(line, i_axis);
}

void	ft_get_points_data(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		j_axis;
	int		i_axis;

	fd = open(file, O_RDONLY);
	j_axis = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || j_axis >= map->total_height)
			break ;
		i_axis = 0;
		while (i_axis < map->total_width)
		{
			ft_get_points_data_heart(line, map, j_axis, i_axis);
			i_axis++;
		}
		free(line);
		j_axis++;
	}
	close(fd);
}
