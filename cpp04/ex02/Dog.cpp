#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
    this->brain = new Brain();
    std::cout << "Dog Constructor" << std::endl;
}

Dog::Dog(const Dog &copy)
{
    this->brain = new Brain(*copy.brain);
    *this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
    {
        delete brain;
        brain = new Brain(*copy.brain);
        AAnimal::operator=(copy);
    }
    return *this;
}

std::string Dog::getType() const
{
    return this->type;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}

