CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c	\
	ft_putadrf.c	\
	ft_putcharf.c	\
	ft_putf.c		\
	ft_puthexf.c	\
	ft_putnbrf.c	\
	ft_putstrf.c	\
	ft_putunbrf.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

#================o================o================o================o

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@

$(NAME): $(OBJ)
	ar rsc $(NAME) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
