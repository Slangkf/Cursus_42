# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclouet <tclouet@42paris.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/15 09:27:48 by tclouet           #+#    #+#              #
#    Updated: 2025/10/16 12:28:35 by tclouet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		mutated

CXX =		c++

CXXFLAGS =	-Wall -Wextra -Werror -std=c++98

HEADERS =	MutantStack.hpp MutantStack.tpp

SOURCES =	main.cpp

OBJDIR =	objects

OBJECTS =	$(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)
	
$(OBJDIR)/%.o: %.cpp $(HEADERS) | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
