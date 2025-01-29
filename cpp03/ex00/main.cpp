#include "ClapTrap.hpp"

int main()
{
    ClapTrap claptrap("Claptrap");
    ClapTrap claptrap2(claptrap);
    ClapTrap claptrap3 = claptrap;
    ClapTrap claptrap4;
    claptrap4 = claptrap;
    claptrap.attack("target");
    claptrap.takeDamage(5);
    claptrap.beRepaired(5);
    return 0;
}