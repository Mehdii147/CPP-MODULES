#include "Zombie.hpp"

int	main() {
	Zombie	*horde = zombieHorde(20, "simo");
	delete[] horde;
	return 0;
}