#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
}

Cat &Cat::operator=(const Cat &copy)
{
    this->type = copy.type;
    return *this;
}

// Cat::Cat(const Cat &copy)
// {
//     *this = copy;
// }


Cat::Cat(std::string type)
{
    this->type = type;
}

std::string Cat::getType() const
{
    return this->type;
}
Cat::~Cat()
{
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}