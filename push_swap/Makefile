NAME = push_swap
SOURCES = main.c lists/ft_init_list.c lists/ft_create_list.c lists/ft_fill_list.c lists/ft_display_list.c sorting/ft_check_and_sort.c sorting/ft_sort_list.c sorting/ft_sort_three.c sorting/ft_sort_four.c sorting/ft_sort_five.c sorting/ft_sort_more.c instructions/ft_swap.c instructions/ft_push.c instructions/ft_rotate.c instructions/ft_reverse_rotate.c utils/ft_atol.c utils/ft_check_input.c utils/ft_check_order.c utils/ft_new_strchr.c utils/ft_new_isdigit.c utils/ft_new_isalpha.c utils/ft_check_double.c utils/ft_length_list.c utils/ft_find_median_list.c utils/ft_find_pos_small.c utils/ft_find_biggest.c utils/ft_find_smallest.c utils/ft_best_path_tobig.c utils/ft_best_path_tosma.c utils/ft_index_list.c utils/ft_clone_a.c utils/ft_check_bottom_list.c utils/ft_compare_list_to_m.c utils/ft_count_moves.c utils/ft_count_sub.c utils/ft_free_list.c

OBJECTS = ${SOURCES:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

#LIBFT
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
