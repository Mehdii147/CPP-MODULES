#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "zen ta9" << std::endl ;
}

Zombie::~Zombie(void){
    std::cout << "he9 mcha" << std::endl;
}

void Zombie::annouce(void){
    std::cout << this->name << ": BraiiiiiiinnnzzzZ" << std::endl; 
}

void	Zombie::setName(std::string name){
	this->name = name;
}