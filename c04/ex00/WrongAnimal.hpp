#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
		
	public:
		// Orthodox Canonical Form
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		~WrongAnimal();
		
		// NOT virtual! (This is the point)
		void makeSound() const;
		std::string getType() const;
};

#endif