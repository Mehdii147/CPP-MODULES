#include <iostream>

int main(int ac, char **av)
{
    size_t i = 1;
    size_t j = 0;
    std::string str;

    if (ac < 2)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    while (av && ac > 1 && av[i])
    {
        str = av[i];
        j = 0;
        while (j < str.length())
        {
            std::cout << (char)std::toupper(str[j]);
            j++;
        }
        i++;
    }
    std::cout << std::endl;
    return 0;
}