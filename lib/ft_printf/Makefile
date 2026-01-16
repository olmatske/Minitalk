NAME = libftprintf.a

SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c hexconvert.c ptrconvert.c \
		ft_unsignedputnbr.c

LIBFT_DIR = ./Libft
LIBFT = ./Libft/libft.a

OBJCS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

all: $(NAME)

$(LIBFT) :
	make -C ./Libft

$(NAME): $(OBJCS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJCS)

clean:
	$(RM) $(OBJCS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re:
	$(MAKE) fclean
	$(MAKE) all

party:
	curl parrot.live

.PHONY: all clean fclean re party
