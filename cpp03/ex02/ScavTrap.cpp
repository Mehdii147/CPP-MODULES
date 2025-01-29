#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_name = "default";
    this->_hitpoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitpoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &copy)
    {
        ClapTrap::operator=(copy);
    }
    return *this;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->_energyPoints > 0)
    {
        std::cout << "ScavTrap " << this->_name << " attack " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    }
    else if (this->_energyPoints == 0)
    {
        std::cout << "ScavTrap " << this->_name << " is out of energy!" << std::endl;
        return;
    }
    else
        std::cout << "ScavTrap " << this->_name << " is dead!" << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->_name << " have enterred in Gate keeper mode" << std::endl;
}