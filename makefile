# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asumerag <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/06 02:36:17 by asumerag          #+#    #+#              #
#    Updated: 2021/02/06 14:32:47 by asumerag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

LIB = -L./lib/ -lft -lgnl -lmlx

NAME = cub3D

HDR = hdr/cub3d.h

SRC = src/cub3d.c \
	  src/cub_parser.c \
	  src/map_parametrs.c \
	  src/map_parser.c \
	  src/raycasting.c \
	  src/plr_init.c \
	  src/plr_move.c \
	  src/screenshot.c \
	  src/sprite.c \
	  src/sprite_sort.c \
	  src/struct_init.c \
	  src/utils.c \
	  src/key_hook.c \
	  src/raycasting_utils.c \
	  src/f_c_utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAG) $(OBJ) $(LIB) -o $(NAME)
	cp lib/libmlx.dylib .
	echo "Done"

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
	@rm -f $(NAME).bmp
	@rm -f libmlx.dylib
	@echo "Clean"

fclean: clean
	@rm -f $(NAME)

norma:
	@norminette -R CheckForbiddenSourceHeader $(SRC) $(HDR)

re: fclean all

.PHONY: all, clean, fclean, norma, re
