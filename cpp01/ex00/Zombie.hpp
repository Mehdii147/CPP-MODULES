#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string.h>
#include <iostream>

class Zombie{
    private:
        std::string _name;
    public: 
        Zombie(std::string name);
        ~Zombie(void);

        void annouce(void);
        Zombie* newZombie(std::string name);
        void randomChump(std::string name);

};

#endif