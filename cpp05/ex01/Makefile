# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehafiane <ehafiane@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 12:46:35 by ehafiane          #+#    #+#              #
#    Updated: 2025/06/25 13:22:20 by ehafiane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MWIGUIWTBAB

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 

SRCS = Bureaucrat.cpp main.cpp Form.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) Bureaucrat.hpp Form.hpp
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all