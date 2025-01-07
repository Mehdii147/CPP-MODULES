#include "Helpers.hpp"

int if_all_spaces(const std::string &s)
{
	size_t i = 0;
	size_t size = s.size();

	while (i < size && isspace(s[i]))
		i++;
	if (i == size)
        return 1;
	else 
		return 0;
}

int is_valid_input(const std::string& str, int type)
{
    size_t i = 0;
	
	if (type == 1)
	{
		while (i < str.size() && std::isdigit(str[i]))
			i++;
		if (i == str.size() && !str.empty())
			return 1;
		else 
			return 0;
	}
	i = 0;
	if (if_all_spaces(str))
		return (0);
    while (i < str.size() && std::isprint(str[i]))
        i++;
    if (i == str.size() && !str.empty())
        return 1;
	else 
		return 0;
}

