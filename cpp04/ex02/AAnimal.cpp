#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "AAnimal Constructor" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
    std::cout << "AAnimal Constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
    *this = copy;

}

AAnimal &AAnimal::operator=(const AAnimal &copy)
{
    this->type = copy.type;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal Destructor" << std::endl;
}

std::string AAnimal::getType() const
{
    return this->type;
}

void AAnimal::makeSound() const
{
    std::cout << "AAnimal Sound" << std::endl;
}