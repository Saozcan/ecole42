# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saozcan <saozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 13:59:45 by saozcan           #+#    #+#              #
#    Updated: 2022/02/24 19:58:13 by saozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard src/*c)
OBJS = $(SRCS:.c=.o)

BONUS = $(wildcard bonus/*c)
OBJS_BONUS = $(BONUS:.c=.o)

LIBFT_DIR	=	libft

MLX_DIR	=	minilibx

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror
MFLAGS	=	./minilibx ./minilibx/libmlx.a ./libft/libft.a \
			./ft_printf/libftprintf.a  -framework OpenGL -framework AppKit

NAME	=	so_long
RM	=	rm -rf

all:	$(NAME)

$(NAME): $(OBJS)
		make -C ./libft
		make -C ./minilibx
		make -C ./ft_printf
		gcc -o $(NAME) main.c ./src/*.c -I $(MFLAGS) $(CFLAGS) 
		
bonus:	$(OBJS_BONUS)
		make -C ./libft
		make -C ./minilibx
		make -C ./ft_printf
		gcc -o $(NAME) main.c ./bonus/*.c -I $(MFLAGS) $(CFLAGS) 
		
fclean: clean
		${RM} ./libft/*.a
		${RM} ./minilibx/*.a
		${RM} ./ft_printf/*.a
		${RM} $(NAME)
clean:
		${RM} ./libft/*.o
		${RM} ./minilibx/*.o
		${RM} ./src/*.o
		${RM} ./bonus/*.o
		${RM} ./ft_printf/*.o
		
re:		fclean all
		
.PHONY: all fclean clean re