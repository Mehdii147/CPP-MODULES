SRC= main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
NAME= Animal
OBJ= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) Animal.hpp Dog.hpp Cat.hpp WrongAnimal.hpp WrongCat.hpp
	c++ -Wall -Wextra -Werror -std=c++98 $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all