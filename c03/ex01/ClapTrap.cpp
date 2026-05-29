#include "ClapTrap.hpp"

// ============================================================
// CONSTRUCTORS & DESTRUCTOR
// ============================================================

ClapTrap::ClapTrap()
    : name(""), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << this->name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name), 
      hitPoints(other.hitPoints), 
      energyPoints(other.energyPoints), 
      attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " has been destroyed!" << std::endl;
}

// ============================================================
// ACTIONS
// ============================================================

void ClapTrap::attack(const std::string& target)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name 
                  << " is dead and cannot attack!" << std::endl;
        return;
    }
    
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name 
                  << " has no energy points and cannot attack!" << std::endl;
        return;
    }
    
    this->energyPoints--;
    std::cout << "ClapTrap " << this->name << " attacks " << target 
              << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= this->hitPoints)
    {
        this->hitPoints = 0;
        std::cout << "ClapTrap " << this->name << " takes " << amount 
                  << " damage and is destroyed!" << std::endl;
    }
    else
    {
        this->hitPoints -= amount;
        std::cout << "ClapTrap " << this->name << " takes " << amount 
                  << " damage! HP left: " << this->hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->name 
                  << " is dead and cannot repair!" << std::endl;
        return;
    }
    
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->name 
                  << " has no energy points and cannot repair!" << std::endl;
        return;
    }
    
    this->energyPoints--;
    this->hitPoints += amount;
    
    std::cout << "ClapTrap " << this->name << " repairs itself for " << amount 
              << " hit points! HP: " << this->hitPoints << std::endl;
}

// ============================================================
// GETTERS
// ============================================================

std::string ClapTrap::getName() const
{
    return this->name;
}

unsigned int ClapTrap::getHitPoints() const
{
    return this->hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return this->energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return this->attackDamage;
}