/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:11:31 by malanglo          #+#    #+#             */
/*   Updated: 2024/02/01 18:12:04 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


t_color	*color_pallet_init(int min_color, int max_color)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
		return (NULL);
	color->start_color = min_color;
	color->start_r = (0xff0000 & min_color) >> 16;
	color->start_g = (0x00ff00 & min_color) >> 8;
	color->start_b = (0x0000ff & min_color);
	color->end_color = max_color;
	color->end_r = (0xff0000 & max_color) >> 16;
	color->end_g = (0x00ff00 & max_color) >> 8;
	color->end_b = (0x0000ff & max_color);
	color->delta_r = (color->end_r - color->start_r);
	color->delta_g = (color->end_g - color->start_g);
	color->delta_b = (color->end_b - color->start_b);
	return (color);
}

enum e_bool
{
	FALSE,
	TRUE
};

// void	ft_apply_colors(t_mlx *fdf, t_point *point)
// {
// 	t_color	*color;

// 	color = NULL;

// 	if (point->z >= 0)
// 	{
// 		color = color_pallet_init(0x303030, 0xffa500);
// 		point->color = ft_color_pix(color, ft_abs(point->z), \
// 			ft_abs(fdf->map->max_z));
// 		free(color);
// 	}
// 	else
// 	{
// 		color = color_pallet_init(0x303030, 0x0492c2);
// 		point->color = ft_color_pix(color, ft_abs(point->z), \
// 			ft_abs(fdf->map->max_z));
// 		free(color);
// 	}
// }

void ft_apply_colors(t_point *point)
{
	int color;


	if (point->z > 9)
	{
		color = 0xffffff;
		point->color = color;
	}
	else if (point->z > 1 && point->z < 5)
	{
		color = 0xff0000;
		point->color = color;
		
	}
	else
	{
		color = 0x0492C2;
		point->color = color;

	}
}

int ft_color_pix(t_color *color, int line, int line_len)
{
    float progress;

    progress = (float)line / line_len;
    return (color_gradient(color, progress));
}


void	pixel_to_image(t_image *image, float x, float y, int color)
{
	int	pixel;

	pixel = ((int)y * image->line_length) + ((int)x * 4);
	if (image->endian == 1)
	{
		image->addr[pixel + 0] = (color >> 24);
		image->addr[pixel + 1] = (color >> 16) & 0xff;
		image->addr[pixel + 2] = (color >> 8) & 0xff;
		image->addr[pixel + 3] = (color) & 0xff;
	}
	else if (image->endian == 0)
	{
		image->addr[pixel + 0] = (color) & 0xff;
		image->addr[pixel + 1] = (color >> 8) & 0xff;
		image->addr[pixel + 2] = (color >> 16) & 0xff;
		image->addr[pixel + 3] = (color >> 24);
	}
}


t_color *ft_init_color(t_point start, t_point end)
{
    t_color *color;

    color = malloc(sizeof(t_color));
    if (!color)
        return (NULL);
    color->start_color = start.color;
    color->start_r = (0xff0000 & start.color) >> 16;
    color->start_g = (0x00ff00 & start.color) >> 8;
    color->start_b = (0x0000ff & start.color);
    
    color->end_color = end.color;
    color->end_r = (0xff0000 & end.color) >> 16;
    color->end_g = (0x00ff00 & end.color) >> 8;
    color->end_b = (0x0000ff & end.color);
    
    color->delta_r = (color->end_r - color->start_r);
    color->delta_g = (color->end_g - color->start_g);
    color->delta_b = (color->end_b - color->start_b);
    return (color);
}


static int	color_gradient(t_color *color, float progress)
{
	int		r;
	int		g;
	int		b;

	r = color->delta_r * progress;
	if (r < -255)
		r = 0;
	else if (r > 255)
		r = 255;
	r = r << 16;
	g = color->delta_g * progress;
	if (g < -255)
		g = 0;
	else if (g > 255)
		g = 255;
	g = g << 8;
	b = color->delta_b * progress;
	if (b < -255)
		b = 0;
	else if (b > 255)
		b = 255;
	return (color->start_color + r + g + b);
}
