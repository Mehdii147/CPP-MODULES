#include "Replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4) {
		std::cerr << "Usage : ./replace file_input string1 string2" << std::endl; 
		return -1;
	}
	else {
		Replace tryMe(av[1]);
		tryMe.replace(av[2], av[3]);
	}
	return (0);
}