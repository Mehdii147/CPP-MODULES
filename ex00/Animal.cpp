#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
}

Animal::Animal(std::string type) : type(type)
{
}

Animal::Animal(const Animal &copy)
{
    *this = copy;
}

Animal &Animal::operator=(const Animal &copy)
{
    this->type = copy.type;
    return *this;
}

Animal::~Animal()
{
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "Animal Sound" << std::endl;
}