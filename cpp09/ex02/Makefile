NAME = PmergeMe
CXX = c++
SRC = main.cpp  PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)
RM = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98


all: $(NAME)

$(NAME): $(OBJ) PmergeMe.hpp
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean  