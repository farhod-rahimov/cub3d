# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btammara <btammara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/14 11:36:07 by btammara          #+#    #+#              #
#    Updated: 2021/01/07 11:51:37 by btammara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	./get_next_line/get_next_line.c \
			./get_next_line/get_next_line_utils.c \
			./parsers/parser_if_ok.c \
			./parsers/parser_map.c \
			./parsers/parser_textures.c \
			./cub3d_utils/ft_atoi.c \
			./cub3d_utils/ft_isalpha.c \
			./cub3d_utils/ft_isdigit.c \
			./cub3d_utils/ft_substr.c \
			./move_2d.c \
			./ray_cast.c \
			./check_sides_for_raycasting.c \
			./draw_lines_map_2d/draw_map_2d.c \
			./draw_lines_map_2d/check_sides.c \
			./draw_lines_map_2d/draw_sides.c \

OBJS	= 	$(SRCS:.c=.o)

NAME	= 	cub3d
CC		= 	gcc
RM		= 	rm -f

CFLAGS	= 	-Wall -Wextra -Werror

.c.o:	
			$(CC) -c $(CFLAGS) -I cub3d.h $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) libmlx.dylib -framework OpenGl -framework Appkit
			make clean

all:		$(NAME)

clean:		
			$(RM) $(OBJS) $(B_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

debug:	
			$(CC) -g $(CFLAGS) -I cub3d.h $(SRCS) libmlx.dylib -framework OpenGl -framework Appkit

.PHONY:		all clean fclean re bonus
