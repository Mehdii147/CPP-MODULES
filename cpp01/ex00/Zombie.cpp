#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << "zen "<< name  << " ta9" << std::endl ;
}

Zombie::~Zombie(void){
    std::cout << "he9 " << this->_name << " mcha" << std::endl;
}

void Zombie::annouce(void){
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ" << std::endl; 
}