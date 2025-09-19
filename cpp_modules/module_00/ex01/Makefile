# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/08 13:59:57 by tclouet           #+#    #+#              #
#    Updated: 2025/08/13 13:28:20 by tclouet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = myAwesomePhoneBook

SOURCES = src/main.cpp src/PhoneBook_fill.cpp src/PhoneBook_display.cpp src/Contact_fill.cpp src/Contact_display.cpp

OBJECTS = ${SOURCES:.cpp=.o}

CC = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CPPFLAGS) -o $@ $^

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

