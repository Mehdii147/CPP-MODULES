#ifndef     CLAPTRAP_HPP
# define    CLAPTRAP_HPP

# include <iostream>
# include <string>


class ClapTrap
{
    private:
        std::string _name;
        int _hitpoints;
        int _energyPoints;
        int _attackDamage;
        
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const &other);
        ~ClapTrap();

        ClapTrap &operator=(ClapTrap const &other);
        void attack(std::string const &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

};



#endif