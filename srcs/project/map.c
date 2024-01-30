/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:10:40 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/30 14:56:39 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int ft_get_map_dimensions(char *file, int *height, int *width)
{
    int fd;
    char *line;

    fd = open(file, O_RDONLY, 0);
    if (fd < 0)
        return (-1);
    line = get_next_line(fd);
    if (!line)
    {
        close(fd);
        return (-1);
    }
    *width = ft_count_words(line, ' ');
    *height = 1;
    free(line);
    while ((line = get_next_line(fd)) != NULL)
    {
        (*height)++;
        free(line);
    }
    close(fd);
    return (0);
}

t_map *read_map(char *file)
{
    t_map *map;
    int width;
    int height;

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
    ft_fill_2D_map(file, map);
    return (map);
}