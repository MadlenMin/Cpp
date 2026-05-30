#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "========== TEST 1: Cannot Instantiate Animal ==========" << std::endl;
	std::cout << "Animal is abstract - cannot instantiate (compiler would error)" << std::endl;
	
	std::cout << "\n========== TEST 2: Creating Dogs and Cats ==========" << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << "\n--- Types ---" << std::endl;
	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;
	
	std::cout << "\n--- Sounds (polymorphism still works) ---" << std::endl;
	dog->makeSound();
	cat->makeSound();
	
	std::cout << "\n--- Cleanup ---" << std::endl;
	delete dog;
	delete cat;
	
	std::cout << "\n========== TEST 3: Array of Animals ==========" << std::endl;
	Animal* animals[4];
	
	for (int i = 0; i < 2; i++)
		animals[i] = new Dog();
	for (int i = 2; i < 4; i++)
		animals[i] = new Cat();
	
	for (int i = 0; i < 4; i++)
		delete animals[i];
	
	std::cout << "\n========== TEST 4: Deep Copy Still Works ==========" << std::endl;
	Dog original;
	original.setIdea(0, "My unique thought");
	
	Dog copy(original);
	std::cout << "Original idea: " << original.getIdea(0) << std::endl;
	std::cout << "Copy idea: " << copy.getIdea(0) << std::endl;
	
	copy.setIdea(0, "Copy's own thought");
	std::cout << "After modifying copy:" << std::endl;
	std::cout << "Original: " << original.getIdea(0) << std::endl;
	std::cout << "Copy: " << copy.getIdea(0) << std::endl;
	
	return 0;
}