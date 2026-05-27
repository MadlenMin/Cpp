#include "Zombie.hpp"

int main()
{
	Zombie* zombi1 = newZombi("Gago");
	zombi1->announce();
	delete zombi1;
	randomChump("Davit");
	return 0;
}