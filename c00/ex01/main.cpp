#include "PhoneBook.class.hpp"
#include <iostream>
#include <string>

int main()
{
	std::string input;
	Phonebook phonebook;
	while(true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT) :";
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nExiting..." << std::endl;
			break;
		}
		if(input == "ADD")
		{
			phonebook.add_contact();
			std::cout << "Contact added to phonebook."  << std::endl;
		}
		else if(input == "SEARCH")
		{
			phonebook.search_contact();
			std::cout << std::endl;
		}
		else if (input == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Unknown command, please choose from (ADD, SEARCH, EXIT)\n";
		}
	}
	return 0;
}