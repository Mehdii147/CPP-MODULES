NAME = weapon
SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
HDR = Weapon.hpp HumanA.hpp HumanB.hpp
OBJ =$(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

all: $(NAME)

$(NAME)	: $(OBJ) $(HDR)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all