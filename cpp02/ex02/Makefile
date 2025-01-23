SRC= Fixed.cpp main.cpp
NAME= ortho
OBJ= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) Fixed.hpp
	c++ -Wall -Wextra -Werror -std=c++98 $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all