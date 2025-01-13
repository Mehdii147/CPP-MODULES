#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string.h>
#include <iostream>

class Zombie{
    private:
        std::string name;
    public: 
        Zombie();
        ~Zombie(void);

        void annouce(void);
        void	setName(std::string name);

};

Zombie	*zombieHorde(int n, std::string name);

#endif