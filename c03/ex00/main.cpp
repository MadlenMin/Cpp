#include "ClapTrap.hpp"
#include <iostream>

#include "ClapTrap.hpp"

int main()
{
    std::cout << "=== Creating ClapTraps ===" << std::endl;
    ClapTrap clappy("Clappy");
    ClapTrap trappy("Trappy");
    
    std::cout << "\n=== Testing Attack ===" << std::endl;
    clappy.attack("a monster");
    trappy.attack("a goblin");
    
    std::cout << "\n=== Testing Take Damage ===" << std::endl;
    clappy.takeDamage(3);
    clappy.takeDamage(5);
    trappy.takeDamage(8);
    
    std::cout << "\n=== Testing Repair ===" << std::endl;
    clappy.beRepaired(4);
    trappy.beRepaired(3);
    
    std::cout << "\n=== Testing No Energy ===" << std::endl;
    for (int i = 0; i < 11; i++) {
        clappy.attack("a dummy");
    }
    
    std::cout << "\n=== Testing Death ===" << std::endl;
    ClapTrap weak("Weak");
    weak.takeDamage(20);
    weak.attack("anything");
    weak.beRepaired(5);
    
    std::cout << "\n=== Testing Copy ===" << std::endl;
    ClapTrap clone(clappy);
    clone.attack("clone target");
    
    std::cout << "\n=== Done ===" << std::endl;
    return 0;
}
