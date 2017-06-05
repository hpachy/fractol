# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpachy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/15 13:34:13 by hpachy            #+#    #+#              #
#    Updated: 2017/01/14 14:16:46 by hpachy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fractol
LIB = libft/

HEAD = libft/
HEAD2 = Include/
FLAGS = -Wall -Werror -Wextra -O3
SRC = Src/app_color.c Src/color.c Src/error_and_affichage.c Src/fractaljulia.c Src/fractal_burning.c Src/fractol_my_fract.c Src/fratolmandelbrot.c Src/init_fract.c Src/key_hook.c Src/main.c Src/mousehook.c
OBJ = app_color.o color.o error_and_affichage.o fractaljulia.o fractal_burning.o fractol_my_fract.o fratolmandelbrot.o init_fract.o key_hook.o main.o mousehook.o

LIBX =-lmlx -lft -framework OpenGL -framework appKit

all: libft $(NAME)

.PHONY : libft clean fclean re

libft :
	@make -C libft

$(NAME) :
	@echo "\033[33;32mCompilation executable : $(NAME)"
	@gcc $(FLAG) -c $(SRC) -I $(HEAD) -I $(HEAD2)
	@echo "\033[33;32mCompilation .o"
	@gcc -o $(NAME)  -L $(LIB) $(OBJ) $(LIBX)
	@echo "\033[33;32m===> OK <==="

clean :
	@echo "\033[31mremove Fractol/*.o"
	@rm -f $(OBJ)
	@echo "\033[33;32m===> OK <==="

fclean :	clean
	@echo "\033[31mremove executable : $(NAME)"
	@rm -f $(NAME)
	@echo "\033[33;32m===> OK <==="

re :	fclean all
