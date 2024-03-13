/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:49:54 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/12 13:30:09 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	close_cross_window(void)
{
	exit(0);
	return (0);
}

int	key_scale(int key, t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win_ptr);
	if (key == XK_equal)
		mlx->cam->zoom += 10;
	else if (key == XK_minus)
		mlx->cam->zoom -= 10;
	else if (key == XK_r)
		mlx->cam->x_offset += 10;
	else if (key == XK_d)
		mlx->cam->y_offset += 10;
	else if (key == XK_l)
		mlx->cam->x_offset -= 10;
	else if (key == XK_u)
		mlx->cam->y_offset -= 10;
	else if (key == XK_f && mlx->cam->z_increase > -1)
		mlx->cam->z_increase -= 0.5;
	else if (key == XK_g && mlx->cam->z_increase < 1)
		mlx->cam->z_increase += 0.5;
	else if (key == XK_Escape)
		exit(0);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win_ptr, mlx->image->img_ptr,
		0, 0);
	ft_render_map(mlx);
	return (0);
}

void	hooks_handler(t_mlx *mlx)
{
	mlx_hook(mlx->mlx_win_ptr, 17, 0, close_cross_window, mlx);
	mlx_hook(mlx->mlx_win_ptr, KeyPress, KeyPressMask, key_scale, mlx);
}
