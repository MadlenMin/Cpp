/*When you create a ScavTrap:

    First: ClapTrap constructor runs

    Then: ScavTrap constructor runs

When you destroy a ScavTrap:

    First: ScavTrap destructor runs

    Then: ClapTrap destructor runs

Why? The base class (ClapTrap) must be ready before the derived class (ScavTrap) can use it.
*/
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " has been created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " has been destroyed!" << std::endl;
}


void ScavTrap::attack(const std::string& target)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ScavTrap " << this->name 
                  << " is dead and cannot attack!" << std::endl;
        return;
    }
    
    if (this->energyPoints == 0)
    {
        std::cout << "ScavTrap " << this->name 
                  << " has no energy points and cannot attack!" << std::endl;
        return;
    }
    
    this->energyPoints--;
    std::cout << "ScavTrap " << this->name << " attacks " << target 
              << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}


void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name 
              << " is now in Gate keeper mode!" << std::endl;
}