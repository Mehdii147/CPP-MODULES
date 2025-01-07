NAME = my_phonebook

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Contact.cpp Phonebook.cpp Helpers.cpp main.cpp
OBJ =$(SRC:.cpp=.o)
RM = rm -rf

all	: $(NAME)

$(NAME)	: $(OBJ) Phonebook.hpp Contact.hpp Helpers.hpp
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all