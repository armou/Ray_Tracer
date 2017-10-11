# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daugier <daugier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/24 17:19:40 by ddufour           #+#    #+#              #
#    Updated: 2017/08/06 18:31:06 by daugier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =	ft_atoi.c \
		ft_atof.c \
		ft_bzero.c \
		ft_putendl.c \
		ft_strlen.c \
		ft_putnbr.c \
		ft_putnbrendl.c \
		ft_isdigit.c \
		ft_putstr.c \
		ft_memalloc.c \
		ft_strsplit.c \
		ft_putchar.c \
		ft_free_tab.c \
		ft_read_file.c \
		ft_strjoinfree.c \
		ft_strnew.c \
		ft_strcpy.c \
		ft_strcat.c \
		ft_memcpy.c \
		iswall.c \
		checkisdigit.c \
		ft_exit.c \
		ft_itoa.c \
		ft_strncmp.c \
		ft_convert_base.c \
		ft_convert_ten.c \
		ft_strrev.c \
		ft_recursive_power.c \
		ft_strjoin.c \
		ft_strsub.c \
		ft_memcmp.c \
		ft_charjoin.c \
		ft_printf.c \
		ft_ftoa.c \

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
