/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:53:39 by malanglo          #+#    #+#             */
/*   Updated: 2024/02/01 15:07:23 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void ft_print_menu(t_mlx *fdf)
{
    int y;
    void *mlx;
    void *win;

    y = 0;
    mlx = fdf->mlx_ptr;;
    win = fdf->mlx_win_ptr;
    
    mlx_string_put(mlx, win, 160, y += 40, 0xffffff, "MENU FDF");
    mlx_string_put(mlx, win, 115, y += 40, 0xffffff, "Liste des deplacements");
    mlx_string_put(mlx, win, 50, y += 70, 0xffffff, "Pour zoomer : press '+' ou '-'");
    mlx_string_put(mlx, win, 50, y += 40, 0xffffff, "Pour deplacer l origine en X : press 'l' ou 'r'");
    mlx_string_put(mlx, win, 50, y += 40, 0xffffff, "Pour deplacer l origine en Y : press 'd' ou 'u'");
    mlx_string_put(mlx, win, 50, y += 40, 0xffffff, "Pour modifier Z : press 'f' ou 'g'");
}