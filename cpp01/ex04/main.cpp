
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

static void	replace(std::string& line, char *s1, char *s2)
{
	size_t begin;
	size_t len;
	
	begin = line.find(s1);
	len = strlen(s1);
	while (begin != std::string::npos)
	{
		line.replace(begin, len, s2);
		begin = line.find(s1, begin);
	}
}

int main(int argc, char **argv)
{
	std::fstream	inputFile;
	std::fstream	outputFile;
	std::string 	line;
	char			*file;
	char			*s1;
	char			*s2;
	
	if (argc != 4 || argv[1][0] == '\0' || argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		std::cout << "Invalid arguments: Program takes 3 non-empty arguments!" << std::endl;
		return (-1);
	}

	file = argv[1];
	s1 = strdup(argv[2]);
	s2 = strdup(argv[3]);

	inputFile.open(file, std::ios::in);
	outputFile.open(strcat(file, ".replace"), std::ios::out);
	
	if (!inputFile.is_open() || !outputFile.is_open())
	{
		std::cout << "Error while opennig a file!" << std::endl;
		return (-1);
	}
	while (getline(inputFile, line))
	{
		replace(line, s1, s2);
		outputFile << line << std::endl;
	}
	inputFile.close();
	outputFile.close();
}