/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:13:10 by malanglo          #+#    #+#             */
/*   Updated: 2024/02/01 18:47:40 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int ft_get_z(char *line, int i_axis)
{
    char **num;
    int z;
    int i;

    num = ft_strsplit(line, ' ');
    z = ft_atoi(num[i_axis]);
    i =0;
    while (num[i] != NULL)
    {
        free(num[i]);
        i++;
    }
    free(num);
    return (z);
}

void	ft_get_coordinates(char *line, t_map *map, int j_axis, int i_axis)
{
    map->point_index[j_axis * map->total_width + i_axis].y = j_axis;
    map->point_index[j_axis * map->total_width + i_axis].x = i_axis;
    map->point_index[j_axis * map->total_width + i_axis].z = ft_get_z(line, i_axis); 
}

void ft_fill_2D_map(char *file, t_map *map)
{
    int fd;
    char *line;
    int j_axis;
    int i_axis;

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

