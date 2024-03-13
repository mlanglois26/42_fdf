/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:42:17 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/13 17:27:41 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

// malloc 
// assigne les data de la map
// init mlx_ptr
// init mlx_win
// assigne les data de l image 
// init camera

t_cam	*ft_init_cam(void)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	cam->zoom = 0;
	cam->x_offset = (WIN_WIDTH + MENU) / 2;
	cam->y_offset = WIN_HEIGHT / 4;
	cam->z_increase = 1;
	return (cam);
}

void	ft_set_cam_default(t_fdf *fdf)
{
	float    zoom_width;
    float    zoom_heigth;
    float    zoom_avg;

	zoom_width = (float)fdf->map->total_width / (WIN_WIDTH + MENU);
	// printf("1 = %f\n", (float)fdf->map->total_width);
	// printf("2 = %d\n", WIN_WIDTH);
	// printf("zoom width = %f\n", zoom_width);
	// printf("\n");
    
	zoom_heigth = (float)fdf->map->total_height / WIN_HEIGHT;
	// printf("1 = %f\n", (float)fdf->map->total_height);
	// printf("2 = %d\n", WIN_HEIGHT);
	// printf("zoom heigth = %f\n", zoom_heigth);
    // printf("\n");

	zoom_avg = (zoom_width + zoom_heigth) / 8;
	// // printf("zoom_avg = %f\n", zoom_avg);
	// fdf->cam->x_offset = ((WIN_WIDTH + MENU) - (float)fdf->map->total_width) / 4;
	// fdf->cam->y_offset = (WIN_HEIGHT - (float)fdf->map->total_height) / 4;
	fdf->cam->zoom = (WIN_WIDTH * WIN_HEIGHT) / (fdf->map->total_height * fdf->map->total_width) * zoom_avg;
	// printf("zoom = %f\n", fdf->cam->zoom);
}

t_image *ft_init_image()
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
	image->addr = mlx_get_data_addr(image->img_ptr, &image->bpp, &image->line_length, &image->endian);
	return (image);
}

t_fdf *init_fdf(char *file)
{
    t_fdf *fdf;

    fdf = malloc(sizeof(t_fdf));
    if (!fdf)
        return NULL;
    fdf->map = fill_map_struct(file);
    if (!fdf->map)
        return (free(fdf), NULL);
    fdf->mlx_ptr = mlx_init();
    if (!fdf->mlx_ptr)
        return (free(fdf), NULL);
    fdf->mlx_win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Fil de Fer");
    if (!fdf->mlx_win_ptr)
        return (free(fdf), NULL);
    fdf->image = ft_image_data(fdf);
	if (!fdf->image)
	{
		free(fdf);
		return (NULL);
	}
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