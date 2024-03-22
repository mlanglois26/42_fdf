/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:10:42 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/22 14:20:27 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_cam	*ft_init_cam(void)
{
	t_cam	*cam;

	cam = malloc(sizeof(t_cam));
	if (!cam)
		return (NULL);
	cam->zoom = 0;
	cam->x_offset = (WIN_WIDTH + MENU) / 2;
	cam->y_offset = WIN_HEIGHT / 3;
	cam->z_increase = 1;
	return (cam);
}

void	ft_set_cam_default(t_fdf *fdf)
{
	float	zoom_width;
	float	zoom_heigth;
	float	zoom_avg;

	zoom_width = (float)fdf->map->total_width / (WIN_WIDTH + MENU);
	zoom_heigth = (float)fdf->map->total_height / WIN_HEIGHT;
	zoom_avg = (zoom_width + zoom_heigth) / 10;
	fdf->cam->zoom = (WIN_WIDTH * WIN_HEIGHT) / (fdf->map->total_height
			* fdf->map->total_width) * zoom_avg;
}
