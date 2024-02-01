/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:44:15 by malanglo          #+#    #+#             */
/*   Updated: 2024/02/01 18:33:40 by malanglo         ###   ########.fr       */
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

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define ANGLE 0.7
# define MENU 400
# define MLX_ERROR 1

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
	int max_z;

}			t_map;

typedef struct s_cam
{
	float	zoom;
	float	x_offset;
	float	y_offset;
	float	z_increase;
	int color_pallet;
}			t_cam;

typedef struct s_line
{
	t_point	start;
	t_point	end;
}			t_line;

typedef struct s_color
{
	int		start_color;
	int		start_r;
	int		start_g;
	int		start_b;
	int		end_color;
	int		end_r;
	int		end_g;
	int		end_b;
	int		delta_r;
	int		delta_g;
	int		delta_b;
}			t_color;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	t_line	*line;
}			t_image;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win_ptr;
	t_map	*map;
	t_image	*image;
	t_cam	*cam;
}			t_mlx;

size_t		ft_strlen(const char *s);
int			ft_atoi(const char *nptr);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*get_next_line(int fd);
char		**ft_strsplit(char const *s, char c);

float		ft_abs(float n);
float		ft_max(float a, float b);
float		ft_min(float a, float b);

// void		ft_iso_transform(t_point *point, float angle);

t_mlx		*init_fdf(char *file);
t_map		*ft_init_map(void);
t_point		*ft_init_point_index(int total_height, int total_width);
t_image		*ft_init_image(void);
t_cam		*ft_init_cam(void);
t_line		*ft_init_line(t_point start, t_point end);

void		ft_fill_2D_map(char *file, t_map *map);
int			ft_count_words(char const *s, char c);

void		ft_join_points(t_mlx **data);
t_map		*read_map(char *file);

void		hooks_handler(t_mlx *mlx);
int			key_scale(int key, t_mlx *mlx);
void		ft_print_menu(t_mlx *fdf);

void		ft_apply_zoom(t_point *point, float zoom);
void		ft_apply_offset(t_point *point, int x_offset, int y_offset);
void		ft_apply_x_offset(t_point *point, int x_offset);
void		ft_apply_y_offset(t_point *point, int y_offset);
void		ft_z_increase(t_point *point, float z);

void		ft_render_map(t_mlx *fdf);
void ft_render_fdf(t_mlx *fdf);

#endif