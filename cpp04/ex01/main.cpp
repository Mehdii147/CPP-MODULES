#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
 const Animal *j = new Dog();
    const Animal *i = new Cat();
    delete j;
    delete i;

    const int arraySize = 4;
    Animal *Animals[arraySize];
    for (int k = 0; k < arraySize / 2; ++k) {
        Animals[k] = new Dog();
    }
    for (int k = arraySize / 2; k < arraySize; ++k) {
        Animals[k] = new Cat();
    }

    for (int k = 0; k < arraySize; ++k) {
        Animals[k]->makeSound();
    }

    for (int k = 0; k < arraySize; ++k) {
        delete Animals[k];
    }
    return 0;
}