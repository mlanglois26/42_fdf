/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:48:33 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/13 17:47:03 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"


void	ft_apply_zoom(t_point *point, float zoom)
{
	point->x *= zoom;
	point->y *= zoom;
}

void	ft_apply_x_offset(t_point *point, int x_offset)
{
	point->x += x_offset;
}

void	ft_apply_y_offset(t_point *point, int y_offset)
{
	point->y += y_offset;
}


void	ft_z_increase(t_point *point, float z)
{
	point->z *= z;
}


int	key_moves(int key, t_fdf *fdf)
{
    mlx_clear_window(fdf->mlx_ptr, fdf->mlx_win_ptr);
	if (key == XK_equal)
		fdf->cam->zoom += 10;
	else if (key == XK_minus)
		fdf->cam->zoom -= 10;
	else if (key == XK_r)
		fdf->cam->x_offset += 10;
	else if (key == XK_d)
		fdf->cam->y_offset += 10;
	else if (key == XK_l)
		fdf->cam->x_offset -= 10;
	else if (key == XK_u)
		fdf->cam->y_offset -= 10;
	else if (key == XK_f && fdf->cam->z_increase > -1)
		fdf->cam->z_increase -= 0.5;
	else if (key == XK_g && fdf->cam->z_increase < 1)
		fdf->cam->z_increase += 0.5;
    ft_render_map(fdf);
	return (0);
}

void	hooks_handler(t_fdf *fdf)
{
	mlx_hook(fdf->mlx_win_ptr, 17, 0, cross_close_window, fdf);
    // mlx_hook(fdf->mlx_win_ptr, KeyPress, KeyPressMask, escape_close_window, fdf);
    mlx_hook(fdf->mlx_win_ptr, KeyPress, KeyPressMask, key_moves, fdf);
}