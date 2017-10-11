# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daugier <daugier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/12 17:05:44 by ddufour           #+#    #+#              #
#    Updated: 2017/10/05 23:19:35 by aoudin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

RM = rm -f

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I header/

SDL2_F = -framework SDL2 -framework SDL2_ttf -framework SDL2_image -F ./Libs/frameworks/

SDL2_P = -rpath @loader_path/Libs/frameworks/

SDL2_I = -I ./Libs/frameworks/SDL2.framework/Headers

SDL2_TTF_I = -I ./Libs/frameworks/SDL2_ttf.framework/Headers

SDL2_IMG_I = -I ./Libs/frameworks/SDL2_image.framework/Headers

LIBS = -LLibs/libft/ #-LLibs/minilibx_macos/

SRCS =	srcs/main.c \
		srcs/draw.c \
		srcs/list_info.c \
		srcs/opencl.c \
		srcs/kernel_cl.c \
		srcs/rayhit.c \
		srcs/vector.c \
		srcs/torus.c \
		srcs/quartic_solver.c \
		srcs/cubic_solver.c \
		srcs/moove.c \
		srcs/moove2.c \
		srcs/moove3.c \
		srcs/event.c \
		srcs/event2.c \
		srcs/event3.c \
		srcs/event4.c \
		srcs/event5.c \
		srcs/event6.c \
		srcs/parse_scene.c \
		srcs/parse_scene_2.c \
		srcs/parse_scene_3.c \
		srcs/parse_object.c \
		srcs/check_obj.c \
		srcs/util_parse2.c \
		srcs/util_parse.c \
		srcs/parse.c \
		srcs/trace.c \
		srcs/hitobject.c \
		srcs/init.c \
		srcs/interface.c \
		srcs/hitobject2.c \
		srcs/vector2.c \
		srcs/rayhit2.c \
		

OBJ = $(SRCS:.c=.o)

$(NAME) : $(OBJ)
	@make -s -C libs/libft
	@echo "Libft Compiled"
	@$(CC) $(LIBS) -lft  -framework OpenGL -framework AppKit -lncurses -o $@ $^ $(SDL2_P) $(SDL2_F) $(SDL2_I) $(SDL2_TTF_I) $(SDL2_IMG_I) -framework OpenCL
	@echo "rt Compiled"

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean :
	@make clean -s -C libs/libft
	@echo ".o Libft delete"
	@$(RM) $(OBJ)
	@echo ".o rt delete"

fclean : clean
	@$(RM) libs/libft/libft.a
	@echo "libft.a delete"
	@$(RM) $(NAME)
	@echo "rt delete"

re : fclean all
