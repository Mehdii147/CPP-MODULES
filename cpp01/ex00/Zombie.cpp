#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << "zen "<< name  << " ta9" << std::endl ;
}

Zombie::~Zombie(void){
    std::cout << "he9 " << name << " mcha" << std::endl;
}

void Zombie::annouce(void){
    std::cout << this->name << ": BraiiiiiiinnnzzzZ" << std::endl; 
}