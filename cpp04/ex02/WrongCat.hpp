
#ifndef WRONGWrongCat_HPP
#define WRONGWrongCat_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

    public:
        WrongCat();
        WrongCat(std::string type);
        WrongCat(const WrongCat &copy);
        WrongCat &operator=(const WrongCat &copy);
         ~WrongCat();
        std::string getType() const;

        void makeSound() const;
};

#endif