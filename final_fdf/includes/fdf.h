/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:25:13 by malanglo          #+#    #+#             */
/*   Updated: 2024/03/13 17:48:13 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define WIN_WIDTH 2500
# define WIN_HEIGHT 1200
# define ANGLE 0.7
# define MENU 400

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}			t_point;

typedef struct s_map
{
	int		total_width;
	int		total_height;
	t_point	*point_index;
	double	max_z;
	double	min_z;
}			t_map;

typedef struct s_line
{
	t_point	start;
	t_point	end;
}			t_line;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_cam
{
	float	zoom;
	float	x_offset;
	float	y_offset;
	float	z_increase;
}			t_cam;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*mlx_win_ptr;
	t_map	*map;
	t_image	*image;
	t_cam	*cam;
}			t_fdf;

/* utils */

size_t		ft_strlen(const char *s);
int			ft_atoi(const char *nptr);
char		*ft_strchr(char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*get_next_line(int fd);
char		**ft_strsplit(char const *s, char c);
int			ft_atoi_base(const char *str, int str_base);

/* maths */

float		ft_abs(float n);
float		ft_max(float a, float b);
float		ft_min(float a, float b);

/* initialisation */

t_fdf		*init_fdf(char *file);
t_map		*ft_init_map(void);
t_point		*ft_init_point_index(int total_height, int total_width);

t_image		*ft_image_data(t_fdf *fdf);

/* fill struct */

void		ft_render_map(t_fdf *fdf);
void		ft_render_line(t_fdf *fdf, t_point start, t_point end);
void		ft_iso_transform(t_point *point, float angle);
void		ft_algo_bres(t_point start, t_point end, t_fdf *fdf);
void		my_pixel_put(t_fdf *fdf, int x, int y, int color);
int			ft_count_words(char const *s, char c);

t_map		*fill_map_struct(char *file);
void		ft_get_points_data(char *file, t_map *map);
int			ft_get_map_dimensions(char *file, int *height, int *width);
int			ft_get_color(char *line, int i_axis);
int			ft_get_z(char *line, int i_axis);

/* end program */

int			cross_close_window(t_fdf *fdf);
int			escape_close_window(int key, t_fdf *fdf);

/* hooks */

void		hooks_handler(t_fdf *fdf);
void		ft_set_cam_default(t_fdf *fdf);

/* background & menu */

void		project_background(t_fdf *fdf);
void		project_menu(t_fdf *fdf);

/* color */

int			color(t_point start, t_point end);
void		add_map_default_colors(t_map *map);

/* point actions */

void		ft_z_increase(t_point *point, float z);
void		ft_apply_y_offset(t_point *point, int y_offset);
void		ft_apply_x_offset(t_point *point, int x_offset);
void		ft_apply_zoom(t_point *point, float zoom);

#endif