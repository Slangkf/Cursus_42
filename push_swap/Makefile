NAME = push_swap
SOURCES = instructions/create_list.c instructions/fill_list.c instructions/display_list.c instructions/swap.c instructions/push.c instructions/rotate.c instructions/reverse_rotate.c utils/ft_atol.c utils/ft_count_sub.c main_functions/main.c

OBJECTS = ${SOURCES:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

#LIBFT
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC = -L$(LIBFT_DIR) -lft
all: 	$(LIBFT) $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME) $(LIBFT) $(INC)
$(LIBFT):
	 	@make all -C$(LIBFT_DIR)

clean:
	@make fclean -C$(LIBFT_DIR)
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
