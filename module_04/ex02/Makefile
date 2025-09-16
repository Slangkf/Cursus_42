# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/15 09:27:48 by tclouet           #+#    #+#              #
#    Updated: 2025/09/16 17:52:20 by tclouet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = abstractClass

SOURCES = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

OBJECTS = ${SOURCES:.cpp=.o}

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(CPPFLAGS) $(SOURCES) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
