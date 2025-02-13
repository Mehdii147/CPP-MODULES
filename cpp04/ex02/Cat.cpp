#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
    this->brain = new Brain();
    std::cout << "Cat Constructor" << std::endl;
}


Cat &Cat::operator=(const Cat &copy) 
{
    if(this != &copy)
    {
        delete brain;
        brain = new Brain(*copy.brain);
        this->type = copy.type;
    }
    return *this;
}

Cat::Cat(const Cat &copy) 
{
    this->brain = new Brain(*copy.brain);
    *this = copy;
}

std::string Cat::getType() const
{
    return this->type;
}
Cat::~Cat()
{
    delete brain;
    std::cout << "Cat Destructor" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}