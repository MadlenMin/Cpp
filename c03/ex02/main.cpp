#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "===== TEST 1: Construction Order =====" << std::endl;
	std::cout << "Creating FragTrap:" << std::endl;
	FragTrap frag("Fraggy");
	
	std::cout << "\n===== TEST 2: Different Attack Messages =====" << std::endl;
	
	// Create ClapTrap for comparison
	ClapTrap clap("Clappy");
	
	std::cout << "\nClapTrap attack: ";
	clap.attack("target");
	
	std::cout << "FragTrap attack: ";
	frag.attack("target");
	
	std::cout << "\n===== TEST 3: Inherited Functions =====" << std::endl;
	frag.takeDamage(40);
	frag.beRepaired(20);
	
	std::cout << "\n===== TEST 4: Special Feature =====" << std::endl;
	frag.highFivesGuys();
	
	std::cout << "\n===== TEST 5: Stats Verification =====" << std::endl;
	std::cout << "FragTrap " << frag.getName() << " - HP: " << frag.getHitPoints()
			  << ", EP: " << frag.getEnergyPoints() 
			  << ", DMG: " << frag.getAttackDamage() << std::endl;
	
	std::cout << "\n===== TEST 6: Destruction Order =====" << std::endl;
	
	return 0;
}