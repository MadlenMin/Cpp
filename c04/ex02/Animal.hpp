#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string type;
		
	public:
		// Orthodox Canonical Form
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();
		
		// Pure virtual function - makes Animal abstract
		virtual void makeSound() const = 0;
		
		// Getter (still works)
		std::string getType() const;
};

#endif