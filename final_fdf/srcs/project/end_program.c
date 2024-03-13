/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:45:04 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/13 12:43:05 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	cross_close_window(t_fdf *fdf)
{
	if (fdf->image)
	{
		mlx_destroy_image(fdf->mlx_ptr, fdf->image->img_ptr);
		free(fdf->image);
	}
	if (fdf->mlx_win_ptr)
		mlx_destroy_window(fdf->mlx_ptr, fdf->mlx_win_ptr);
	if (fdf->mlx_ptr)
	{
		mlx_destroy_display(fdf->mlx_ptr);
		free(fdf->mlx_ptr);
	}
	if (fdf->cam)
		free(fdf->cam);
	if (fdf->map)
	{
		free(fdf->map->point_index);
		free(fdf->map);
	}
	free(fdf);
	exit(0);
	return (0);
}

int	escape_close_window(int key, t_fdf *fdf)
{
	if (key == XK_Escape)
	{
		if (fdf->image)
		{
			mlx_destroy_image(fdf->mlx_ptr, fdf->image->img_ptr);
			free(fdf->image);
		}
		if (fdf->mlx_win_ptr)
			mlx_destroy_window(fdf->mlx_ptr, fdf->mlx_win_ptr);
		if (fdf->mlx_ptr)
		{
			mlx_destroy_display(fdf->mlx_ptr);
			free(fdf->mlx_ptr);
		}
		if (fdf->cam)
			free(fdf->cam);
		if (fdf->map)
		{
			free(fdf->map->point_index);
			free(fdf->map);
		}
		free(fdf);
		exit(0);
	}
	return (0);
}