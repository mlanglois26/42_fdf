/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brouillon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:59:47 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/30 13:00:20 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_get_map_dimensions(char *file, int *height, int *width)
{
    int fd;
    char *line;

    fd = open(file, O_RDONLY, 0);
    if (fd < 0)
        return (-1);
    line = get_next_line(fd);
    if (!line)
    {
        close(fd);
        return (-1);
    }
    *width = ft_count_words(line, ' ');
    *height = 1;
    free(line);
    while ((line = get_next_line(fd)) != NULL)
    {
        (*height)++;
        free(line);
    }
    close(fd);
    return (0);
}


int ft_get_z(char *line, int i_axis)
{
    char **num;
    int z;
    int i;

    num = ft_strsplit(line, ' ');
    z = ft_atoi(num[i_axis]);
    i =0;
    while (num[i] != NULL)
    {
        free(num[i]);
        i++;
    }
    free(num);
    return (z);
}

void	ft_get_y_x(char *line, t_map *map, int j_axis, int i_axis)
{
    char ** z_res;
    int i;
    
    map->point_index[j_axis * map->total_width + i_axis].y = j_axis;
    map->point_index[j_axis * map->total_width + i_axis].x = i_axis;
    map->point_index[j_axis * map->total_width + i_axis].z = ft_get_z(line, i_axis); 
}

void ft_fill_2D_map(char *file, t_map *map)
{
    int fd;
    char *line;
    int j_axis;
    int i_axis;

    fd = open(file, O_RDONLY);
    
    j_axis = 0;
    while ((line = get_next_line(fd)) != NULL && j_axis < map->total_height)
    {
        i_axis = 0;
		while (i_axis < map->total_width)
        {
			ft_get_y_x(line, map, j_axis, i_axis);
            i_axis++;
        }
        free(line);
        j_axis++;
    }
    close(fd);
}

t_point *init_point_index(int total_height, int total_width)
{
    t_point *point_index;
    int j_axis;
    int i_axis;

    point_index = malloc(total_width * total_height * sizeof(t_point));
    if (!point_index)
		return (NULL);
	j_axis = 0;
	while (j_axis < total_height)
	{
		i_axis = 0;
		while (i_axis < total_width)
		{
            point_index[j_axis * total_width + i_axis].y = 0;
            point_index[j_axis * total_width + i_axis].x = 0;
			point_index[j_axis * total_width + i_axis].z = 0;
			point_index[j_axis * total_width + i_axis].color = 0;
			i_axis++;
		}
		j_axis++;
	}
	return (point_index);
}


t_map *init_map(void)
{
    t_map *map;

    map = malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->point_index = NULL;

    map->total_width = 0;
    map->total_height = 0;
    return (map);
}

t_map *read_map(char *file)
{
    t_map *map;
    int width;
    int height;

    if (ft_get_map_dimensions(file, &height, &width) == -1)
        return (NULL);
    map = init_map();
    if (!map)
        return (NULL);
    map->total_height = height;
    map->total_width = width;
    map->point_index = init_point_index(map->total_height, map->total_width);
    if (!map->point_index)
    {
        free(map);
        return (NULL);
    }
    ft_fill_2D_map(file, map);
    return (map);
}

t_image *init_image(void)
{
    t_image *image = malloc(sizeof(t_image));
    if (!image)
        return NULL;

    image->img_ptr = NULL;
    image->addr = NULL;
    image->bpp = 0;
    image->line_length = 0;
    image->endian = 0;

    return image;
}

#define	SIDE_LEN		1980
#define MLX_ERROR 1
#define X				200
#define Y				200


t_mlx *init_fdf(char *file)
{
    t_mlx *fdf;

    fdf = malloc(sizeof(t_mlx));
    if (!fdf)
        return NULL;

    fdf->mlx_ptr = mlx_init();
    if (!fdf->mlx_ptr)
    {
        free(fdf);
        return NULL;
    }

    fdf->mlx_win_ptr = mlx_new_window(fdf->mlx_ptr, SIDE_LEN, SIDE_LEN, "Hello world!");
    if (!fdf->mlx_win_ptr)
    {
        free(fdf);
        return NULL;
    }

    fdf->image = init_image();
    if (!fdf->image)
    {
        free(fdf);
        return NULL;
    }

    fdf->image->img_ptr = mlx_new_image(fdf->mlx_ptr, SIDE_LEN, SIDE_LEN);
    if (!fdf->image->img_ptr)
    {
        free(fdf);
        return NULL;
    }

    // fdf->image->addr = mlx_get_data_addr(fdf->image->img_ptr, &fdf->image->bpp, &fdf->image->line_length, &fdf->image->endian);
	
    fdf->map = read_map(file);
   fdf->zoom = 10;

    return fdf;
}


///////////////////////////////////////////////////////////////////////////////////



void	my_pixel_put(t_image *img, int x, int y, int color)
{
	int	offset;


	printf("entering my_pixel_put\n");

	offset = (img->line_length * y) + (x * (img->bpp / 8));
	*((unsigned int *)(offset + img->addr)) = color;
}


void color_screen(t_mlx *data, int color)
{
    int y;
    int x;

    y = 0;
    
    while (y < SIDE_LEN)
    {
        x = 0;
        while (x < SIDE_LEN)
        {
            my_pixel_put(data->image, x, y, color);
            ++x;
        }
        ++y;
    }
}


int point_color = 0xffffff;

