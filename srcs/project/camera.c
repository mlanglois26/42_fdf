/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:19:58 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/31 14:20:20 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void ft_apply_zoom(t_point *point, float zoom) 
{
    point->x *= zoom;
    point->y *= zoom;
}

void ft_apply_offset(t_point *point, int x_offset, int y_offset) 
{
    point->x -= x_offset;
    point->y -= y_offset;
}

void ft_apply_x_offset(t_point *point, int x_offset) 
{
    point->x += x_offset;
}

void ft_apply_y_offset(t_point *point, int y_offset) 
{
    point->y += y_offset;
}