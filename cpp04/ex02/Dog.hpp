#ifndef DOG_CPP
#define DOG_CPP

#include <iostream> 
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(std::string type);
        Dog(const Dog& copy);
        Dog& operator=(const Dog& copy);
        ~Dog();

        std::string getType() const;
        void makeSound() const;
};

#endif