void draw_points_on_window(t_mlx *mlx)
{
    t_map *map = mlx->map;
    int width = mlx->map->total_width;
    int height = mlx->map->total_height;

    if (map == NULL || map->point_index == NULL)
    {
        printf("La carte est vide.\n");
        return;
    }

    int j_axis = 0;
    while (j_axis < height)
    {
        int i_axis = 0;
        while (i_axis < width)
        {
            int x = map->point_index[j_axis * width + i_axis].x * mlx->zoom;
            int y = map->point_index[j_axis * width + i_axis].y * mlx->zoom;

            my_pixel_put(mlx->image, x, y, point_color);
            i_axis++;
        }
        j_axis++;
    }
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win_ptr, mlx->image->img_ptr, 0, 0);
}


//////////////////////////////////////////////////////////////////////////////////////////////////

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void transform(t_point *point, float angle) 
{
    float new_x;
    float new_y;
    
    new_x = (point->x - point->y) * cos(angle);
    new_y = (point->x + point->y) * sin(angle) - point->z;
    
    point->x = new_x;
    point->y = new_y;
}

void ft_apply_zoom(t_point *point, float zoom, int x_offset, int y_offset) 
{
    point->x *= zoom;
    point->y *= zoom;
    point->x += x_offset;
    point->y += y_offset;
}

void ft_algo_bres(t_point start, t_point end, t_mlx *data)
{
	float x_distance;
	float y_distance;
	int max;
	int color;

	printf("start x = %f\n", start.x);
    printf("end x = %f\n", end.x);
    printf("start y = %f\n", start.y);
    printf("end x = %f\n", start.y);
	printf("enter algo\n");

	// start.x *= data->zoom;
	// end.x *= data->zoom;
	// start.y *= data->zoom;
	// end.y *= data->zoom;
	
   	ft_apply_zoom(&start, data->zoom, 425, 60);
    ft_apply_zoom(&end, data->zoom, 425, 60);
	
	transform(&start, 0.6);
    transform(&end, 0.6);
	
	// x_distance = (end.x - start.x) * data->zoom;
	// printf("x_distance = %f\n", x_distance);
	// y_distance = (end.y - start.y) * data->zoom;
	// printf("y_distance = %f\n", y_distance);

	x_distance = end.x - start.x;
    printf("x_distance = %f\n", x_distance);
	y_distance = end.y - start.y;
    printf("y_distance = %f\n", y_distance);

	max = ft_max(ft_abs(x_distance), ft_abs(y_distance));
    x_distance /= max;
    y_distance /= max;
	end.color = (end.z || start.z) ? 0xfc0345 : 0xBBFAFF;
	end.color = (end.z != start.z) ? 0xfc031c : end.color;

 	while ((int)(start.x - end.x) || (int)(start.y - end.y))
    {
		printf("enter while\n");
	    printf("start.x: %f, start.y: %f, end.x: %f, end.y: %f\n", start.x, start.y, end.x, end.y);
		// my_pixel_put(data->image, (int)start.x, (int)start.y, end.color);
		mlx_pixel_put(data->mlx_ptr, data->mlx_win_ptr, start.x, start.y, end.color);

		start.x += x_distance;
		start.y += y_distance;
    }
	// mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->image->img_ptr, 0, 0);

}


void ft_join_points(t_mlx **data)
{
	int j_axis;
	int i_axis;
	t_point start;
	t_point end;
	int total_width = (*data)->map->total_width;
	printf("Before loop\n");
	j_axis = 0;
	while (j_axis < (*data)->map->total_height)
	{
		i_axis = 0;
		while (i_axis < (*data)->map->total_width)
		{
			printf("Inside loop - j_axis: %d, i_axis: %d\n", j_axis, i_axis);
			if (i_axis < (*data)->map->total_width - 1)
            {
                start.x = i_axis;
                start.y = j_axis;
				start.z = (*data)->map->point_index[j_axis * total_width + i_axis].z;

                end.x = i_axis + 1;
                end.y = j_axis;
				end.z = (*data)->map->point_index[j_axis * total_width + i_axis + 1].z;
				printf("coucou\n");
                ft_algo_bres(start, end, (*data));
            }
            if (j_axis < (*data)->map->total_height - 1)
            {
                start.x = i_axis;
                start.y = j_axis;
				start.z = (*data)->map->point_index[j_axis *total_width + i_axis].z;

                end.x = i_axis;
                end.y = j_axis + 1;
				end.z = (*data)->map->point_index[j_axis * total_width + i_axis + 1].z;
                
				ft_algo_bres(start, end, (*data));
            }
			i_axis++;
		}
		j_axis++;
	}
	// mlx_put_image_to_window((*data)->mlx_ptr, (*data)->mlx_win_ptr, (*data)->image->img_ptr, 0, 0);
	printf("After loop\n");
}


int f(int key, t_mlx *data)
{
    if (key == XK_r)
    {
        point_color = 0xff0000;
        // draw_points_on_window(data);
		ft_join_points(&data);
    }   
    else if (key == XK_g)
    {
        point_color = 0xff00;
        // draw_points_on_window(data);
		ft_join_points(&data);
    }
    else if (key == XK_b)
    {
        point_color = 0xff;
        // draw_points_on_window(data);
		ft_join_points(&data);
    }
    else if (key == XK_Escape)
    {
        // destroy la fenetre ici
        exit (1);
    }
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win_ptr, data->image->img_ptr, 0, 0);
    return (0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
    t_mlx *mlx;

    mlx = init_fdf(argv[1]);

    if (!mlx)
        return (MLX_ERROR);

    mlx_key_hook(mlx->mlx_win_ptr, f, mlx);
    // draw_points_on_window(mlx);
	ft_join_points(&mlx);
    mlx_loop(mlx->mlx_ptr);

    return (0);
}