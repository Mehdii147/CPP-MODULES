NAME = harl
SRC = main.cpp Harl.cpp
HDR = Harl.hpp
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
