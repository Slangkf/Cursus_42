NAME = push_swap
SOURCES = lists/ft_init_list.c lists/create_list.c lists/fill_list.c lists/display_list.c sorting/ft_check_order.c sorting/ft_sort_list.c sorting/ft_sort_three.c sorting/ft_sort_four.c sorting/ft_sort_five.c sorting/ft_find_smallest.c instructions/swap.c instructions/push.c instructions/rotate.c instructions/reverse_rotate.c utils/ft_atol.c utils/ft_check_input.c utils/ft_new_strchr.c utils/ft_new_isdigit.c utils/ft_new_isalpha.c utils/ft_check_double.c main/main.c

OBJECTS = ${SOURCES:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Include LIBFT
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC = -L$(LIBFT_DIR) -lft

all: $(LIBFT) $(NAME)

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
