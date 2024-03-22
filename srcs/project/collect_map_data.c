/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_map_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:32:22 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/21 10:55:05 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_free_split(char **num)
{
	int	i;

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
	if (!num)
		return (0);
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

int	ft_get_z(char *line, int i_axis)
{
	char	**num;
	int		z;

	num = ft_strsplit(line, ' ');
	if (!num)
		return (0);
	if (i_axis < 0 || i_axis >= ft_count_words(line, ' '))
	{
		ft_free_split(num);
		return (0);
	}
	if (!num[i_axis])
	{
		ft_free_split(num);
		return (0);
	}
	z = ft_atoi(num[i_axis]);
	ft_free_split(num);
	return (z);
}

int	ft_get_map_dimensions(char *file, int *height, int *width)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	if (fd < 0)
		return (close(fd), -1);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), -1);
	*width = ft_count_words(line, ' ');
	*height = 1;
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		(*height)++;
		free(line);
	}
	close(fd);
	return (0);
}
