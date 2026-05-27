#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie " << this->name << " created" << '\n';
}
void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ.." << '\n';
}
Zombie::~Zombie()
{
	std::cout << name << ": destroyed " << '\n';
}
