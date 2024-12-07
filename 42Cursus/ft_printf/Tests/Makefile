NAME = libftprintf.a
SOURCES = 	ft_printf.c \
		ft_printchar.c \
		ft_printstr.c \
		ft_printadress.c \
		ft_printnbr.c \
		ft_printunbr.c \
		ft_printhexa_low.c \
		ft_printhexa_upp.c \
		ft_strchr.c

OBJECTS = ${SOURCES:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -I./ -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

