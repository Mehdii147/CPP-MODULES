#include "ScavTrap.hpp"

int main()
{
    ScavTrap scavtrap("Scavtrap");
    ScavTrap scavtrap2(scavtrap);
    ScavTrap scavtrap3 = scavtrap;
    ScavTrap scavtrap4;
    scavtrap4 = scavtrap;
    scavtrap.attack("target");
    scavtrap.guardGate();
    scavtrap.takeDamage(5);
    scavtrap.beRepaired(5);
    return 0;
    
}