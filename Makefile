# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 12:41:59 by malanglo          #+#    #+#              #
#    Updated: 2024/01/30 17:58:22 by malanglo         ###   ########.fr        #
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
				srcs/utils/ft_split.c\
				srcs/utils/gnl.c\
				srcs/utils/gnl_utils.c\
				srcs/project/coordinates.c\
				srcs/project/draw.c\
				srcs/project/init.c\
				srcs/project/map.c\
				srcs/project/maths_utils.c\
				srcs/project/transform.c\
				srcs/project/key_hook.c\
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
