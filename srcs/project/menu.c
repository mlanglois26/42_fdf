/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:54:47 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/13 11:35:41 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	project_background(t_fdf *fdf)
{
	int	*img;
	int	i;

	img = (int *)fdf->image->addr;
	i = 0;
	while (i < WIN_WIDTH * WIN_HEIGHT)
	{
		if (i % WIN_WIDTH < MENU)
			img[i] = 0x23364c;
		else
			img[i] = 0x172432;
		i++;
	}
}

void	project_menu(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx_ptr;
	win = fdf->mlx_win_ptr;
	mlx_string_put(mlx, win, 160, y += 40, 0xffffff, "MENU FDF");
	mlx_string_put(mlx, win, 115, y += 40, 0xffffff, "Liste des deplacements");
	mlx_string_put(mlx, win, 50, y += 70, 0xffffff,
		"Pour zoomer : press '+' ou '-'");
	mlx_string_put(mlx, win, 50, y += 40, 0xffffff,
		"Pour deplacer l origine en X : press 'l' ou 'r'");
	mlx_string_put(mlx, win, 50, y += 40, 0xffffff,
		"Pour deplacer l origine en Y : press 'd' ou 'u'");
	mlx_string_put(mlx, win, 50, y += 40, 0xffffff,
		"Pour modifier Z : press 'f' ou 'g'");
}
