# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguede <aguede@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 02:21:26 by aguede            #+#    #+#              #
#    Updated: 2023/09/23 18:55:39 by aguede           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC		= cc

CFLAGS	= -g -o -Wall -Werror -Wextra 

LIB		= ./MLX42/build/libmlx42.a

RM		= rm -f 

MAKE_MLX = cd ./MLX42/build && make

SRC = ./src/main.c ./src/ft_graphics.c ./src/ft_key_hook.c ./src/ft_move.c ./src/ft_move_up.c ./src/ft_move_down.c ./src/ft_move_right.c ./src/ft_move_left.c ./src/ft_update_image.c ./src/ft_utils.c \
		./src/ft_validate_2dmap.c ./src/ft_validate_map.c ./src/ft_validate_path.c \
		./libft/ft_split.c ./libft/ft_strlen.c \
		./ft_printf/ft_printf.c ./ft_printf/ft_putptr.c ./ft_printf/ft_simple.c \

OBJS = ${SRC:%.c=%.o}

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(MAKE_MLX)
	$(CC) $(OBJS) $(LIB) $(CFLAGS) -o $(NAME) -Iinclude -ldl -lglfw -pthread -lm -I ./MLX42/include


clean	: 
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all