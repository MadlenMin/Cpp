#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	private:
		std::string name;           // ClapTrap's name
		unsigned int hitPoints;     // Health (0 = dead)
		unsigned int energyPoints;  // Can act if > 0
		unsigned int attackDamage;  // Damage dealt per attack
		
	public:
		// Orthodox Canonical Form
		ClapTrap();                                // Default constructor
		ClapTrap(const std::string& name);         // Parameterized constructor
		ClapTrap(const ClapTrap& other);           // Copy constructor
		ClapTrap& operator=(const ClapTrap& other); // Copy assignment
		~ClapTrap();
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		std::string getName() const;
		unsigned int getHitPoints() const;
		unsigned int getEnergyPoints() const;
		unsigned int getAttackDamage() const;
};

#endif