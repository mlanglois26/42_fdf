/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:20:54 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/30 14:56:47 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void transform(t_point *point, float angle) 
{
    float new_x;
    float new_y;
    
    new_x = (point->x - point->y) * cos(angle);
    new_y = (point->x + point->y) * sin(angle) - point->z;
    
    point->x = new_x;
    point->y = new_y;
}
