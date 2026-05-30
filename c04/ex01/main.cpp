#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "========== PART 1: Creating Animals with Brains ==========" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;  // Should not leak
	delete i;
	
	std::cout << "\n========== PART 2: Array of Animals ==========" << std::endl;
	Animal* animals[6];
	
	for (int idx = 0; idx < 3; idx++)
		animals[idx] = new Dog();
	for (int idx = 3; idx < 6; idx++)
		animals[idx] = new Cat();
	
	for (int idx = 0; idx < 6; idx++)
		delete animals[idx];
	
	std::cout << "\n========== PART 3: Deep Copy Test ==========" << std::endl;
	Dog original;
	original.setIdea(0, "I love bones");
	original.setIdea(1, "Chase the mailman");
	
	std::cout << "\n--- Copying Dog ---" << std::endl;
	Dog copy(original);  // Deep copy
	
	std::cout << "\nOriginal ideas: " << original.getIdea(0) << ", " << original.getIdea(1) << std::endl;
	std::cout << "Copy ideas: " << copy.getIdea(0) << ", " << copy.getIdea(1) << std::endl;
	
	std::cout << "\n--- Modifying copy's brain ---" << std::endl;
	copy.setIdea(0, "Sleep all day");
	copy.setIdea(1, "Eat treats");
	
	std::cout << "Original ideas (should be unchanged): " << original.getIdea(0) << ", " << original.getIdea(1) << std::endl;
	std::cout << "Copy ideas (changed): " << copy.getIdea(0) << ", " << copy.getIdea(1) << std::endl;
	
	std::cout << "\n========== PART 4: Assignment Operator Test ==========" << std::endl;
	Dog assignTarget;
	assignTarget.setIdea(0, "Default idea");
	
	std::cout << "\n--- Assigning ---" << std::endl;
	assignTarget = original;
	
	std::cout << "After assignment: " << assignTarget.getIdea(0) << ", " << assignTarget.getIdea(1) << std::endl;
	
	std::cout << "\n========== PART 5: Cat Deep Copy Test ==========" << std::endl;
	Cat catOriginal;
	catOriginal.setIdea(0, "Hate dogs");
	catOriginal.setIdea(1, "Love naps");
	
	Cat catCopy(catOriginal);
	
	std::cout << "Original cat ideas: " << catOriginal.getIdea(0) << ", " << catOriginal.getIdea(1) << std::endl;
	std::cout << "Copy cat ideas: " << catCopy.getIdea(0) << ", " << catCopy.getIdea(1) << std::endl;
	
	catCopy.setIdea(0, "Love everyone");
	
	std::cout << "After modifying copy: " << std::endl;
	std::cout << "Original: " << catOriginal.getIdea(0) << std::endl;
	std::cout << "Copy: " << catCopy.getIdea(0) << std::endl;
	
	std::cout << "\n========== PART 6: Brain Destruction Order ==========" << std::endl;
	{
		Dog localDog;
		Cat localCat;
	}  // Brains should be destroyed here
	
	return 0;
}