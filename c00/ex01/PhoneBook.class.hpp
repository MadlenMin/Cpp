#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
# include "Contact.class.hpp"

class Phonebook
{
	private:
		Contact contacts[8];
		int count;
		int index;
	public:
		Phonebook();
		void add_contact();
		void search_contact();
		void display_search();
		void display_contact(int index);
		std::string trim(const std::string &str) const;
};
std::string getAnswer(const std::string massage);
#endif