#include "Zombie.hpp"

int	main() {
	Zombie	*zumbi = NULL;

	zumbi = zumbi->newZombie("lulu");
	zumbi = zumbi->newZombie("lulu2");
	zumbi = zumbi->newZombie("lulu3");
	zumbi = zumbi->newZombie("lulu4");
	zumbi->randomChump("mumu");
	zumbi->randomChump("mumu2");
	zumbi->randomChump("mumu3");
	zumbi->randomChump("mumu4");
	delete zumbi;
}