/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:44:15 by malanglo          #+#    #+#             */
/*   Updated: 2024/01/30 18:06:48 by malanglo         ###   ########.fr       */
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

# define WIN_WIDTH			1920
# define WIN_HEIGHT			1080

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
}			t_map;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_image;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win_ptr;
	t_map	*map;
	t_image	*image;
	int		zoom;
}			t_mlx;

size_t		ft_strlen(const char *s);
int			ft_atoi(const char *nptr);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*get_next_line(int fd);
char		**ft_strsplit(char const *s, char c);

int	ft_abs(int n);
int	ft_max(int a, int b);
int	ft_min(int a, int b);

void transform(t_point *point, float angle);

t_map *ft_init_map(void);
t_point *ft_init_point_index(int total_height, int total_width);
t_image *ft_init_image(void);

void ft_fill_2D_map(char *file, t_map *map);
int	ft_count_words(char const *s, char c);

void ft_join_points(t_mlx **data);
t_map *read_map(char *file);

void hooks_handler(t_mlx *mlx);
#endif