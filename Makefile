# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 17:50:42 by olmatske          #+#    #+#              #
#    Updated: 2026/01/16 18:03:34 by olmatske         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

PRINTF_DIR = ./lib/ft_printf/
PRINTF_LIB = $(PRINTF_DIR)libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

all: server client

bonus: server client

server: server.o libft ftprintf
	$(CC) -o $@ $< -Llib/libft -lft -Llib/ft_printf -lftprintf

client: client.o libft
	$(CC) -o $@ $< -Llib/libft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C lib/libft

ftprintf:
	make -C lib/ft_printf

clean:
	rm -f $(OBJECTS)
	make -C lib/libft clean
	make -C lib/ft_printf clean
	
fclean: clean
	rm -f server client lib/libft/libft.a lib/ft_printf/libftprintf.a

re: fclean all

.PHONY: all bonus libft ftprintf clean fclean re