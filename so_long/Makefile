NAME = so_long
SOURCES = main.c utils/image_manag.c utils/image_manag2.c utils/keyboard_manag.c utils/parsing.c utils/parsing2.c utils/parsing3.c utils/utils.c utils/utils2.c utils/utils3.c

OBJECTS = ${SOURCES:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx

#Include Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC = -L$(LIBFT_DIR) -lft

all: $(LIBFT) $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(LIBFT) $(INC)
$(LIBFT):
	 @make all -C$(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	@make fclean -C$(LIBFT_DIR)
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
