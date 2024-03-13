/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:24:14 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/13 17:49:43 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
	{
		printf("Wrong number of arguments - expected ./fdf selected_map\n");
		exit(0);
	}
	else
	{
		fdf = init_fdf(argv[1]);
		if (!fdf)
			exit(0);
		ft_render_map(fdf);
		hooks_handler(fdf);
		mlx_loop(fdf->mlx_ptr);
	}
	return (0);
}
