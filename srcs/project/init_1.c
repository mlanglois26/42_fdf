/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:42:17 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/22 14:14:56 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_fdf	*init_fdf(char *file)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	fdf->map = fill_map_struct(file);
	if (!fdf->map)
		return (free(fdf), NULL);
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		return (free(fdf), NULL);
	fdf->mlx_win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"Fil de Fer");
	if (!fdf->mlx_win_ptr)
		return (free(fdf), NULL);
	fdf->image = ft_image_data(fdf);
	if (!fdf->image)
		return (free(fdf), NULL);
	fdf->cam = ft_init_cam();
	if (!fdf->cam)
		return (free(fdf), NULL);
	ft_set_cam_default(fdf);
	return (fdf);
}

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
			point_index[j_axis * total_width + i_axis].color = -1;
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

t_image	*ft_image_data(t_fdf *fdf)
{
	t_image	*image;

	image = ft_init_image();
	if (!image)
		return (NULL);
	image->img_ptr = mlx_new_image(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	image->addr = mlx_get_data_addr(image->img_ptr, &image->bpp,
			&image->line_length, &image->endian);
	return (image);
}
