#include <iostream>
#include <string>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "string's adress: " << &string << std::endl;
    std::cout << "string's PTR   : " << stringPTR << std::endl;
    std::cout << "string's REF   : " << &stringREF << std::endl;


    std::cout << "string's      value: " << string << std::endl;
    std::cout << "string's PTR  value: " << *stringPTR << std::endl;
    std::cout << "string's REF  value: " << stringREF << std::endl;
}