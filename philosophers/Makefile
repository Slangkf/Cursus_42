NAME = philo

SOURCES = main.c utils/error_and_free.c utils/init_philo_struct.c utils/init_prog_struct.c utils/is_eating.c utils/monitoring.c utils/parsing.c utils/routine.c utils/time_manag.c utils/utils.c

OBJECTS = ${SOURCES:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
