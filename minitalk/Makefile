# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saozcan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 10:05:59 by saozcan           #+#    #+#              #
#    Updated: 2022/02/15 10:19:42 by saozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I./

CLIENT = $(CC) $(CFLAGS) client.c -o client

SERVER = $(CC) $(CFLAGS) server.c -o server

all:
	$(CLIENT)
	$(SERVER)

re: fclean all

clean:
	rm -rf client server

fclean:
	rm -rf client server

.PHONY: re fclean clean all
