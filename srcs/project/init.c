/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:15:42 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/30 14:56:31 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_map *ft_init_map(void)
{
    t_map *map;

    map = malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->point_index = NULL;

    map->total_width = 0;
    map->total_height = 0;
    return (map);
}

t_point *ft_init_point_index(int total_height, int total_width)
{
    t_point *point_index;
    int j_axis;
    int i_axis;

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

t_image *ft_init_image(void)
{
    t_image *image = malloc(sizeof(t_image));
    if (!image)
        return NULL;

    image->img_ptr = NULL;
    image->addr = NULL;
    image->bpp = 0;
    image->line_length = 0;
    image->endian = 0;

    return image;
}