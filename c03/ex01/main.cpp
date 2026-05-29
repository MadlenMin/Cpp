#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "===== TEST 1: Construction Order =====" << std::endl;
    ScavTrap scav("Scavvy");
    
    std::cout << "\n===== TEST 2: Different Attack Messages =====" << std::endl;
    
    ClapTrap clap("Clappy");
    
    std::cout << "\nClapTrap attack: ";
    clap.attack("target");
    
    std::cout << "ScavTrap attack: ";
    scav.attack("target");
    
    std::cout << "\n===== TEST 3: Inherited Functions =====" << std::endl;
    scav.takeDamage(30);
    scav.beRepaired(10);
    
    std::cout << "\n===== TEST 4: Special Feature =====" << std::endl;
    scav.guardGate();
    
    std::cout << "\n===== TEST 5: Destruction Order =====" << std::endl;
    
    return 0;
}