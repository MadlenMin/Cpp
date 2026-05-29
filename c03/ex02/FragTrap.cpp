#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " has been created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " has been destroyed!" << std::endl;
}


void FragTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "FragTrap " << this->name 
				  << " is dead and cannot attack!" << std::endl;
		return;
	}
	
	if (this->energyPoints == 0)
	{
		std::cout << "FragTrap " << this->name 
				  << " has no energy points and cannot attack!" << std::endl;
		return;
	}
	
	this->energyPoints--;
	std::cout << "FragTrap " << this->name << " attacks " << target 
			  << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}


void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name 
			  << " says: I am tiered" << std::endl;
}