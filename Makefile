# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/16 17:50:42 by olmatske          #+#    #+#              #
#    Updated: 2026/01/20 13:12:24 by olmatske         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Minitalk

CLIENT = client.c
SERVER = server.c
CLIENT_OBJ = $(CLIENT:.c=.o)
SERVER_OBJ = $(SERVER:.c=.o)

CC = cc

CFLAGS := -Wall -Werror -Wextra -Ilib

FT_PRINTF_DIR = ./lib/ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
FT_LIBFT_DIR = ./lib/Libft
FT_LIBFT_LIB = $(FT_LIBFT_DIR)/libft.a
LIB = $(FT_PRINTF_LIB) $(FT_LIBFT_LIB)

RM = rm -f

all: server client

$(FT_PRINTF_LIB):
	make -C $(FT_PRINTF_DIR)

$(FT_LIBFT_LIB):
	make -C $(FT_LIBFT_DIR)

server: $(SERVER_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(FT_PRINTF_LIB) $(FT_LIBFT_LIB) -o $(NAME)

client: $(CLIENT_OBJ) $(LIB)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(FT_PRINTF_LIB) $(FT_LIBFT_LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)
	make -C $(FT_PRINTF_DIR) clean
	make -C $(FT_LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
















# SOURCES = server.c client.c
# OBJECTS = $(SOURCES:.c=.o)

# PRINTF_DIR = ./lib/ft_printf/
# PRINTF_LIB = $(PRINTF_DIR)libftprintf.a

# CC = gcc
# CFLAGS = -Wall -Wextra -Werror

# $(PRINTF_LIB):
# 	make -C $(PRINTF_DIR)

# all: server client

# bonus: server client

# server: server.o libft ftprintf
# 	$(CC) -o $@ $< -Llib/libft -lft -Llib/ft_printf -lftprintf

# client: client.o libft
# 	$(CC) -o $@ $< -Llib/libft -lft -Llib/ft_printf -lftprintf

# %.o: %.c
# 	$(CC) -c $(CFLAGS) $?

# libft:
# 	make -C lib/libft

# ftprintf:
# 	make -C lib/ft_printf

# clean:
# 	rm -f $(OBJECTS)
# 	make -C lib/libft clean
# 	make -C lib/ft_printf clean
	
# fclean: clean
# 	rm -f server client lib/libft/libft.a lib/ft_printf/libftprintf.a

# re: fclean all

# .PHONY: all bonus libft ftprintf clean fclean re