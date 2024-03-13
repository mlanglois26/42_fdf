/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:19:55 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/12 16:26:20 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	center(t_mlx *fdf)
{
	fdf->cam->x_offset += ((WIN_WIDTH - fdf->map->total_width) / 2);
	fdf->cam->y_offset = -500;
}

int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	if (argc != 2)
	{
		printf("Wrong number of arguments - expected ./fdf selected_map\n");
		exit(0);
	}
	else
	{
		mlx = init_fdf(argv[1]);
		if (!mlx)
			return (MLX_ERROR);
		// center(mlx);
		// ft_render_map(mlx);
		mlx_key_hook(mlx->mlx_win_ptr, &key_scale, mlx);
		hooks_handler(mlx);
		mlx_loop(mlx->mlx_ptr);
	}
	return (0);
}
