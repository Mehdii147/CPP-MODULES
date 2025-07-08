NAME = identify

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES = main.cpp Base.cpp Functions.cpp
OBJECTS = $(SOURCES:.cpp=.o)

HEADERS = Base.hpp A.hpp B.hpp C.hpp Functions.hpp

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.cpp 
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
