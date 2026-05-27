#include "Zombie.hpp"

Zombie* newZombi (std::string name)
{
	Zombie* newZ = new Zombie(name);
	return newZ;
}