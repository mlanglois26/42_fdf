# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 15:23:29 by malanglo          #+#    #+#              #
#    Updated: 2024/03/22 14:53:06 by malanglo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX_FILE	=	libmlx.a

MLX_FLAG	=	-lX11 -lXext -lm

MLX_PATH	=	./minilibx-linux/

MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))

MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)

SRCS = 			srcs/utils/ft_atoi.c\
				srcs/utils/ft_atoi_base.c\
				srcs/utils/ft_split.c\
				srcs/utils/gnl.c\
				srcs/utils/gnl_utils.c\
				srcs/project/parsing.c\
				srcs/project/colors.c\
				srcs/project/draw.c\
				srcs/project/init_1.c\
				srcs/project/camera.c\
				srcs/project/collect_map_data.c\
				srcs/project/fill_map_struct.c\
				srcs/project/line_action.c\
				srcs/project/utils.c\
				srcs/project/hooks.c\
				srcs/project/menu.c\
				srcs/project/end_program.c\
				srcs/project/main.c\

OBJS =		$(SRCS:.c=.o)

all: $(NAME) $(MLX_LIB) 

mlx:	$(MLX_PATH)
	@make -sC $(MLX_PATH)

$(NAME): mlx $(OBJS)
	$(CC) $(OBJS) $(MLX_EX) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


