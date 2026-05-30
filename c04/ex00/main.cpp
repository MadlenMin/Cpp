#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "========== PART 1: Correct Polymorphism ==========" << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << "\n--- Types ---" << std::endl;
	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;
	
	std::cout << "\n--- Sounds ---" << std::endl;
	std::cout << "Dog sound: ";
	dog->makeSound();
	std::cout << "Cat sound: ";
	cat->makeSound();
	std::cout << "Animal sound: ";
	meta->makeSound();
	
	std::cout << "\n--- Cleanup ---" << std::endl;
	delete meta;
	delete dog;
	delete cat;
	
	std::cout << "\n========== PART 2: Wrong Polymorphism (No Virtual) ==========" << std::endl;
	
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	
	std::cout << "\n--- Types ---" << std::endl;
	std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
	
	std::cout << "\n--- Sounds (WRONG - shows why virtual is needed) ---" << std::endl;
	std::cout << "WrongCat sound (via WrongAnimal*): ";
	wrongCat->makeSound();  // This calls WrongAnimal::makeSound()! Not WrongCat!
	std::cout << "WrongAnimal sound: ";
	wrongMeta->makeSound();
	
	std::cout << "\n--- Direct WrongCat call ---" << std::endl;
	WrongCat* realWrongCat = new WrongCat();
	std::cout << "WrongCat sound (direct): ";
	realWrongCat->makeSound();  // This calls WrongCat::makeSound()
	
	std::cout << "\n--- Cleanup ---" << std::endl;
	delete wrongMeta;
	delete wrongCat;
	delete realWrongCat;
	
	std::cout << "\n========== PART 3: Construction/Destruction Order ==========" << std::endl;
	std::cout << "Creating Dog:" << std::endl;
	Dog puppy;
	
	std::cout << "\nCreating Cat:" << std::endl;
	Cat kitten;
	
	return 0;
}