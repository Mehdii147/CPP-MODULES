#include "Animal.hpp"
#include "Cat.hpp"

int main()
{
    // const Animal *meta = new Animal();
    // // const Animal *j = new Dog();
    // const Animal *i = new Cat();

    Cat *cat = new Cat();
    Animal *animal = new Animal();

    cat->makeSound();
    animal->makeSound();  

    delete cat;
    delete animal;
    // std::cout << i->getType() << " " << std::endl;
    // std::cout << j->getType() << " " << std::endl;

    // i->makeSound(); //will output the cat sound!
    // // j->makeSound();
    // meta->makeSound();

    // delete meta;
    // // delete j;
    // delete i;
    return 0;
}