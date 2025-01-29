#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _hitpoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "defualt ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy){
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy){
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &copy)
	{
		this->_name = copy._name;
		this->_hitpoints = copy._hitpoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}

void ClapTrap::attack(std::string const &target){
    if (this->_energyPoints > 0){
        std::cout << "ClapTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints-- ;
    }
    else if(this->_energyPoints == 0){
        std::cout << "ClapTrap " << this->_name << " is out of energy!" << std::endl;
        return;
    }
    else
        std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->_hitpoints > 0){
        std::cout << "ClapTrap " << this->_name << " take " << amount << " points of damage!" << std::endl;
        this->_hitpoints -= amount;
    }
    else
        std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->_hitpoints > 0){
        std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points!" << std::endl;
        this->_hitpoints += amount;
    }
    else
        std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
}

ClapTrap::~ClapTrap(){
     std::cout <<"ClapTrap Destructor called" << std::endl;
}