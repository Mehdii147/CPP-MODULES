# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehafiane <ehafiane@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 12:46:35 by ehafiane          #+#    #+#              #
#    Updated: 2025/07/02 16:24:16 by ehafiane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MWIGUIWTBAB

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

SRCS = Bureaucrat.cpp main.cpp Form.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) Bureaucrat.hpp Form.hpp
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all