#include "Contact.class.hpp"

Contact::Contact()
{
	
}
void Contact::setFirstName(const std::string &value)
{
	first_name = value;
}
void Contact::setLastName(const std::string &value)
{
	last_name = value;
}
void Contact::setNicname(const std::string &value)
{
	nickname = value;
}
void Contact::setPhoneNbr(const std::string &value)
{
	phone_number = value;
}
void Contact::setDarkestSecret(const std::string &value)
{
	darkest_secret = value;
}

std::string Contact::getFirstName() const
{
	return (first_name);
}

std::string Contact::getLastName() const
{
	return (last_name);
}

std::string Contact::getNicname() const
{
	return (nickname);
}

std::string Contact::getPhoneNbr() const
{
	return(phone_number);
}

std::string Contact::getDarkestSecret() const
{
	return (darkest_secret);
}
