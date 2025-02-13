#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Constructor" << std::endl;
}


Cat &Cat::operator=(const Cat &copy)
{
    this->type = copy.type;
    return *this;
}

Cat::Cat(const Cat &copy)
{
    *this = copy;
}

std::string Cat::getType() const
{
    return this->type;
}
Cat::~Cat()
{
    std::cout << "Cat Destructor" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}