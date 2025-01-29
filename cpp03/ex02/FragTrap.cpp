#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
    this->_name = "default";
    this->_hitpoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
    this->_hitpoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy){
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy){
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &copy){
        ClapTrap::operator=(copy);
    }
    return *this;
}

void FragTrap::attack(const std::string &target){
    std::cout << "FragTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void){
    std::cout << "positive high fives request!" << std::endl;
}
