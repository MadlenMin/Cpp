#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
	private:
		std::string darkest_secret;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;	
	public:
		Contact();
		void setFirstName(const std::string &value);
		void setLastName(const std::string &value);
		void setNicname(const std::string &value);
		void setPhoneNbr(const std::string &value);
		void setDarkestSecret(const std::string &value);
	public:
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNicname() const;
		std::string getPhoneNbr() const;
		std::string getDarkestSecret() const;
};

bool validateString(const std::string &value);
bool my_isalpha(char c);
bool my_isnum(char c);
bool validatePhoneNbr(const std::string &value);