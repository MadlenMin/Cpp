#include "Contact.class.hpp"

bool my_isalpha(char c)
{
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;
	else
		return false;
}

bool my_isnum(char c)
{
	if((c >= '0' && c <= '9'))
		return true;
	else
		return false;
}
bool validateString(const std::string &value)
{
	int i;
	i = 0;
	while(value[i])
	{
		if(!my_isalpha(value[i]))
		{
			return false;
		}
		i++;
	}
	return true;
}
bool validatePhoneNbr(const std::string &value)
{
	int i;
	i = 0;
	if(value[i] == '+')
		i++;
	while(value[i])
	{
		if(!my_isnum(value[i]))
		{
			return false;
		}
		i++;
	}
	return true;
}
