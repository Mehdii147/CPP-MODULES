#include "Phonebook.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		std::cout << "No arguments needed!" << std::endl;
		return (0);
	}
	std::string	str;
	Phonebook 	pb1;
	while (str != "EXIT")
	{
		std::cout << "Enter a command > ";
		std::getline(std::cin, str);
		if (str == "ADD")
			pb1.add();
		else if (str == "SEARCH")
			pb1.search();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}