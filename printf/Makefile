NAME = libftprintf.a

SOURCES = main.c ft_printf/ft_printf.c ft_printf/ft_printchar.c ft_printf/ft_printstr.c ft_printf/ft_printadress.c ft_printf/ft_printnbr.c ft_printf/ft_printunbr.c ft_printf/ft_printhexa_low.c ft_printf/ft_printhexa_upp.c utils/ft_strchr.c

OBJECTS = ${SOURCES:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
