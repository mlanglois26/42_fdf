/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:13:10 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/08 10:16:01 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_get_z(char *line, int i_axis)
{
	char	**num;
	int		z;
	int		i;

	num = ft_strsplit(line, ' ');
	z = ft_atoi(num[i_axis]);
	i = 0;
	while (num[i] != NULL)
	{
		free(num[i]);
		i++;
	}
	free(num);
	return (z);
}

void ft_free_split(char **num)
{
    int i;

    i = 0;
    while (num[i])
    {
        free(num[i]);   
        i++;
    }
    free(num);
}

int	ft_get_color(char *line, int i_axis)
{
	char	**num;
	int		color;
	char	*comma_pos;
	char	*point_info;
	char	*z_hexa;

	color = 0;
	num = ft_strsplit(line, ' ');
	point_info = num[i_axis];
	comma_pos = ft_strchr(point_info, ',');
	if (comma_pos != NULL)
	{
		z_hexa = ft_strdup(comma_pos + 3);
		color = ft_atoi_base(z_hexa, 16);
		free(z_hexa);
	}
	else
	{
		color = -1;
	}
    ft_free_split(num);
	return (color);
}

void	ft_get_coordinates(char *line, t_map *map, int j_axis, int i_axis)
{
	map->point_index[j_axis * map->total_width + i_axis].y = j_axis;
	map->point_index[j_axis * map->total_width + i_axis].x = i_axis;
	map->point_index[j_axis * map->total_width + i_axis].z = ft_get_z(line, i_axis);
	map->point_index[j_axis * map->total_width + i_axis].color = ft_get_color(line, i_axis);
}

void	ft_fill_2D_map(char *file, t_map *map)
{
	int		fd;
	char	*line;
	int		j_axis;
	int		i_axis;

	fd = open(file, O_RDONLY);
	j_axis = 0;
	while ((line = get_next_line(fd)) != NULL && j_axis < map->total_height)
	{
		i_axis = 0;
		while (i_axis < map->total_width)
		{
			ft_get_coordinates(line, map, j_axis, i_axis);
			i_axis++;
		}
		free(line);
		j_axis++;
	}
	close(fd);
}
