#include "HumanB.hpp"

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;

}
HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

void HumanB::attack() const
{
	if(this->weapon == NULL)
	{
		std::cout << this->name << " has no weapon " << '\n';
		return;
	}
	std::cout << this->name << " attacks with their " << this->weapon->getType() << '\n';
}