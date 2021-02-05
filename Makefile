# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btammara <btammara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/14 11:36:07 by btammara          #+#    #+#              #
#    Updated: 2021/02/05 09:38:29 by btammara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	./parser/parser_if_ok.c \
			./parser/parser_map.c \
			./parser/parser_textures.c \
			./cub3d_utils/ft_atoi.c \
			./cub3d_utils/ft_isalpha.c \
			./cub3d_utils/ft_isdigit.c \
			./cub3d_utils/ft_substr.c \
			./cub3d_utils/ft_strjoin_3.c \
			./cub3d_utils/ft_error.c \
			./cub3d_utils/ft_strncmp.c \
			./cub3d_utils/ft_strdup.c \
			./cub3d_utils/ft_strcpy.c \
			./cub3d_utils/ft_strlen.c \
			./cub3d_utils/move_2d.c \
			./raycast/ray_cast.c \
			./raycast/check_sides_walls_for_raycasting.c \
			./raycast/check_sides_sprites_for_raycasting.c \
			./raycast/check_sides_walls.c \
			./raycast/check_sides_sprites.c \
			./cub3d_utils/ft_screenshot.c

OBJS	= 	$(SRCS:.c=.o)

NAME	= 	cub3D
CC		= 	gcc
RM		= 	rm -f

CFLAGS	= 	-Wall -Wextra -Werror

.c.o:	
			$(CC) -c $(CFLAGS) -I cub3d.h $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			cd ./minilibx_mms_20200219 && make && cd ..
			cp ./minilibx_mms_20200219/libmlx.dylib ./
			$(CC) -o $(NAME) $(OBJS) libmlx.dylib -framework OpenGl -framework Appkit

all:		$(NAME)

clean:		
			$(RM) $(OBJS) $(B_OBJS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) libmlx.dylib

re:			fclean all

debug:	
			$(CC) -g $(CFLAGS) -I cub3d.h $(SRCS) libmlx.dylib -framework OpenGl -framework Appkit

.PHONY:		all clean fclean re bonus
