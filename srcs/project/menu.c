/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:53:39 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/31 18:43:02 by malanglo         ###   ########.fr       */
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
    
    mlx_string_put(mlx, win, 90, y += 40, 0xffffff, "MENU FDF");
    mlx_string_put(mlx, win, 50, y += 40, 0xffffff, "Liste des deplacements");
    mlx_string_put(mlx, win, 50, y += 60, 0xffffff, "Pour zoomer : press '+' ou '-'");
    mlx_string_put(mlx, win, 50, y += 40, 0xffffff, "Pour augmenter Z : press 'u' ou '-'d");
    mlx_string_put(mlx, win, 50, y += 40, 0xffffff, "Pour deplacer l origine en X : press 'l' ou 'r'");
    mlx_string_put(mlx, win, 50, y += 40, 0xffffff, "Pour deplacer l origine en Y : press 'd' ou 'u'");
}