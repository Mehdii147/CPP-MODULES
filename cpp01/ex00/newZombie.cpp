#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name){  
    Zombie *zumbi = new Zombie(name);

    zumbi->annouce();
    return zumbi;  
}
