#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
    const Animal* meta = new Animal();
    // const WrongAnimal* meta = new WrongAnimal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    // const WrongAnimal* i = new WrongCat();
    // std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    // j->makeSound();
    // meta->makeSound();
    delete meta;
    delete j;
    delete i;
    return 0;
}
