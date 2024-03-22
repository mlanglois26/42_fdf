/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:48:33 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/21 14:23:46 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	render_map_wrapper(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	ft_render_map(fdf);
	return (0);
}

int	key_moves(int key, t_fdf *fdf)
{
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
	else if (key == XK_Escape)
		escape_close_window(fdf);
	return (0);
}

void	hooks_handler(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->mlx_win_ptr);
	mlx_loop_hook(fdf->mlx_ptr, render_map_wrapper, fdf);
	mlx_hook(fdf->mlx_win_ptr, 17, 0, cross_close_window, fdf);
	mlx_hook(fdf->mlx_win_ptr, KeyPress, KeyPressMask, key_moves, fdf);
}
