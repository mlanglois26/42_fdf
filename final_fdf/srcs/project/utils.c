/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:50:36 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/13 11:38:22 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

float	ft_abs(float n)
{
	if (n < 0.0)
		return (-n);
	else
		return (n);
}

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	ft_min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}


// void	my_pixel_put(t_fdf *fdf, int x, int y, int color)
// {
// 	char	*offset;

// 	if (y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
// 	{
// 		offset = fdf->image->addr + (y * fdf->image->line_length + x * (fdf->image->bpp / 8));
// 		printf("offset = %s\n", offset);
// 		*(unsigned int *)offset = color;
// 	}
// }

void	my_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	int	offset;

	if (x >= MENU && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)	
	{
		offset = (y * fdf->image->line_length) + ((fdf->image->bpp / 8) * x);
		*(unsigned int *)(fdf->image->addr + offset) = color;
	}
}

