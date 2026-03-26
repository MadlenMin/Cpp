#include "PhoneBook.class.hpp"

Phonebook::Phonebook()
{
	count = 0;
	index = 0;
}

std::string getAnswer(const std::string message)
{
	std::string answer;
	std::cout << message;
	if (!std::getline(std::cin, answer))
    {
        std::cout << "\nExiting..." << std::endl;
        return "";
    }
	return answer;
}
void Phonebook::add_contact()
{
	Contact new_contact;
	std::string input;

	input = getAnswer("First Name: ");
	if (input.empty())
		return;
	while(!validateString(input))
	{
		std::cout << "Invalid input try again\n";
		input = getAnswer("First Name: ");
		if (input.empty())
			return;
	}
	new_contact.setFirstName(input);

	input = getAnswer("Last Name: ");
	if (input.empty())
		return;
	while(!validateString(input))
	{
		std::cout << "Invalid input try again\n";
		input = getAnswer("Last Name: ");
		if (input.empty())
			return;
	}
	new_contact.setLastName(input);

	input = getAnswer("Nick name: ");
	if (input.empty())
		return;
	while(!validateString(input))
	{
		std::cout << "Invalid input try again\n";
		input = getAnswer("Nick name: ");
		if (input.empty())
			return;
	}
	new_contact.setNicname(input);

	input = getAnswer("Phone Number: ");
	if (input.empty())
		return;
	while(!validatePhoneNbr(input))
	{
		std::cout << "Invalid input try again\n";
		input = getAnswer("Phone Number: ");
		if (input.empty())
			return;
	}
	new_contact.setPhoneNbr(input);
	
	input = getAnswer("Darkest Secret: ");
	if (input.empty())
		return;
	new_contact.setDarkestSecret(input);
	contacts[index] = new_contact;
	index = (index + 1) % 8;
	if (count < 8)
		count++;
}
std::string Phonebook::trim(const std::string &str) const
{
	if(str.length() > 10)
		return str.substr(0,9) + ".";
	return str;
}

void Phonebook::display_contact(int index)
{
	std::cout << std::setw(10) << index << "|";
	std::cout << std::setw(10) << trim(contacts[index].getFirstName()) << "|";
	std::cout << std::setw(10) << trim(contacts[index].getLastName()) << "|";
	std::cout << std::setw(10) << trim(contacts[index].getNicname()) << "|" << std::endl;
} 
void Phonebook::display_search()
{
	std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "\n";
	for(int i = 0; i < count ; i++)
		display_contact(i);
}

void Phonebook::search_contact()
{
	if(count == 0)
	{
		std::cout << "Phonebook is empty\n";
		return;
	}
	display_search();
	std::cout << "What contact do you want to find, enter the index: ";
	std::string number = getAnswer("");
	if (number.empty())
		return;
	if(number.length() != 1 || !my_isnum(number[0]))
	{
		std::cout << "Invalid index input" << std::endl;
		return;
	}
	int index = number[0] - '0';
	if(index >= count)
	{
		std::cout << "Index not in range, choose a number between 0-" << (count - 1) << "\n";
		return;
	}
	std::cout << "First name: " << contacts[index].getFirstName() << "\n";
    std::cout << "Last name: " << contacts[index].getLastName() << "\n";
    std::cout << "Nickname: " << contacts[index].getNicname() << "\n";
    std::cout << "Phone number: " << contacts[index].getPhoneNbr() << "\n";
    std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << "\n";
}
