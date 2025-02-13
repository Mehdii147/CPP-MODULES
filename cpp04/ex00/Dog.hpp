#ifndef DOG_CPP
#define DOG_CPP

#include <iostream> 
#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog& copy);
    Dog& operator=(const Dog& copy);
    std::string getType() const;
    ~Dog();

    void makeSound() const;
};

#endif