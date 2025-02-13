#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal Constructor" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Animal Constructor" << std::endl;
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
    std::cout << "Animal Destructor" << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "Animal Sound" << std::endl;
}